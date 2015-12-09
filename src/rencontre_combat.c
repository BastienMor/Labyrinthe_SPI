#include <stdio.h>
#include <stdlib.h>
#include "include/Outil.h"
#include "include/joueur.h"
#define N 50

// Structures de données 
typedef struct inventaire{int etat; int contenu[50]; struct inventaire *locker[10];}t_inventaire;
typedef struct {int id; int hp; t_inventaire inventaire; int x; int y; int orientation;}entity;
typedef struct {int etat; int haut;int bas;int gauche; int droite; t_inventaire objets; entity entite;}t_salle;

int Rencontre(entity monstre, entity joueur){ // Vérifier la rencontre du joueur et d'un monstre
	t_salle labyrinthe[N][N];
	if(labyrinthe[monstre.x][monstre.y] == labyrinthe[joueur.x-1][monstre.y]{
			return 1;
	}
	if(labyrinthe[monstre.x][monstre.y] == labyrinthe[joueur.x][monstre.y+1]{
			return 1;
	}
	if(labyrinthe[monstre.x][monstre.y] == labyrinthe[joueur.x+1][monstre.y]{
			return 1;
	}
	if(labyrinthe[monstre.x][monstre.y] == labyrinthe[joueur.x][monstre.y-1]{
			return 1;
	}
	return 0;
}

void Combattre(entity * monstre, entity * joueur){ // Fait combattre le joueur contre un monstre
	if(Rencontre(monstre,joueur) == 1){
		
	}
}

void Tester_fonctions(){
	entity monstre;
	entity joueur;
	t_salle labyrinthe[N][N];
	int var;
	do{
			printf("Test des fonctions :\n");
			printf(" 1 - Rencontre\n");
			printf(" 2 - Combattre\n");
			printf("Votre choix : ");
			scanf("%i", &var);
			switch(var){
				case 1 : Rencontre(monstre, joueur); break;
				case 2 : Combattre(monstre, joueur); break;
				case 0 : break;
	while(var!=0);
}

int main(){
	Tester_fonctions();
	return 0;
}
