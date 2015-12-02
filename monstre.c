#include <stdio.h>
#include <stdlib.h>
#include "Outil.h"

// Structures de données 
typedef struct {int etat; int contenu[10];}t_inventaire;
typedef struct {int id; int hp; int x,y;t_inventaire inventaire;}entity;
typedef struct {int etat; int haut;int bas;int gauche;int droite; t_inventaire objets; int entite;}t_salle;
 
void Monstre_deplacer(entity monstre,t_salle labyrinthe){
	int nord, est, sud, ouest;
	int direction = 4;
	int rand_g;
	bool deplacement = false;
	// Labyrinthe_orienter(&nord, &est, &sud, &ouest);
	
	/*
		rand % possibilite
		Verifier si rand correspond � nord,est,sud,ouest
			Si vrai alors se deplacer
		sinon faire demi-tour
	*/
	While(10); // Fait cette action pour 10 tours - Modification possible
	do{
		rand_g = rand()%direction;
	
		if(rand_g==1 && nord==1){
			printf("deplacement possible");
			deplacement = true;
		}
		if(rand_g==2 && est==1){
			printf("deplacement possible");
			deplacement = true;
		}
		if(rand_g==3 && sud==1){
			printf("deplacement possible");
			deplacement = true;
		}
		if(rand_g==4 && ouest==1){
			printf("deplacement possible");
			deplacement = true;
		}
	}while(bWhile(deplacement)); /* Fait la boucle tant qu'il n'atteint pas les tours donnés. Après cela, sort du jeu 
			 Assertion failed: (zWhilE[ipWhilE]>=0), function bWhile, file Outil.c, line 1031. <- A modifier */
			 
	/*Faire demi-tour*/
	
	Dis("Cette fonction est encore en cours de construction. Veuillez patienter !");
}

void Monstre_initialiser(entity monstre) // Initialise les stats du monstre, peut être réutilisé plusieurs fois
{
	monstre.id=0;
	monstre.hp=100;
	monstre.inventaire.etat=1;
	monstre.inventaire.contenu[0]=5;
	printf("\nInit : id:%i hp:%i\n", monstre.id, monstre.hp);
}

void Monstre_agir(t_salle labyrinthe, entity joueur, entity monstre) { // Permet de faire agir le monstre pendant le tour 
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

void Monstre_tester(int var){ // Vérification des fonctions 
	entity joueur;
	entity monstre;
	t_salle labyrinthe[N][N];
	
	do{
		printf("\nMenu :\n");
		printf(" 1 - Initialisation de départ\n");
		//printf(" 2 - Faire agir le joueur\n");
		printf(" 3 - Faire déplacer le monstre\n");
		printf(" 4 - Faire combattre le monstre\n");
		printf(" 0 - Quitter\n");
		printf("Votre choix : ");
		scanf("%i", &var);
		switch(var){
			case 1: Monstre_initialiser(monstre); break;
			//case 2: Joueur_agir(labyrinthe, joueur, monstre); break; 
			case 3: Monstre_deplacer(monstre); break;
			case 4: combattre(monstre); break;
			case 0: break;
			default: Dis("Ca passe pas !\n");
		}
	}while(var!=0);
	Dis("C'est tellement dommage que l'on se quitte. A bientôt ! :)\n");
}

void Monstre_amorcer(){ // A utiliser seulement une fois (début de partie)
	entity monstre;
	Monstre_initialiser(monstre);
}

int main(){
	int var;
	Monstre_amorcer();
	Monstre_tester(var);
	return 0;
}
