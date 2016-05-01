/**
 * @file application.c
 * @author Marek Felšöci
**/

#include "../include/application.h"

/**
 * @brief Initialisation d'une application
 * @param source : ensemble de départ
 * @param but : ensemble d'arrivée
 * @returns une application
 **/
Application nouvelle(Ensemble source, Ensemble but)
{
	Application n;
	
	n.depart = source;
	n.arrivee = but;
	n.relation = NULL;
	
	return n;
}

/**
 * @brief Désallocation d'une liste chaînée de relations 
 * @param r : relation à désallouer
 * @returns vrai
 **/
Bool del_rel(Relation r)
{
	if( r == NULL )
		return vrai;
		
	Relation t = r->suivant;
	
	del_ant(r->antecedents);
	
	free(r);
	
	return del_rel(t);
}

/**
 * @brief Réinitialisation d'une application
 * @param a : application à réinitialiser
 * @returns une application
 * Cette fonction supprime toutes les relations entre les deux ensembles d'une
 * application. 
 **/
Application reinit(Application a)
{
	del_rel(a.relation);
	
	return a;
}

/**
 * @brief Recherche d'une image dans les relations d'une application
 * @param r : la relation où la fonction va rechercher l'image y
 * @param y : l'image recherchée
 * @returns la relation contenant l'image recherchée
 * @returns NULL si l'image ne se trouve dans aucune relation
 **/
Relation t_im(Relation r, E y)
{
	if( r == NULL )
		return NULL;
	
	if( r->image == y )
		return r;
		
	return t_im(r->suivant, y);
}

/**
 * @brief Recherche d'un antécédent dans les relations d'une application
 * @param r : la relation où la fonction va rechercher l'antécédent x
 * @param x : l'antécédent recherché
 * @returns la relation contenant l'antécédent recherché
 * @returns NULL si l'antécédent ne se trouve dans aucune relation
 **/
Relation t_ant(Relation r, E x)
{
	if( r == NULL )
		return NULL;
		
	if( r->antecedents == NULL )
		return t_ant(r->suivant, x);
		
	if( elem_ant(r->antecedents, x) == vrai )
		return r;
	
	return t_ant(r->suivant, x);
}

/**
 * @brief Définit une relation antécédent / image
 * @param a : l'application à laquelle la relation doit être ajoutée 
 * @param x : un élément appartenant à l'ensemble de départ
 * @param y : un élément appartenant à l'ensemble d'arrivée
 * @returns l'application modifiée
 **/	
Application fonction(Application a, E x, E y)
{
	if( elem(a.depart, x) == faux )
		return a;
		
	if( elem(a.arrivee, y) == faux )
		return a;
		
	if( t_ant(a.relation, x) != NULL )
		return a;
	
	Relation t = NULL;
	
	if( ( t = t_im(a.relation, y) ) != NULL )
	{		
		t->antecedents = adj_ant(t->antecedents, x);
		
		return a;
	}
		
	Relation n = (Relation) malloc( sizeof( struct s_rel ) );

	n->image = y;
	n->antecedents = nouv_ant();
	n->antecedents = adj_ant(n->antecedents, x);
	n->suivant = a.relation;
	
	a.relation = n;
		
	return a;
}

/**
 * @brief Renvoie l'image d'un élément x
 * @param a : l'application dans laquelle l'élément doit être recherché 
 * @param x : l'élément dont l'image on cherche à renvoyer
 * @returns l'image de x
 * 
 * Précondition : L'élément x doit avoir une image
 **/
E im(Application a, E x)
{
	Relation t = t_ant(a.relation, x);
	
	if( t != NULL )
		return t->image;
}

/**
 * @brief Renvoie la liste des antécédents d'une image y
 * @param a : l'application dans laquelle l'image doit être recherché  
 * @param y : un élément appartenant à l'ensemble d'arrivée
 * @returns l'application modifiée
 **/
Antecedent ant(Application a, E y)
{
	Relation t = t_im(a.relation, y);
	
	if( t != NULL )
		return t->antecedents;
		
	return NULL;
}

/**
 * @brief Renvoie la liste des antécédents des éléments de l'ensemble intermédiaire d'une composition d'applications
 * @param intermediaire : l'ensemble commun aux applications d'une composition 
 * @param r1 : la liste des relations de l'application de départ
 * @returns une liste chaînée de tous les antécédents de tous les éléments de l'ensemble intermédiaire
 **/
Antecedent origines(Antecedent intermediaire, Relation r1)
{
	if( intermediaire == NULL )
		return NULL;
		
	Relation t = t_im(r1, intermediaire->val); 
	
	if( t == NULL )
		return origines(intermediaire->suivant, r1);
		
	return ajout(origines(intermediaire->suivant, r1), t->antecedents );
}

/**
 * @brief Crée la liste de relations pour l'application correspondante à la composition de deux autres applications
 * @param r : la liste de relations de destination  
 * @param r1 : la liste de relation de l'application de départ
 * @param r2 : la liste de relation de l'application d'arrivée
 * @returns une liste de relations
 **/
Relation transfert(Relation r, Relation r1, Relation r2)
{
	if( r1 == NULL )
		return r;
		
	if( r2 == NULL )
		return r;
		
	if( r2->antecedents == NULL )
		return transfert(r, r1, r2->suivant);
		
	Relation n = (Relation) malloc( sizeof( struct s_rel ) );

	n->image = r2->image;
	n->antecedents = origines(r2->antecedents, r1);
	n->suivant = r;
		
	return transfert(n, r1, r2->suivant);
}

/**
 * @brief Composition de deux applications
 * @param f : une application  
 * @param g : une application
 * @returns une nouvelle application correspondante à la composition de f et de g
 **/
Application composition(Application f, Application g)
{
	Application n = nouvelle(f.depart, g.arrivee);
	
	n.relation = transfert(n.relation, f.relation, g.relation);
	
	return n;
}


	
	
