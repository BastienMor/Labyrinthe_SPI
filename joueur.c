#include <stdio.h>
#include <stdlib.h>
#include "Outil.h"

// Structures de données 
typedef struct {int etat; int contenu[10];}t_inventaire;
typedef struct {int id; int hp; t_inventaire inventaire;}entity;
typedef struct {int etat; int haut;int bas;int gauche;int droite; t_inventaire objets; int entite;}t_salle;

// Fonctions Joueur 
void Joueur_deplacer(entity joueur){
	int nord, est, sud, ouest;
	// Labyrinthe_orienter(&nord, &est, &sud, &ouest);
	int var;
	
	While(10); // Fait cette action pour 10 tours - Modification possible
	do{
		printf("\nDéplacements disponibles :\n");
		printf(" 1 - Nord\n");
		printf(" 2 - Est\n");
		printf(" 3 - Sud\n");
		printf(" 4 - Ouest\n");
		printf(" 0 - Quitter\n");
		printf("Votre choix : ");
		scanf("%i", &var);
		switch(var){
			case 1: if(nord == 1){ 
						Dis("Déplacement possible !"); } break;
			case 2: if(est == 1) { 
						Dis("Déplacement possible !"); } break;
			case 3: if(sud == 1) {
						Dis("Déplacement possible !"); } break;
			case 4: if(ouest == 1) {
						Dis("Déplacement possible !"); } break;
			case 5: break;
			default: Dis("Déplacement impossible !");
		}
	}while(bWhile(var!=0)); /* Fait la boucle tant qu'il n'atteint pas les tours donnés. Après cela, sort du jeu 
			 Assertion failed: (zWhilE[ipWhilE]>=0), function bWhile, file Outil.c, line 1031. <- A modifier */
}
void Joueur_initialiser(entity joueur) // Initialise les stats du joueur, peut être réutilisé plusieurs fois
{
	joueur.id=0;
	joueur.hp=100;
	joueur.inventaire.etat=1;
	joueur.inventaire.contenu[0]=5;
	printf("\nInit : id:%i hp:%i\n", joueur.id, joueur.hp);
}

void Joueur_combattre(entity joueur){ // Fait combattre le joueur contre un monstre
	Dis("Cette fonction est encore en cours de construction. Veuillez patienter !");
}

void Joueur_agir(t_salle labyrinthe, entity joueur, entity monstre) { // Permet de faire agir le joueur pendant le tour 
	Dis("Cette fonction est encore en cours de construction. Veuillez patienter !");
	/* Boucle tour du joueur
	 Vérification de la présence d'objets au sol 
		 Si présence alors récupération de l'objet 
	 Vérification de la présence ou non d'un monstre 
		 Si présence du monstre autour de lui alors combat !
		 Perte des points de vie possible 
	 Vérfication des murs présents ou absents autour de lui 
		 Si absence du mur dans une direction alors possibilité de se déplacer 
		 Perte des points de vie possible
	   Fin du tour du joueur */
}

void Joueur_tester(int var){ // Vérification des fonctions 
	entity joueur;
	entity monstre;
	t_salle labyrinthe;
	
	do{
		printf("\nMenu :\n");
		printf(" 1 - Initialisation de départ\n");
		printf(" 2 - Faire agir le joueur\n");
		printf(" 3 - Faire déplacer le joueur\n");
		printf(" 4 - Faire combattre le joueur\n");
		printf(" 0 - Quitter\n");
		printf("Votre choix : ");
		scanf("%i", &var);
		switch(var){
			case 1: Joueur_initialiser(joueur); break;
			case 2: Joueur_agir(labyrinthe, joueur, monstre); break; 
			case 3: Joueur_deplacer(joueur); break;
			case 4: Joueur_combattre(joueur); break;
			case 0: break;
			default: Dis("Ca passe pas !\n");
		}
	}while(var!=0);
	Dis("C'est tellement dommage que l'on se quitte. A bientôt ! :)\n");
}

void Joueur_amorcer(){ // A utiliser seulement une fois (début de partie)
	entity joueur;
	Joueur_initialiser(joueur);
}

int main(){
	int var;
	Joueur_amorcer();
	Joueur_tester(var);
	return 0;
}
