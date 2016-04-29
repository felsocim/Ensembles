#include "../include/application.h"

Application nouvelle(Ensemble source, Ensemble but)
{
	Application n;
	
	n.depart = source;
	n.arrivee = but;
	n.relation = NULL;
	
	return n;
}

Bool del_rel(Relation r)
{
	if( r == NULL )
		return vrai;
		
	Relation t = r->suivant;
	
	del_ant(r->antecedents);
	
	free(r);
	
	return del_rel(t);
}

Application reinit(Application a)
{
	del_rel(a.relation);
	
	return a;
}

Relation t_im(Relation r, E y)
{
	if( r == NULL )
		return NULL;
	
	if( r->image == y )
		return r;
		
	return t_im(r->suivant, y);
}

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
	
E im(Application a, E x)
{
	Relation t = t_ant(a.relation, x);
	
	if( t != NULL )
		return t->image;
}

Antecedent ant(Application a, E y)
{
	Relation t = t_im(a.relation, y);
	
	if( t != NULL )
		return t->antecedents;
		
	return NULL;
}

Antecedent origines(Antecedent intermediaire, Relation r1)
{
	if( intermediaire == NULL )
		return NULL;
		
	Relation t = t_im(r1, intermediaire->val); 
	
	if( t == NULL )
		return origines(intermediaire->suivant, r1);
		
	return ajout(origines(intermediaire->suivant, r1), t->antecedents );
}

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

Application composition(Application f, Application g)
{
	Application n = nouvelle(f.depart, g.arrivee);
	
	n.relation = transfert(n.relation, f.relation, g.relation);
	
	return n;
}


	
	
