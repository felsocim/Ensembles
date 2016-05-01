/**
 * @file application.h
 * @author Marek Felšöci
**/

#ifndef __APPLICATION_H
#define __APPLICATION_H

#include "base.h"
#include "ensemble.h"
#include "antecedent.h"

typedef struct s_rel {
	E image;
	Antecedent antecedents;
	struct s_rel * suivant; } *Relation;

typedef struct s_app {
	Ensemble depart;
	Ensemble arrivee;
	Relation relation; } Application;

Application nouvelle(Ensemble source, Ensemble but);
Bool del_rel(Relation r);
Application reinit(Application a);
Relation t_im(Relation r, E y);
Relation t_ant(Relation r, E x);
Application fonction(Application a, E x, E y);	
E im(Application a, E x);
Antecedent ant(Application a, E y);
Antecedent origines(Antecedent intermediaire, Relation r1);
Relation transfert(Relation r, Relation r1, Relation r2);
Application composition(Application f, Application g);

#endif
