/**
 * @file test_applications_composition.c
 * @brief Fichier de tests des opérations sur les applications.
 * @author Marek Felšöci
 **/

#include "../include/base.h"
#include "../include/ensemble.h"
#include "../include/antecedent.h"
#include "../include/application.h"

/**
 * @brief Fonction principale
 * @param void
 * @returns 0
 **/
int main(void)
{
	//TEST DES APPLICATIONS
		
	//Initialisation de deux nouveaux ensembles
	Ensemble e1 = nouvel(10);
	Ensemble e2 = nouvel(7);
	
	printf("\n PARTIE I : DÉFINITION D'UNE APPLICATION AVEC DES RELATIONS A-I \n\n");
	
	//Adjonction des éléments
	e1 = adj(e1, 777);
	e1 = adj(e1, 5);
	e1 = adj(e1, 1);
	e1 = adj(e1, 8);
	e1 = adj(e1, -2);
	e1 = adj(e1, 0);
	e1 = adj(e1, 12);
	e1 = adj(e1, 7);
	e1 = adj(e1, -87);
	e1 = adj(e1, 452);
	e1 = adj(e1, 3);
	
	e2 = adj(e2, 17);
	e2 = adj(e2, -4);
	e2 = adj(e2, 5);
	e2 = adj(e2, 12);
	e2 = adj(e2, 43);
	e2 = adj(e2, 28);
	
	printf("Ensemble 'e1' :");
	affiche(e1);
	
	printf("Cardinal de 'e1' : %d\n", card(e1));
	
	printf("Ensemble 'e2' :");
	affiche(e2);
	
	printf("Cardinal de 'e2' : %d\n", card(e2));
	
	//Définition d'une application 'f' avec 'e1' comme l'ensemble de départ et 'e2' l'ensemble d'arrivée 
	Application f = nouvelle(e1, e2);

	//Définition des relations antécédents / images pour l'application 'f'
	f = fonction(f, 777, 17);	
	f = fonction(f, 12, -4);
	f = fonction(f, 5, 5);
	f = fonction(f, -2, 12);
	f = fonction(f, -87, 12);
	f = fonction(f, 1, 43);
	f = fonction(f, 8, 43);
	f = fonction(f, 452, 43);
	
	printf("\nOn a défini les relations antécédent-image entre 'e1' et 'e2' comme suit: \n");
	printf("x=777; y=17\n");
	printf("x=12; y=-4\n");
	printf("x=5; y=5\n");
	printf("x=-2; y=12\n");
	printf("x=-87; y=12\n");
	printf("x=1; y=43\n");
	printf("x=8; y=43\n");
	printf("x=452; y=43\n\n");
	
	printf("Image de 777 est %d\n", im(f, 777));	
	printf("Image de 12 est %d\n", im(f, 12));
	printf("Image de 5 est %d\n", im(f, 5));
	printf("Image de -2 est %d\n", im(f, -2));
	printf("Image de -87 est %d\n", im(f, -87));
	printf("Image de 1 est %d\n", im(f, 1));
	printf("Image de 8 est %d\n", im(f, 8));
	printf("Image de 452 est %d\n", im(f, 452));
	
	printf("Antécédent(s) de 17 : ");
	affiche_ant(ant(f, 17));
	
	printf("Antécédent(s) de -4 : ");
	affiche_ant(ant(f, -4));
	
	printf("Antécédent(s) de 5 : ");
	affiche_ant(ant(f, 5));
	
	printf("Antécédent(s) de 12 : ");
	affiche_ant(ant(f, 12));
	
	printf("Antécédent(s) de 43 : ");
	affiche_ant(ant(f, 43));
	
	printf("Antécédent(s) de 28 : ");
	affiche_ant(ant(f, 28));
	
//------------------------------------------------------------------------------

	//TEST DE COMPOSITION DE DEUX APPLICATIONS
	
	printf("\n PARTIE II : COMPOSITION DE DEUX APPLICATIONS \n\n");
	
	printf("\n A) : DÉFINITION D'UN 3e ENSEMBLE ET D'UNE 2e APPLICATION \n\n");
	
	//Initialisation d'un troisième ensemble
	Ensemble e3 = nouvel(10);
	
	//Adjonction des éléments
	e3 = adj(e3, -5);
	e3 = adj(e3, 12);
	e3 = adj(e3, -22);
	e3 = adj(e3, 34);
	e3 = adj(e3, 43);
	e3 = adj(e3, 47);
	e3 = adj(e3, 52);
	e3 = adj(e3, 100);
	e3 = adj(e3, 137);
	
	printf("Ensemble 'e3' :");
	affiche(e3);
	
	printf("Cardinal de 'e3' : %d\n", card(e3));
	
	//Définition d'une application 'g' avec 'e2' comme l'ensemble de départ et 'e3' l'ensemble d'arrivée 
	Application g = nouvelle(e2, e3);
	
	//Définition des relations antécédents / images pour l'application 'g'
	
	g = fonction(g, 17, 47);
	g = fonction(g, 5, 47);
	g = fonction(g, 12, -22);
	g = fonction(g, 43, 52);
	g = fonction(g, 28, 100);
	
	printf("\nOn a défini les relations antécédent-image entre 'e2' et 'e3' comme suit: \n");
	printf("x=17; y=47\n");
	printf("x=5; y=47\n");
	printf("x=12; y=-22\n");
	printf("x=43; y=52\n");
	printf("x=28; y=100\n\n");
	
	printf("Image de 17 est %d\n", im(g, 17));	
	printf("Image de 5 est %d\n", im(g, 5));
	printf("Image de 12 est %d\n", im(g, 12));
	printf("Image de 43 est %d\n", im(g, 43));
	printf("Image de 28 est %d\n", im(g, 28));
	
	printf("Antécédent(s) de -5 : ");
	affiche_ant(ant(g, -5));
	
	printf("Antécédent(s) de 12 : ");
	affiche_ant(ant(g, 12));
	
	printf("Antécédent(s) de -22 : ");
	affiche_ant(ant(g, -22));
	
	printf("Antécédent(s) de 34 : ");
	affiche_ant(ant(g, 34));
	
	printf("Antécédent(s) de 43 : ");
	affiche_ant(ant(g, 43));
	
	printf("Antécédent(s) de 47 : ");
	affiche_ant(ant(g, 47));
	
	printf("Antécédent(s) de 52 : ");
	affiche_ant(ant(g, 52));
	
	printf("Antécédent(s) de 100 : ");
	affiche_ant(ant(g, 100));
	
	printf("Antécédent(s) de 137 : ");
	affiche_ant(ant(g, 137));

	//Définition de la composition des applications 'f' et 'g'
	Application c = composition(f, g);
	
	printf("\n B) : DÉFINITION DE LA COMPOSITION g(f(x)) \n\n");
	
	printf("Image de 777 est %d\n", im(c, 777));	
	printf("Image de 5 est %d\n", im(c, 5));
	printf("Image de -2 est %d\n", im(c, -2));
	printf("Image de -87 est %d\n", im(c, -87));
	printf("Image de 1 est %d\n", im(c, 1));
	printf("Image de 8 est %d\n", im(c, 8));
	printf("Image de 452 est %d\n", im(c, 452));
	
	printf("Antécédent(s) de -5 : ");
	affiche_ant(ant(c, -5));
	
	printf("Antécédent(s) de 12 : ");
	affiche_ant(ant(c, 12));
	
	printf("Antécédent(s) de -22 : ");
	affiche_ant(ant(c, -22));
	
	printf("Antécédent(s) de 34 : ");
	affiche_ant(ant(c, 34));
	
	printf("Antécédent(s) de 43 : ");
	affiche_ant(ant(c, 43));
	
	printf("Antécédent(s) de 47 : ");
	affiche_ant(ant(c, 47));
	
	printf("Antécédent(s) de 52 : ");
	affiche_ant(ant(c, 52));
	
	printf("Antécédent(s) de 100 : ");
	affiche_ant(ant(c, 100));
	
	printf("Antécédent(s) de 137 : ");
	affiche_ant(ant(c, 137));
	
//------------------------------------------------------------------------------
	
	//Désallocation de toutes les applications utilisées	
	reinit(f);
	reinit(g);
	reinit(c);
	
	//Désallocation de tous les ensembles utilisés
	del(e1);
	del(e2);
	del(e3);
	
	return 0;
}
