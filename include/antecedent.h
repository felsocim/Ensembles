/**
 * @file antecedent.h
 * @author Marek Felšöci
**/

#ifndef __ANTECEDENT_H
#define __ANTECEDENT_H

#include "base.h"

typedef struct s_ant {
	E val;
	struct s_ant * suivant; } *Antecedent;
	
Antecedent nouv_ant();
Bool del_ant(Antecedent a);
Bool elem_ant(Antecedent a, E v);
Antecedent adj_ant(Antecedent a, E v);
Antecedent ajout(Antecedent d, Antecedent s);
void affiche_ant(Antecedent a);

#endif
