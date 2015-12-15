#include <stdio.h>
#define N 5

typedef struct inventaire{int etat; int contenu[50]; struct inventaire *locker[10];}t_inventaire;
typedef struct {int id; int hp; t_inventaire inventaire; int x; int y; int orientation;}entity;
typedef struct {int etat; int haut;int bas;int gauche; int droite; t_inventaire objets; entity entite;}t_salle;
t_salle labyrinthe[N][N];
entity joueur;

//ề Affiche la vie que le joueur possède
void Joueur_afficher_vie(){
	int hp_max = 350;
	int vie;
	vie = joueur.hp % hp_max;
	if(vie == hp_max || vie ){
		printf("█");
	} else if(vie ) {
		printf("▓");
	}
	if(vie <= 0 || ) {
		printf("░");
	}
}


