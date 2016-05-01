/**
 * @file test_ensembles_base.c
 * @brief Fichier de tests des opérations de base sur les ensembles.
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
	//Initialisation d'un nouvel ensemble avec une capacité initiale de 10 éléments
	Ensemble e = nouvel(10);
	
	//Adjonction de 8 nouveaux éléments dans l'ensemble 'e'
	e = adj(e, 45);	
	e = adj(e, 6);
	e = adj(e, 127);	
	e = adj(e, 57);	
	e = adj(e, -23);	
	e = adj(e, 0);	
	e = adj(e, 12);
	e = adj(e, 1278);
	
	printf("Ensemble e :");
	affiche(e);
	
	printf("Cardinal de e : %d\n", card(e));
	
	printf("Minimum de e : %d\n", min(e));
	
	printf("Maximum de e : %d\n", max(e));
	
	//Adjonction de nouveaux éléments dans l'ensemble 'e' en dépassant sa capacité initiale de 10 éléments
	e = adj(e, 55);	
	e = adj(e, -23); //L'élément '-23' ne sera pas ajouté car il se trouve déjà dans l'ensemble 'e'	
	e = adj(e, 123);	
	e = adj(e, 256);
	e = adj(e, 4096);
	
	printf("Ensemble e :");
	affiche(e);
	
	printf("Cardinal de e : %d\n", card(e));
	
	printf("Minimum de e : %d\n", min(e));
	
	printf("Maximum de e : %d\n", max(e));
	
	//Suppression de tous les éléments de l'ensemble 'e'
	e = supp(&e, 55);
	e = supp(&e, -23);
	e = supp(&e, 1278);
	e = supp(&e, 123);
	e = supp(&e, 12);
	e = supp(&e, 0);
	e = supp(&e, 256);
	e = supp(&e, 4096);
	e = supp(&e, 57);
	e = supp(&e, 127);
	e = supp(&e, 6);
	e = supp(&e, 45);
	
	//Affichage d'un ensemble ne comportant aucun élément
	printf("Ensemble e :");
	affiche(e);
	
	printf("Cardinal de e : %d\n", card(e));
	
	//Adjonction de nouveaux éléments dans un ensemble vide mais déjà utilisé
	e = adj(e, 10);
	e = adj(e, -20);
	e = adj(e, 30);
	e = adj(e, 40);
	e = adj(e, 50);
	
	printf("Ensemble e :");
	affiche(e);
	
	printf("Cardinal de e : %d\n", card(e));
	
	printf("Minimum de e : %d\n", min(e));
	
	printf("Maximum de e : %d\n", max(e));
	
	//Désallocation de l'ensemble 'e' à la fin du programme
	del(e);
	
	return 0;
}
