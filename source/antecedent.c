#include "../include/antecedent.h"

Antecedent nouv_ant()
{
	return (Antecedent) NULL;
}

Bool del_ant(Antecedent a)
{
	if( a == NULL )
		return vrai;
		
	Antecedent t = a->suivant;
	
	free(a);
	
	return del_ant(t);
}

Bool elem_ant(Antecedent a, E v)
{
	if( a == NULL )
		return faux;
	
	if( a->val == v )
		return vrai;
		
	return elem_ant(a->suivant, v);
}

Antecedent adj_ant(Antecedent a, E v)
{
	if( elem_ant(a, v) == vrai )
		return a;
		
	Antecedent n = (Antecedent) malloc( sizeof( struct s_ant ) );
	
	n->val = v;
	
	n->suivant = a;
	
	return n;
}

Antecedent ajout(Antecedent d, Antecedent s)
{
	if( s == NULL )
		return d;
		
	d = adj_ant(d, s->val);
	
	return ajout(d, s->suivant);
}

void affiche_ant(Antecedent a)
{
	if( a == NULL )
	{
		printf("Pas d'antécedents\n");
		return;
	}
	
	if( a->suivant == NULL )
	{
		printf(" { %d } \n", a->val);
		return;
	}
	else
	{
		printf(" { %d } ", a->val);
	}
		
	affiche_ant(a->suivant);
}
