#include "../include/base.h"
#include "../include/ensemble.h"

int main(void)
{
	Ensemble e = nouvel(10);
	
	e = adj(e, 777);
	
	e = adj(e, 5);
	
	e = adj(e, 1);
	
	e = adj(e, 8);
	
	e = adj(e, -2);
	
	e = adj(e, 0);
	
	e = adj(e, 12);
	
	e = adj(e, 7);
	
	affiche(e);
	
	/*e = supp(&e, 1);
	
	e = supp(&e, 12);
	
	e = supp(&e, 777);
	
	affiche(e);
	
	del(e);*/
	
	/*Ensemble es = nouvel(3);
	
	es = adj(es, 1);
	
	es = adj(es, 5);
	
	es = adj(es, 3);
	
	es = adj(es, 2);
	
	es = adj(es, 4);
	
	affiche(es);
		
	es = supp(&es, 3);
	
	printf("Card(es) = %d\n", card(es));
	
	affiche(es);
	
	es = supp(&es, 1);
	
	es = supp(&es, 2);
	
	es = supp(&es, 4);
	
	es = supp(&es, 5);
	
	affiche(es);
	
	printf("Card(es) = %d\n\n", card(es));
	
	del(es);
	
	
	printf("Min(e) = %d\n", min(e));
	
	printf("Max(e) = %d\n", max(e));*/
	
		
	Ensemble e1 = nouvel(4);
	
	Ensemble e2 = nouvel(5);
	
	e1 = adj(e1, 1);
	e1 = adj(e1, 2);
	e1 = adj(e1, 3);
	e1 = adj(e1, 4);
	
	e2 = adj(e2, 3);
	e2 = adj(e2, 4);
	e2 = adj(e2, 5);
	e2 = adj(e2, 6);
	e2 = adj(e2, 7);
	
	affiche(e1);
	
	affiche(e2);
	
	Ensemble res1 = u(e1, e2);
	
	affiche(res1);
	
	printf("Min(u(e1,e2)) = %d\n", min(res1));
	
	printf("Max(u(e1,e2)) = %d\n", max(res1));
	
	
	Ensemble res3 = inter(e1, e);
	
	affiche(res3);
	
	printf("Min(inter(e1,e)) = %d\n", min(res3));
	
	printf("Max(inter(e1,e)) = %d\n", max(res3));
	
	del(e);
	
	del(e1);
	
	del(e2);
	
	del(res1);
	
	del(res3);
	
	return 0;
}
