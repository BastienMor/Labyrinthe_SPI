#include <stdio.h>
#include <stdlib.h>
#include "Outil.h"

// Structures de données 
typedef struct {int etat; int contenu[10];}t_inventaire;
typedef struct {int id; int hp; int x,y;t_inventaire inventaire;}entity;
typedef struct {int etat; int haut;int bas;int gauche;int droite; t_inventaire objets; int entite;}t_salle;

void Combattre(entity monstre, entity joueur){ // Fait combattre le joueur contre un monstre
	Dis("Cette fonction est encore en cours de construction. Veuillez patienter !");
	int rencon;
	
	rencon = Rencontre(monstre,joueur);
	
	if(rencon == 1){
		/*Combat*/
	}
	else{
		/*On fait rien*/
	}
	
}

int Rencontre(entity monstre, entity joueur){ // Verifier la rencontre du joueur et d'un monstre
	Dis("Cette fonction est encore en cours de construction. Veuillez patienter !");
	
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
