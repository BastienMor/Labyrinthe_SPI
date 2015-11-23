#include <stdio.h>
#define N 50

/* Structures de données */
typedef struct {int etat; int contenu[10];}t_inventaire;
typedef struct {int id; int hp; t_inventaire inventaire;}entity;
typedef struct {int etat; int haut;int bas;int gauche;int droite; t_inventaire objets; int entite;}t_salle;

/* Fonctions Joueur */
void Joueur_initialiser(entity joueur) 
{
	joueur.id=0;
	joueur.hp=100;
	joueur.inventaire.etat=1;
	joueur.inventaire.contenu[0]=5;
}

void Joueur_tester(int var){
	entity joueur;
	entity monstre;
	t_salle labyrinthe[N][N];
	switch(var){
		case 1: Joueur_initialiser(joueur); break;
		case 2: Joueur_agir(labyrinthe, joueur, monstre); break;
	}
}

void Joueur_amorcer(){
}

void Joueur_agir(t_salle labyrinthe, entity joueur, entity monstre) {
	printf("Le tour du joueur commence !\n");
}


