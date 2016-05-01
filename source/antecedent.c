#include "../include/antecedent.h"

/**
 * @brief Initialisation d'une liste d'antécédents
 * @returns une liste d'antécédents
 **/
Antecedent nouv_ant()
{
	return (Antecedent) NULL;
}

/**
 * @brief Désallocation d'une liste d'antécédents
 * @param a : la liste d'antécédents à désallouer
 * @returns vrai
 **/
Bool del_ant(Antecedent a)
{
	if( a == NULL )
		return vrai;
		
	Antecedent t = a->suivant;
	
	free(a);
	
	return del_ant(t);
}

/**
 * @brief Vérification de l'existence d'un élément dans une liste d'antécédents
 * @param a : la liste d'antécédents dans laquelle l'élément doit être recherché  
 * @param v : l'élément recherché
 * @returns vrai : si l'élément existe dans la liste d'antécédents
 * @returns faux : sinon
 **/
Bool elem_ant(Antecedent a, E v)
{
	if( a == NULL )
		return faux;
	
	if( a->val == v )
		return vrai;
		
	return elem_ant(a->suivant, v);
}

/**
 * @brief Ajout d'un élément à une liste d'antécédents
 * @param a : la liste d'antécédents dans laquelle l'élément doit être ajouté 
 * @param v : l'élément à ajouter
 * @returns la liste d'antécédents avec le nouvel élément ajouté
 **/
Antecedent adj_ant(Antecedent a, E v)
{
	if( elem_ant(a, v) == vrai )
		return a;
		
	Antecedent n = (Antecedent) malloc( sizeof( struct s_ant ) );
	
	n->val = v;
	
	n->suivant = a;
	
	return n;
}

/**
 * @brief Fonction auxiliaire de fusion de deux listes d'antécédents (sans doublons)
 * @param d : la liste d'antécédents de destination 
 * @param s : la liste d'antécédents de source
 * @returns la liste d'antécédents de destination 
 **/
Antecedent ajout(Antecedent d, Antecedent s)
{
	if( s == NULL )
		return d;
		
	d = adj_ant(d, s->val);
	
	return ajout(d, s->suivant);
}

/**
 * @brief Affichage d'une liste d'antécédents
 * @param a : la liste d'antécédents à afficher 
 * @returns void 
 **/
void affiche_ant(Antecedent a)
{
	if( a == NULL )
	{
		printf(" Pas d'antécédents \n");
		return;
	}
	
	if( a->suivant == NULL )
	{
		printf(" %d \n", a->val);
		return;
	}
	else
	{
		printf(" %d,", a->val);
	}
		
	affiche_ant(a->suivant);
}
