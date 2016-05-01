#include "../include/ensemble.h"

/**
 * @brief Initialisation d'un nouvel ensemble
 * @param capacite : la capacité de départ du nouvel ensemble 
 * @returns un nouvel ensemble
 * En cas d'erreur de l'allocation de l'espace mémoire pour le nouvel ensemble
 * la fonction renvoie un ensemble vide.
 **/
Ensemble nouvel(Nat capacite)
{
	Ensemble n;
	
	if( capacite > 0 )
		n.valeurs = (E *) malloc(capacite * sizeof(E));
	else
		n.valeurs = NULL;
		
	n.taille = 0;
	
	if( n.valeurs == NULL ) //En cas d'erreur de l'allocation
		n.limite = 0;
	else
		n.limite = capacite;
	
	return n;
}

/**
 * @brief Désallocation de l'espace mémoire occupé par les éléments d'un ensemble
 * @param e : l'ensemble à désallouer 
 * @returns vrai 
 **/	
Bool del(Ensemble e)
{
	e.taille = 0;
	e.limite = 0;
	
	if( e.valeurs == NULL )
		return vrai;
	
	free(e.valeurs);
	
	return vrai;
}

/**
 * @brief Fonction auxiliaire de recherche de la position d'un élément dans un ensemble
 * @param e : l'ensemble dans lequel la position d'un élément doit être recherchée
 * @param x : l'élément dont la position doit être recherchée
 * @returns la position de l'élément dans l'ensemble : si l'élément existe dans cet ensemble
 * @returns -1 : sinon
 **/
posit_n position(Ensemble e, E x)
{
	if( e.taille < 1 )
		return -1;
		
	if( ( x < e.valeurs[0] ) || ( x > e.valeurs[e.taille - 1] ) )
		return -1;
		
	if( ( x <= e.valeurs[e.taille - 1] ) && ( e.taille >= 1 ) )
	{
		if( e.valeurs[e.taille - 1] == x )
		{
			return ( e.taille - 1 );
		}
		else
		{
			e.taille--;
			return position(e, x);
		}
	}

	return -1;
}

/**
 * @brief Vérification de l'existence d'un élément dans un ensemble
 * @param e : l'ensemble dans lequel l'élément doit être recherché
 * @param x : l'élément recherché
 * @returns vrai : si l'élément x se trouve dans l'ensemble e
 * @returns faux : sinon 
 **/
Bool elem(Ensemble e, E x)
{
	if( position(e ,x) == -1 )
		return faux;
		
	return vrai;
}

/**
 * @brief Cardinal d'un ensemble
 * @param e : l'ensemble dont le cardinal doit être renvoyé
 * @returns le cardinal de l'ensemble e : si l'ensemble n'est pas vide
 * @returns 0 : sinon 
 **/		
Nat card(Ensemble e)
{
	return e.taille;
}

/**
 * @brief Fonction auxiliaire de duplication d'un ensemble
 * @param s : l'ensemble de départ 
 * @param d : l'ensemble de destination
 * @returns l'ensemble de destination 
 **/
Ensemble dup(Ensemble s, Ensemble d)
{
	if( s.taille >= 1 )
	{
		d.valeurs[s.taille - 1] = s.valeurs[s.taille - 1];
		s.taille--;
		d.taille++;
		return dup(s,d);
	}
	
	return d;
}

/**
 * @brief Fonction auxiliaire d'insertion d'un espace libre à une position précise dans un ensemble
 * @param e : l'ensemble dans lequel un espace libre doit être inséré
 * @param p : la position à laquelle l'espace libre doit être inséré
 * @param __ext : le nombre d'éléments de l'ensemble e après l'insertion d'un espace libre
 * @returns l'ensemble e comportant un espace libre à la position p 
 **/
Ensemble inser(Ensemble e, Nat p, Nat __ext)
{
	if( ( __ext - 1 ) > p )
	{
		e.valeurs[__ext - 1] = e.valeurs[__ext - 2];
		
		return inser(e, p, __ext - 1);
	}
	
	return e;
}

/**
 * @brief Fonction auxiliaire de recherche de la position à laquelle un nouvel élément va être inséré dans un ensemble
 * @param e : l'ensemble dans lequel la recherche de position convenable doit être effectuée
 * @param x : l'élément à insérer
 * @returns la position dans l'ensemble e à laquelle l'élément x va être inséré 
 **/
Nat place(Ensemble e, E x)
{
	if( e.taille < 1 )
		return 0;
	
	if( x < e.valeurs[0] )
		return 0;

	if( x > e.valeurs[e.taille - 1] )
	{
		return e.taille;
	}
	
	e.taille--;
	return place(e, x);
}	

/**
 * @brief Adjonction d'un nouvel élément à un ensemble
 * @param e : l'ensemble de destination 
 * @param x : l'élément à ajouter
 * @returns l'ensemble avec le nouvel élément ajouté
 * S'il n'y a plus d'espace disponible dans l'ensemble pour ajouter le nouvel 
 * élément la limite est incrémentée d'un élément et de l'espace supplémentaire 
 * est alloué pour l'ensemble.
 * Si l'élément se trouve déjà dans l'ensemble en question ce dernier n'est pas 
 * modifié.   
 **/
