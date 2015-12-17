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
typedef struct {int etat; int contenu[50];}t_inventaire;
typedef struct {int id; char nom[30]; char description[30]; int valeur; int atk; int def; int vitesse; int hp; int heal;}t_objet;
typedef struct {int id; int hp; int action; t_inventaire inventaire; int x; int y; int orientation;}entity;
typedef struct {int etat; int haut;int bas;int gauche; int droite; t_inventaire objets; entity entite;}t_salle;
t_objet table[100];

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

void Objet_afficher(entity joueur){ //Affiche les objets de l'inventaire du joueur
	//Récupérer obj_stats
}

void Objet_afficher(t_salle labyrinthe[N][N]){ //Affiche les objets présents dans le labyrinthe
}

void Objet_utiliser(entity * joueur){	//Le joueur utilise un objet parmi ceux dans son inventaire
	int numobjet;
	printf("Quel objet voulez-vous utiliser ?\n");
	Objet_afficher(joueur);
	printf("\nDonnez un numéro correspondant à l'objet voulu : ");
	scanf("%i", &numobjet);
	if(entity.t_inventaire.id == numobjet){
		if(id)
	}
}







/**
\fn void Combattre(entity * monstre, entity * joueur)
\brief Fait combattre le joueur contre un monstre
\param monstre Entité le représentant
\param joueur Entité le représentant
*/
void Combattre(entity * monstre, entity * joueur){
	int choix=0;
	if(Rencontre(monstre,joueur) == 1){
		do{
			printf(" Menu combat !\n");
			printf("Que voulez-vous faire ?\n");
			printf("1 - Attaque\n");
			printf("2 - Attaque spéciale\n");
			printf("3 - Utiliser un objet\n");
			printf("4 - Ne rien faire");
		}while(choix!=4);
		switch(choix){
			case 1: monstre.hp -= 10; break;
			case 2: monstre.hp -= 50; break;
			case 3: Objet_utiliser(&joueur); break;
			case 4: break;
		}
	}
}

/*int main(){
	entity joueur;
	entity monstre;
	Rencontre(joueur, monstre);
	Combattre(&monstre, &joueur);
	return 0;
}*/
