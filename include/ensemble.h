#ifndef __ENSEMBLE_H
#define __ENSEMBLE_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Définition des types de données

typedef int E;
typedef unsigned int Nat;
typedef int posit_n;
typedef enum { faux, vrai } Bool;
typedef struct s_ens {
	E * valeurs;
	Nat taille; 
	Nat limite; } Ensemble;
	
//Prototypes des fonctions

Ensemble nouvel(Nat capacite);
Bool del(Ensemble e);

Bool elem(Ensemble e, E x);
Nat card(Ensemble e);
Ensemble adj(Ensemble e, E x);
Ensemble supp(Ensemble * e, E x);
E min(Ensemble e);
E max(Ensemble e);

Ensemble u(Ensemble e1, Ensemble e2);
Ensemble inter(Ensemble e1, Ensemble e2); 

posit_n position(Ensemble e, E x);
Ensemble dup(Ensemble s, Ensemble d);

#endif
