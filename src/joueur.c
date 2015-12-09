//gcc joueur.c Outil.c -o joueur

#include <stdio.h>
#include <stdlib.h>
#include "include/Outil.h"
#include "include/joueur.h"
#include "include/rencontre_combat.h"
#include "include/labyrinthe.h"
#define N 5


// Structures de données
typedef struct inventaire{int etat; int contenu[50]; struct inventaire *locker[10];}t_inventaire;
typedef struct {int id; int hp; t_inventaire inventaire; int x; int y; int orientation;}entity;
typedef struct {int etat; int haut;int bas;int gauche; int droite; t_inventaire objets; entity entite;}t_salle;

//Fonctions d'initialisation
void Joueur_initialiser(entity joueur){ // Initialise les stats du joueur, peut être réutilisé plusieurs fois
	joueur.id=1;
	joueur.hp=100;
	joueur.inventaire.etat=1;
	joueur.inventaire.contenu[0]=5;
	joueur.x=0;
	joueur.y=0;
	joueur.orientation=rand()*4-1;
	printf("\nInitialisation : id:%i hp:%i\n", joueur.id, joueur.hp);
}

void Joueur_amorcer(){ // A utiliser seulement une fois (début de partie)
	entity joueur;
	Joueur_initialiser(joueur);
}

//Fonctions booléennes
int bPartie_finie(){ //Indique la fin de partie
	entity joueur;
	if(joueur.hp == 0){
		return 1;
	}
	return 0;
}

int bObjet(t_salle labyrinthe[N][N]){ //Indique la présence ou non d'un objet au sol 
	int x; int y;
	joueurpos(&x, &y);
	Labyrinthe_examiner(x, y, &joueur.inventaire);
	if(){
		return 1;
	}
	return 0;
}

int bMonstre(t_salle labyrinthe[N][N]){ //Indique la présence ou non d'un monstre devant soi
	entity monstre;
	int x; int y;
	joueurpos(&x, &y);
	if()
		return 1;
	return 0;
}

int bMur(entity joueur, t_salle labyrinthe[N][N]){ //Indique la présence ou non du mur dans les 4 directions
	int i, x, y;
	joueurpos(&x, &y);
	for(i=1; i<=4; i++){
		joueur.orientation = i;
		if()
			return 1;
		return 0;	
	}
}


//Fonctions de modification
void Objet_recuperer(entity * joueur){
	
}
void Joueur_hp_modifier(entity * joueur){

}

// Fonctions Joueur 
void Joueur_deplacer(entity joueur, t_salle labyrinthe[N][N]){
	int nord, sud, est, ouest;
	labyrinthe_orienter(&nord, &est, &sud, &ouest);
	do{
	printf("\nDéplacement(s) disponible(s) :\n");
		if(nord == 1)
			printf(" z - Avancer\n");
		if(est == 1)
			printf(" d - Tourner à droite\n");
		if(ouest == 1)
			printf(" q - Tourner à gauche\n");
		
		printf("\n");
		printf("Votre choix : ");
		scanf("%c", &bouger);
		switch(bouger){
			case 'z':  break;
			case 's':  break;
			case 'd':  break;
			case 0: break;
			default: Dis("Déplacement impossible !\n");
		}
	}while(bouger!=0);
}

void Joueur_combattre(entity joueur){ // Fait combattre le joueur contre un monstre
	entity monstre;	
	Combattre(monstre, joueur);
}

void Joueur_agir(t_salle labyrinthe[N][N], entity joueur, entity monstre) { // Permet de faire agir le joueur pendant le tour 
	int tour=0;
	while(!bPartie_finie()){
		//Vérification de la présence d'objet(s) au sol 
		if(bObjet(labyrinthe[N][N]) == 1){
			Objet_recuperer(&joueur);
		}
		//Vérification de la présence d'un monstre
		if(bMonstre(labyrinthe[N][N]) == 1){
			Joueur_combattre(joueur);
		}
		//Vérifications de la présence des murs pour avancer 
		if(bMur(joueur, labyrinthe[N][N]) == 0){
			Joueur_deplacer(joueur, labyrinthe[N][N]);		
		}
	}
	/* Boucle tour du joueur
	 Vérification de la présence d'objets au sol 
		 Si présence alors récupération de l'objet 
	 Vérification de la présence ou non d'un monstre 
		 Si présence du monstre autour de lui alors combat !
		 Perte des points de vie possible 
	 Vérfication des murs présents ou absents autour de lui 
		 Si absence du mur dans une direction alors possibilité de se déplacer 
	   Fin du tour du joueur */   
}

void Joueur_tester(int var){ // Vérification des fonctions 
	entity joueur;
	entity monstre;
	t_salle labyrinthe[N][N];
	
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
			case 3: Joueur_deplacer(joueur, labyrinthe); break;
			case 4: Joueur_combattre(joueur); break;
			case 0: break;
			default: Dis("Ca passe pas !\n");
		}
	}while(var!=0);
	Dis(" A bientôt !\n");
}

//Programme principal
int main(){  
	int var;
	Joueur_amorcer();
	Joueur_tester(var);
	return 0;
}
