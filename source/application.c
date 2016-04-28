#include "../include/application.h"

Application nouvelle(Ensemble source, Ensemble but)
{
	Application n;
	
	n.depart = source;
	n.arrivee = but;
	n.relation = NULL;
	
	return n;
}

Bool drel(Relation r)
{
	if( r == NULL )
		return vrai;
		
	Relation t = r->suivant;
	
	del(r->antecedents);
	
	free(r);
	
	return drel(t);
}

Application reinit(Application a)
{
	drel(a.relation);
	
	return a;
}

Relation trouver_im(Relation r, E y)
{
	if( r == NULL )
		return NULL;
	
	if( r->image == y )
		return r;
		
	return trouver_im(r->suivant, y);
}

Relation trouver_ant(Relation r, E x)
{
	if( r == NULL )
		return NULL;
		
	if( r->antecedents.taille < 1 )
		return trouver_ant(r->suivant, x);
		
	if( elem(r->antecedents, x) == vrai )
		return r;
	
	return trouver_ant(r->suivant, x);
}
	
Application fonction(Application a, E x, E y)
{
	if( elem(a.depart, x) == faux )
		return a;
		
	if( elem(a.arrivee, y) == faux )
		return a;
		
	if( trouver_ant(a.relation, x) != NULL )
		return a;
	
	Relation t = NULL;
	
	if( ( t = trouver_im(a.relation, y) ) != NULL )
	{		
		t->antecedents = adj(t->antecedents, x);
		
		t = NULL;
		
		return a;
	}
		
	Relation n = (Relation) malloc( sizeof( struct s_rel ) );

	n->image = y;
	n->antecedents = nouvel(1);
	n->antecedents = adj(n->antecedents, x);
	n->suivant = a.relation;
	
	a.relation = n;
		
	return a;
}
	
E im(Application a, E x)
{
	Relation t = trouver_ant(a.relation, x);
	
	if( t != NULL )
		return t->image;
}

Ensemble ant(Application a, E y)
{
	Relation t = trouver_im(a.relation, y);
	
	if( t != NULL )
		return t->antecedents;
		
	return nouvel(0);
}

Ensemble ajout(Ensemble d, Ensemble s)
{
	if( s.taille < 1 )
		return d;
		
	d = adj(d, s.valeurs[--s.taille]);
	
	return ajout(d, s);
}

Ensemble origines(Ensemble intermediaire, Relation r1)
{
	if( intermediaire.taille < 1 )
		return nouvel(0);
		
	Relation t = trouver_im(r1, intermediaire.valeurs[--intermediaire.taille]); 
	
	if( t == NULL )
		return origines(intermediaire, r1);
		
	return ajout(origines(intermediaire, r1), t->antecedents );
}

Relation transfert(Relation r, Relation r1, Relation r2)
{
	if( r1 == NULL )
		return r;
		
	if( r2 == NULL )
		return r;
		
	if( r2->antecedents.taille < 1 )
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
