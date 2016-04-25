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
	
Application fonction(Ensemble source, Ensemble but, E (*op) (E));	
E im(Application a, E x);
Ensemble ant(Application a, E y);

#endif
