#include <stdio.h>
#include <stdlib.h>
#include "include/Outil.h"
#include "include/joueur.h"
#define N 50

/**
\file rencontre_combat.c
\brief Fichier contenant les fonctions Rencontre et Combattre. Les modules joueur et monstre les utilisent pour s'affronter
\date Décembre 2015
\author Junior, Alizée 
*/

// Structures de données 
typedef struct inventaire{int etat; int contenu[50]; struct inventaire *locker[10];}t_inventaire;
typedef struct {int id; int hp; t_inventaire inventaire; int x; int y; int orientation;}entity;
typedef struct {int etat; int haut;int bas;int gauche; int droite; t_inventaire objets; entity entite;}t_salle;

/**
\fn int Rencontre(entity monstre, entity joueur)
\brief Indique si le joueur et le monstre sont positionnés côte à côte
\param monstre Entité le représentant
\param joueur Entité le représentant
\return 1 si la rencontre est effectuée 0 sinon
*/
int Rencontre(entity monstre, entity joueur){
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

/**
\fn void Combattre(entity * monstre, entity * joueur)
\brief Fait combattre le joueur contre un monstre
\param monstre Entité le représentant
\param joueur Entité le représentant
*/
void Combattre(entity * monstre, entity * joueur){
	if(Rencontre(monstre,joueur) == 1){
		
	}
}

/**
\fn Tester_fonctions(void)
\brief Permet de tester les fonctions Rencontre et Combattre
*/
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
