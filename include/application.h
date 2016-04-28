#ifndef __APPLICATION_H
#define __APPLICATION_H

#include "ensemble.h"

typedef struct s_rel {
	E image;
	Ensemble antecedents;
	struct s_rel * suivant; } *Relation;
	
typedef struct s_app {
	Ensemble depart;
	Ensemble arrivee;
	Relation relation; } Application;

Application nouvelle(Ensemble source, Ensemble but);
Application reinit(Application a);
Relation trouver_im(Relation r, E y);
Relation trouver_ant(Relation r, E x);
Application fonction(Application a, E x, E y);	
E im(Application a, E x);
Ensemble ant(Application a, E y);

Application composition(Application f, Application g);

#endif
