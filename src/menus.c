#include <stdio.h>
#include "lib.h"
#define N 12

typedef struct {int etat; int contenu[50];}t_inventaire;
typedef struct {int id; int hp; int action; t_inventaire inventaire; int x; int y; int orientation;}entity;
typedef struct {int etat; int haut;int bas;int gauche; int droite; t_inventaire objets; entity entite;}t_salle;
t_salle labyrinthe[N][N];







void Jeu_sauver(){
	FILE * save;
	save = fopen("p1.sav", "w");
	fwrite(labyrinthe, sizeof(t_salle), sizeof(labyrinthe)/sizeof(labyrinthe[0][0]), save);
	fclose(save);
}

void Jeu_charger(){
	FILE * load;
	load = fopen("p1.sav", "w");
	fread(labyrinthe, sizeof(t_salle), sizeof(labyrinthe)/sizeof(labyrinthe[0][0]), load);
	fclose(load);
}


//Menu lors du démarrage du jeu et menu pause du jeu
void Menu(){
	FILE * charger;
	int choix;
	do{
		printf("╔═══════════════════════════════════════════════╗\n");
		printf("║          Menu principal                       ║\n");
		printf("║   1 - Commencer une nouvelle partie           ║\n");
		printf("║   2 - Sauvegarder la partie                   ║\n");
		printf("║   3 - Charger une partie                      ║\n");
		printf("║   4 - Options                                 ║\n");
		printf("║   5 - Quitter                                 ║\n");
		printf("╚═══════════════════════════════════════════════╝\n");
		printf("     ⇢ Que voulez-vous faire ?  ");
		scanf("%i", &choix);
		printf("\n");
		switch(choix){
			case 1: /*labyrinthe_disp(); Joueur_agir(); */ break; 
			case 2: Jeu_sauver(); break;
			case 3: Jeu_charger(); break;
			case 4: /*Options_afficher();*/ break;
			case 5: break;	
		}
	}while(choix != 5);
	if(choix==5)
		printf("Au revoir !\n");
}

int main(){
	Menu();
	return 0;
}