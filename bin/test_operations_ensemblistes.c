/**
 * @file test_operations_ensemblistes.c
 * @brief Fichier de tests des opérations ensemblistes (union et intersection).
 * @author Marek Felšöci
 **/
 
#include "../include/base.h"
#include "../include/ensemble.h"

/**
 * @brief Fonction principale
 * @param void
 * @returns 0
 **/
int main(void)
{
	//1ER CAS DE FIGURE : DEUX ENSEMBLES NON-VIDES AYANT CERTAINS ÉLÉMENTS EN COMMUN
	
	//Initialisation de deux nouveaux ensembles
	Ensemble e1 = nouvel(10);
	
	Ensemble e2 = nouvel(10);
	
	printf("\n PARTIE I : DEUX ENSEMBLES NON-VIDES AYANT CERTAINS ÉLÉMENTS EN COMMUN \n\n");
	
	//Adjonction des éléments
	e1 = adj(e1, -5);
	e1 = adj(e1, 12);
	e1 = adj(e1, -22);
	e1 = adj(e1, 34);
	e1 = adj(e1, 42);
	e1 = adj(e1, 47);
	e1 = adj(e1, 51);
	e1 = adj(e1, 100);
	e1 = adj(e1, 139);
	
	e2 = adj(e2, -78);
	e2 = adj(e2, -55);
	e2 = adj(e2, -12);
	e2 = adj(e2, 0);
	e2 = adj(e2, 42);
	e2 = adj(e2, 51);
	e2 = adj(e2, 139);
	e2 = adj(e2, 212);
	e2 = adj(e2, 7);
	e2 = adj(e2, -46);
	e2 = adj(e2, 785);
	e2 = adj(e2, 1305);
	
	printf("Ensemble 'e1' :");
	affiche(e1);
	
	printf("Cardinal de 'e1' : %d\n", card(e1));
	
	printf("Ensemble 'e2' :");
	affiche(e2);
	
	printf("Cardinal de 'e2' : %d\n", card(e2));
	
	//Calcul de l'union et de l'intersection de 'e1' et 'e2'
	Ensemble ru = u(e1, e2);

	Ensemble rinter = inter(e1, e2);
	
	printf("Union de 'e1' et 'e2' :");
	affiche(ru);
	
	printf("Cardinal de l'union : %d\n", card(ru));
	
	printf("Minimum de l'union : %d\n", min(ru));
	
	printf("Maximum de l'union : %d\n", max(ru));
	
	printf("Intersection de 'e1' et 'e2' :");
	affiche(rinter);
	
	printf("Cardinal de l'intersection : %d\n", card(rinter));
	
	printf("Minimum de l'intersection : %d\n", min(rinter));
	
	printf("Maximum de l'intersection : %d\n", max(rinter));

//------------------------------------------------------------------------------	
	
	//2E CAS DE FIGURE : DEUX ENSEMBLES NON-VIDES N'AYANT AUCUN ÉLÉMENT EN COMMUN
	
	//Initialisation de deux nouveaux ensembles
	Ensemble e3 = nouvel(10);
	
	Ensemble e4 = nouvel(10);
	
	printf("\n PARTIE II : DEUX ENSEMBLES NON-VIDES N'AYANT AUCUN ÉLÉMENT EN COMMUN \n\n");
	
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
	
	e4 = adj(e4, -78);
	e4 = adj(e4, -55);
	e4 = adj(e4, -12);
	e4 = adj(e4, 0);
	e4 = adj(e4, 42);
	e4 = adj(e4, 51);
	e4 = adj(e4, 139);
	e4 = adj(e4, 212);
	e4 = adj(e4, 7);
	e4 = adj(e4, -46);
	e4 = adj(e4, 785);
	e4 = adj(e4, 1305);
	
	printf("Ensemble 'e3' :");
	affiche(e3);
	
	printf("Cardinal de 'e3' : %d\n", card(e3));
	
	printf("Ensemble 'e4' :");
	affiche(e4);
	
	printf("Cardinal de 'e4' : %d\n", card(e4));
	
	//Calcul de l'union et de l'intersection de 'e3' et 'e4'
	Ensemble ru2 = u(e3, e4);

	Ensemble rinter2 = inter(e3, e4);
	
	printf("Union de 'e3' et 'e4' :");
	affiche(ru2);
	
	printf("Cardinal de l'union : %d\n", card(ru2));
	
	printf("Minimum de l'union : %d\n", min(ru2));
	
	printf("Maximum de l'union : %d\n", max(ru2));
	
	printf("Intersection de 'e3' et 'e4' :");
	affiche(rinter2);
	
	printf("Cardinal de l'intersection : %d\n", card(rinter2));
	
	//Pas de calcul des extrémités de l'intersection car le résultat est 
	//un ensemble vide dans ce cas de figure.
	
//------------------------------------------------------------------------------	
	
	//3E CAS DE FIGURE : DEUX ENSEMBLES DONT LE PREMIER EST VIDE
	
	//Initialisation de deux nouveaux ensembles
	Ensemble e5 = nouvel(10);
	
	Ensemble e6 = nouvel(10);
	
	printf("\n PARTIE III : DEUX ENSEMBLES DONT LE PREMIER EST VIDE \n\n");
	
	//Adjonction des éléments
	e6 = adj(e6, -78);
	e6 = adj(e6, -55);
	e6 = adj(e6, -12);
	e6 = adj(e6, 0);
	e6 = adj(e6, 42);
	e6 = adj(e6, 51);
	e6 = adj(e6, 139);
	e6 = adj(e6, 212);
	
	printf("Ensemble 'e5' :");
	affiche(e5);
	
	printf("Cardinal de 'e5' : %d\n", card(e5));
	
	printf("Ensemble 'e6' :");
	affiche(e6);
	
	printf("Cardinal de 'e6' : %d\n", card(e6));
	
	//Calcul de l'union et de l'intersection de 'e5' et 'e6'
	Ensemble ru3 = u(e5, e6);

	Ensemble rinter3 = inter(e5, e6);
	
	printf("Union de 'e5' et 'e6' :");
	affiche(ru3);
	
	printf("Cardinal de l'union : %d\n", card(ru3));
	
	printf("Minimum de l'union : %d\n", min(ru3));
	
	printf("Maximum de l'union : %d\n", max(ru3));
	
	printf("Intersection de 'e5' et 'e6' :");
	affiche(rinter3);
	
	printf("Cardinal de l'intersection : %d\n", card(rinter3));
	
	//Pas de calcul des extrémités de l'intersection car le résultat est 
	//un ensemble vide dans ce cas de figure.
	
//------------------------------------------------------------------------------	
	
	//4E CAS DE FIGURE : DEUX ENSEMBLES DONT LE SECOND EST VIDE
	
	//Initialisation de deux nouveaux ensembles
	Ensemble e7 = nouvel(10);
	
	Ensemble e8 = nouvel(10);
	
	printf("\n PARTIE IV : DEUX ENSEMBLES DONT LE SECOND EST VIDE \n\n");
	
	//Adjonction des éléments
	e7 = adj(e7, -78);
	e7 = adj(e7, -55);
	e7 = adj(e7, -12);
	e7 = adj(e7, 0);
	e7 = adj(e7, 42);
	e7 = adj(e7, 51);
	e7 = adj(e7, 139);
	e7 = adj(e7, 212);
	
	printf("Ensemble 'e7' :");
	affiche(e7);
	
	printf("Cardinal de 'e7' : %d\n", card(e7));
	
	printf("Ensemble 'e8' :");
	affiche(e8);
	
	printf("Cardinal de 'e8' : %d\n", card(e8));
	
	//Calcul de l'union et de l'intersection de 'e7' et 'e8'
	Ensemble ru4 = u(e7, e8);

	Ensemble rinter4 = inter(e7, e8);
	
	printf("Union de 'e7' et 'e8' :");
	affiche(ru4);
	
	printf("Cardinal de l'union : %d\n", card(ru4));
	
	printf("Minimum de l'union : %d\n", min(ru4));
	
	printf("Maximum de l'union : %d\n", max(ru4));
	
	printf("Intersection de 'e7' et 'e8' :");
	affiche(rinter4);
	
	printf("Cardinal de l'intersection : %d\n", card(rinter4));
	
	//Pas de calcul des extrémités de l'intersection car le résultat est 
	//un ensemble vide dans ce cas de figure.

//------------------------------------------------------------------------------	
	
	//5E CAS DE FIGURE : DEUX ENSEMBLES VIDES
	
	//Initialisation de deux nouveaux ensembles
	Ensemble e9 = nouvel(10);
	
	Ensemble e10 = nouvel(10);
	
	printf("\n PARTIE V : DEUX ENSEMBLES VIDES \n\n");
	
	printf("Ensemble 'e9' :");
	affiche(e9);
	
	printf("Cardinal de 'e9' : %d\n", card(e9));
	
	printf("Ensemble 'e10' :");
	affiche(e10);
	
	printf("Cardinal de 'e10' : %d\n", card(e10));
	
	//Calcul de l'union et de l'intersection de 'e9' et 'e10'
	Ensemble ru5 = u(e9, e10);

	Ensemble rinter5 = inter(e9, e10);
	
	printf("Union de 'e9' et 'e10' :");
	affiche(ru5);
	
	printf("Cardinal de l'union : %d\n", card(ru5));
	
	//Pas de calcul des extrémités de l'union car le résultat est un ensemble 
	//vide dans ce cas de figure.
	
	printf("Intersection de 'e9' et 'e10' :");
	affiche(rinter5);
	
	printf("Cardinal de l'intersection : %d\n", card(rinter5));
	
	//Pas de calcul des extrémités de l'intersection car le résultat est 
	//un ensemble vide dans ce cas de figure.
	
//------------------------------------------------------------------------------	
	
	//Désallocation de tous les ensembles utilisés 
	del(e1);
	del(e2);
	del(ru);
	del(rinter);
	del(e3);
	del(e4);
	del(ru2);
	del(rinter2);
	del(e5);
	del(e6);
	del(ru3);
	del(rinter3);
	del(e7);
	del(e8);
	del(ru4);
	del(rinter4);
	del(e9);
	del(e10);
	del(ru5);
	del(rinter5);
	
	return 0;
}
