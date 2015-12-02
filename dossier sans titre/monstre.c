#include <stdio.h>
#include <stdlib.h>
#include "Outil.h"
#include <time.h>

typedef struct {int etat; int contenu[10];}t_inventaire;
typedef struct {int id; int hp; int x,y;t_inventaire inventaire;}entity;
typedef struct {int etat; int haut;int bas;int gauche;int droite; t_inventaire objets; int entite;}t_salle;

void Monstre_initialiser(entity monstre) // Initialise les stats du monstre, peut Ãªtre rÃ©utilisÃ© plusieurs fois
{
	monstre.id=0;
	monstre.hp=100;
	monstre.x = 0;
	monstre.y=0;
	monstre.inventaire.etat=1;
	monstre.inventaire.contenu[0]=5;
}

void Monstre_deplacer(entity monstre){
	int nord, est, sud, ouest;
	int direction = 4;
	int rand_g;
	int deplacement = 0;
	
	/*nord=1;
	est=1;
	sud=1;
	ouest=0;*/
	
	labyrinthe_orienter(&nord, &est, &sud, &ouest, monstre);
	
	While(10); // Fait cette action pour 10 tours - Modification possible
	do{
		rand_g = (rand()%direction) + 1;;
	
		if(rand_g==1 && nord==1){
			printf("deplacement possible au nord\n");
			if(est==1) printf("deplacement possible aussi a l'est\n");
			if(ouest==1) printf("deplacement possible aussi a l'ouest\n");
			if(sud==1) printf("deplacement possible aussi au sud\n");
			deplacement = 1;
		}
		if(rand_g==2 && est==1){
			printf("deplacement possible a l'est\n");
			if(nord==1) printf("deplacement possible aussi au nord\n");
			if(ouest==1) printf("deplacement possible aussi a l'ouest\n");
			if(sud==1) printf("deplacement possible aussi au sud\n");
			deplacement = 1;
		}
		if(rand_g==3 && sud==1){
			printf("deplacement possible au sud\n");
			if(est==1) printf("deplacement possible aussi a l'est\n");
			if(ouest==1) printf("deplacement possible aussi a l'ouest\n");
			if(nord==1) printf("deplacement possible aussi au nord\n");
			deplacement = 1;
		}
		if(rand_g==4 && ouest==1){
			printf("deplacement possible a l'ouest\n");
			if(nord==1) printf("deplacement possible aussi au nord\n");
			if(est==1) printf("deplacement possible aussi a l'est\n");
			if(sud==1) printf("deplacement possible aussi au sud\n");
			deplacement = 1;
		}
	}while(bWhile(deplacement!=1)); /* Fait la boucle tant qu'il n'atteint pas les tours donnÃ©s. AprÃšs cela, sort du jeu 
			 Assertion failed: (zWhilE[ipWhilE]>=0), function bWhile, file Outil.c, line 1031. <- A modifier */
}

void monstrepos(int * x, int * y, entity monstre)
{
	*x = monstre.x;
	*y = monstre.y;
}


