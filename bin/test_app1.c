#include "../include/base.h"
#include "../include/ensemble.h"
#include "../include/antecedent.h"
#include "../include/application.h"

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
	
	Application a = nouvelle(e, e1);

	a = fonction(a, 777, 1);
	
	a = fonction(a, 12, 1);
	
	a = fonction(a, 5, 2);
	
	a = fonction(a, -2, 2);
	
	a = fonction(a, 1, 3);
	
	a = fonction(a, 8, 4);
	
	/*printf("Image de 777 est %d\n", im(a, 777));
	
	printf("Image de 12 est %d\n", im(a, 12));
	
	printf("Image de 5 est %d\n", im(a, 5));
	
	printf("Image de 1 est %d\n", im(a, 1));
	
	printf("Image de 8 est %d\n", im(a, 8));
	
	printf("Antecedent(s) de 1 : ");
	affiche(ant(a, 1));
	
	printf("Antecedent(s) de 2 : ");
	affiche(ant(a, 2));
	
	printf("Antecedent(s) de 3 : ");
	affiche(ant(a, 3));
	
	printf("Antecedent(s) de 4 : ");
	affiche(ant(a, 4));*/
	
	Application b = nouvelle(e1, e2);
	
	b = fonction(b, 1, 3);
	
	b = fonction(b, 2, 5);
	
	b = fonction(b, 3, 3);
	
	b = fonction(b, 4, 7);
	
	Application c = composition(a, b);
	
	printf("Image de 777 est %d\n", im(c, 777));
	
	printf("Image de 12 est %d\n", im(c, 12));
	
	printf("Image de 5 est %d\n", im(c, 5));
	
	printf("Image de -2 est %d\n", im(c, -2));
	
	printf("Image de 1 est %d\n", im(c, 1));
	
	printf("Image de 8 est %d\n", im(c, 8));
	
	printf("Antecedent(s) de 3 : ");
	affiche_ant(ant(c, 3));
	
	printf("Antecedent(s) de 4 : ");
	affiche_ant(ant(c, 4));
	
	printf("Antecedent(s) de 5 : ");
	affiche_ant(ant(c, 5));
	
	printf("Antecedent(s) de 6 : ");
	affiche_ant(ant(c, 6));
	
	printf("Antecedent(s) de 7 : ");
	affiche_ant(ant(c, 7));
	
	reinit(a);
	
	reinit(b);
	
	reinit(c);
	
	del(e);
	del(e1);
	del(e2);
	
	return 0;
}
