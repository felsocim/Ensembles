#include "ensemble.h"

Ensemble nouvel(Nat capacite)
{
	Ensemble n;
	
	n.valeurs = (E *) malloc(capacite * sizeof(E));
	n.taille = 0;
	
	if( n.valeurs == NULL ) //En cas d'erreur de l'allocation
		n.limite = 0;
	
	n.limite = capacite;
	
	return n;
}
	
Bool del(Ensemble e)
{
	e.taille = 0;
	e.limite = 0;
	
	if( e.valeurs == NULL )
		return vrai;
	
	free(e.valeurs);
	
	return vrai;
}

posit_n position(Ensemble e, E x)
{
	if( e.taille < 1 )
		return -1;
		
	if( e.taille >= 1 )
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

Bool elem(Ensemble e, E x)
{
	if( position(e ,x) == -1 )
		return faux;
		
	return vrai;
}
		
Nat card(Ensemble e)
{
	return e.taille;
}

Ensemble adj(Ensemble e, E x)
{
	if( elem(e, x) == vrai )
		return e;
		
	if( e.taille < e.limite )
	{
		e.valeurs[e.taille] = x;
		e.taille++;
		
		return e;
	}	
	
	if( e.taille >= 0 )
	{
		e.valeurs = realloc(e.valeurs, ( e.taille + 1) * sizeof(E));
		e.valeurs[e.taille] = x;
		e.taille++;
	}
	
	return e;
}

Ensemble decal(Ensemble e, Nat p)
{
	if( p < ( e.taille - 1) )
	{
		e.valeurs[p] = e.valeurs[p + 1];
		
		return decal(e, p + 1);
	}
	
	return e;
}

Ensemble supp(Ensemble * e, E x)
{
	posit_n p;
	
	if( ( p = position(*e, x) ) == -1 )
		return *e;
		
	*e = decal(*e, p);
		
	e->valeurs = (E *) realloc(e->valeurs, ( e->taille - 1 ) * sizeof(E));	
	e->taille--;
	
	return *e;
}

E min(Ensemble e)
{
	E temp = e.valeurs[e.taille - 1];
	
	e.taille--;
	
	if( e.taille < 1 )
		return temp;

	if( min(e) < temp )
		return min(e);
	
	return temp;
}

E max(Ensemble e)
{
	E temp = e.valeurs[e.taille - 1];
	
	e.taille--;
	
	if( e.taille < 1 )
		return temp;

	if( max(e) > temp )
		return max(e);
	
	return temp;
}

void affiche(Ensemble e)
{
	if( e.taille < 1 )
	{
		printf(" vide \n");
		return;
	}
		
	if( e.taille == 1 )
	{
		printf(" { %d } \n", e.valeurs[e.taille - 1]);
		return;
	}
	
	printf(" { %d } ", e.valeurs[e.taille - 1]);
	e.taille--;
	
	affiche(e);
}

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

Ensemble u(Ensemble e1, Ensemble e2)
{
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

Ensemble inter(Ensemble e1, Ensemble e2)
{
	if( e1.taille < 1 )
		return nouvel(0);
	
	if( e2.taille < 1 )
		return nouvel(0);
		
	if( elem(e2, e1.valeurs[e1.taille - 1]) == vrai )
	{	
		return adj(inter(e1, e2), e1.valeurs[--e1.taille]);
	}
	
	e1.taille--;
	e2.taille--;
	
	return inter(e1, e2);
}
