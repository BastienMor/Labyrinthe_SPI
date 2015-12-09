#include <stdio.h>
#include <stdlib.h>
#include "Outil.h"

/**
\file monstre.c
\brief Module permettant d'utiliser les différentes fonctions associées au(x) monstre(s) présent(s) dans le jeu
\date Novembre 2015
\author Junior
*/

typedef struct {int etat; int contenu[10];}t_inventaire;
typedef struct {int id; int hp; int x,y;t_inventaire inventaire;}entity;
typedef struct {int etat; int haut;int bas;int gauche;int droite; t_inventaire objets;}t_salle;

/**
\fn void Monstre_initialiser(entity monstre)
\brief Initialise les statistiques du monstre
\param monstre Variable de type entity correspondant au monstre
*/
void Monstre_initialiser(entity monstre){
	monstre.id=0;
	monstre.hp=100;
	monstre.x=0;
	monstre.y=0;
	monstre.inventaire.etat=1;
	monstre.inventaire.contenu[0]=5;
}

/**
\fn void Monstre_deplacer(entity monstre)
\brief Permet de faire déplacer le monstre de manière aléatoire en fonction du chemin qu'il prend
\param monstre Entité le représentant
*/
void Monstre_deplacer(entity monstre){
	int nord, est, sud, ouest;
	int direction = 4;
	int rand_g;
	int deplacement = 0;
	
	labyrinthe_orienter(&nord, &est, &sud, &ouest, monstre);
	do{
		rand_g = rand()%direction;
	
		if(rand_g==1 && nord==1){
			printf("deplacement possible");
			deplacement = 1;
		}
		if(rand_g==2 && est==1){
			printf("deplacement possible");
			deplacement = 1;
		}
		if(rand_g==3 && sud==1){
			printf("deplacement possible");
			deplacement = 1;
		}
		if(rand_g==4 && ouest==1){
			printf("deplacement possible");
			deplacement = 1;
		}
	}while(deplacement!=1);
}

/**
\fn void Monstre_positionner(int * x, int * y, entity monstre)
\brief Permet de récupérer les positions x et y du joueur
\param x Position x du monstre (horizontal)
\param y Position y du monstre (vertical)
\param mosntre Entité le représentant
*/
void Monstre_positionner(int * x, int * y, entity monstre){
	*x = monstre.x;
	*y = monstre.y;
}
/**
\fn void Labyrinthe_orienter(int *nord, int *est, int *sud, int *ouest, entity monstre)
\brief Maj ds labyrinthe[x][y] les directions valides si XY est la place du joueur
*/
void Labyrinthe_orienter(int *nord, int *est, int *sud, int *ouest, entity monstre){
	int x, y;
	Monstre_positionner(&x, &y, monstre);
	
	*nord = 1;
	*est = 1;
	*sud = 1;
	*ouest = 1;
	
	if(labyrinthe[x][y].haut == 1)
	{
		*nord = 0;
	}
	if(labyrinthe[x][y].droite == 1)
	{
		*est = 0;
	}
	if(labyrinthe[x][y].bas == 1)
	{
		*sud = 0;
	}
	if(labyrinthe[x][y].gauche == 1)
	{
		*ouest = 0;
	}
}
