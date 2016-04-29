#ifndef __ENSEMBLE_H
#define __ENSEMBLE_H

#include "base.h"

//Définition de l'ensemble
typedef struct s_ens {
	E * valeurs;
	Nat taille; 
	Nat limite; } Ensemble;
	
//Prototypes des fonctions
Ensemble nouvel(Nat capacite);
Bool del(Ensemble e);
posit_n position(Ensemble e, E x);
Bool elem(Ensemble e, E x);
Nat card(Ensemble e);
Ensemble dup(Ensemble s, Ensemble d);
Ensemble adj(Ensemble e, E x);
Ensemble decal(Ensemble e, Nat p);
Ensemble supp(Ensemble * e, E x);
E min(Ensemble e);
E max(Ensemble e);
void affiche(Ensemble e);
Ensemble u(Ensemble e1, Ensemble e2);
Ensemble inter(Ensemble e1, Ensemble e2); 


Ensemble dup(Ensemble s, Ensemble d);

#endif