Ensemble adj(Ensemble e, E x)
{
	if( e.valeurs == NULL )
	{
		e.valeurs = (E*) malloc( sizeof(E) );
		e.valeurs[0] = x;
		e.taille++;
		
		return e;
	}
		
	if( elem(e, x) == vrai )
		return e;
	
	Nat p = place(e, x);
	
	if( e.taille < e.limite )
	{
		e = inser(e, p, ++e.taille);
		e.valeurs[p] = x;
		
		return e;
	}
		
	e.valeurs = (E*) realloc(e.valeurs, ( e.taille + 1 ) * sizeof(E));
	e = inser(e, p, ++e.taille);
	e.valeurs[p] = x;
	
	return e;
}


/**
 * @brief Fonction auxiliaire de décalage des éléments d'un ensemble après la suppression d'un élément
 * @param e : l'ensemble dont les éléments doivent être décalés
 * @param p : la position dans l'ensemble à partir de laquelle le décalage doit être effectué
 * @returns l'ensemble avec les éléments décalés 
 **/
Ensemble decal(Ensemble e, Nat p)
{
	if( p < ( e.taille - 1) )
	{
		e.valeurs[p] = e.valeurs[p + 1];
		
		return decal(e, p + 1);
	}
	
	return e;
}

/**
 * @brief Suppression d'un éléments d'un ensemble
 * @param *e : l'adresse de l'ensemble duquel l'élément doit être supprimé 
 * @param x : l'élément à supprimer
 * @returns l'ensemble sans l'élément x 
 **/
Ensemble supp(Ensemble * e, E x)
{
	posit_n p;
	
	if( ( p = position(*e, x) ) == -1 )
		return *e;
		
	*e = decal(*e, p);
			
	e->taille--;
	
	return *e;
}

/**
 * @brief Calcul du minimum d'un ensemble
 * @param e : l'ensemble dont le minimum doit être renvoyé 
 * @returns le minimum de l'ensemble e
 * L'ensemble e doit contenir au moins un élément.
 **/
E min(Ensemble e)
{
	return e.valeurs[0];
}

/**
 * @brief Calcul du maximum d'un ensemble
 * @param e : l'ensemble dont le maximum doit être renvoyé 
 * @returns le maximum de l'ensemble e
 * L'ensemble e doit contenir au moins un élément.
 **/
E max(Ensemble e)
{
	return e.valeurs[e.taille - 1];
}

/**
 * @brief Affichage des éléments d'un ensemble
 * @param e : l'ensemble dont les éléments doivent être affichés 
 * @returns void
 **/
void affiche(Ensemble e)
{
	if( e.taille < 1 )
	{
		printf(" { Ø } \n");
		return;
	}
		
	if( e.taille == 1 )
	{
		printf(" { %d }\n", e.valeurs[e.taille - 1]);
		return;
	}
	
	printf(" { %d }", e.valeurs[e.taille - 1]);
	e.taille--;
	
	affiche(e);
}

/**
 * @brief Union de deux ensembles
 * @param e1 : un ensemble
 * @param e2 : un ensemble
 * @returns l'ensemble correspondant à l'union des ensembles e1 et e2
 **/
Ensemble u(Ensemble e1, Ensemble e2)
{
	if( ( e1.taille < 1 ) && ( e2.taille < 1 ) )
		return nouvel(0);
		
	if( e1.taille < 1 )
		return u(e2, e1);
	
	if( e2.taille < 1 )
	{
		return dup(e1, nouvel(e1.taille));
	}
		
	if( elem(e2, e1.valeurs[e1.taille - 1]) == vrai )
	{	
		return adj(u(e1,e2), e1.valeurs[--e1.taille]);
	}
	
	return adj(adj(u(e1,e2), e1.valeurs[--e1.taille]), e2.valeurs[--e2.taille]);
}

/**
 * @brief Intersection de deux ensembles
 * @param e1 : un ensemble
 * @param e2 : un ensemble
 * @returns l'ensemble correspondant à l'intersection des ensembles e1 et e2
 **/
Ensemble inter(Ensemble e1, Ensemble e2)
{
	if( ( e1.taille < 1 ) && ( e2.taille < 1 ) )
		return nouvel(0);
		
	if( e1.taille < 1 )
		return nouvel(0);
	
	if( e2.taille < 1 )
		return nouvel(0);
		
	if( e1.valeurs[e1.taille - 1] == e2.valeurs[e2.taille - 1] )
	{	
		e1.taille--;
		e2.taille--;
		
		return adj(inter(e1, e2), e1.valeurs[e1.taille]);
	}
	
	if( e2.valeurs[e2.taille - 1] > e1.valeurs[e1.taille - 1] )
		return inter(e2, e1);
	
	e1.taille--;
	
	return inter(e1, e2);
}
