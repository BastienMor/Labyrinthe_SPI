#include <stdio.h>
#include <stdlib.h>
#include "Outil.h"

/* Structures de données */
typedef struct {int etat; int contenu[10];}t_inventaire;
typedef struct {int id; int hp; t_inventaire inventaire;}entity;
typedef struct {int etat; int haut;int bas;int gauche;int droite; t_inventaire objets; int entite;}t_salle;

// Fonctions Joueur 
void Joueur_deplacer(entity joueur){}
/* int nord, est, sud, ouest;
	Labyrinthe_orienter(&nord, &est, &sud, &ouest);
*/
	do{
		printf("\nDéplacements possibles :\n");
		if(nord == 1)
			printf("\n");
		printf(" 2 - Faire jouer le joueur\n");
		printf(" 0 - Quitter\n");
		printf("Votre choix (choisis bien !): ");
		scanf("%i", &var);
		switch(var){
			case 1: if(nord == 1){ 
						Dis("Déplacement possible !"), Joueur_agir(labyrinthe, joueur, monstre); } break;
			case 2: if(est == 1) { 
						Dis("Déplacement possible !"), Joueur_agir(labyrinthe, joueur, monstre); } break;
			case 3: if(sud == 1) {
						Dis("Déplacement possible !"), Joueur_agir(labyrinthe, joueur, monstre); } break;
			case 4: id(ouest == 1) {
						Dis("Déplacement possible !"), Joueur_agir(labyrinthe, joueur, monstre); } break;
			case 5: break;
			default: Dis("Déplacement impossible !");
		}
	}while(var!=0);

void Joueur_initialiser(entity joueur) /* Initialise les stats du joueur, peut être réutilisé plusieurs fois */
{
	joueur.id=0;
	joueur.hp=100;
	joueur.inventaire.etat=1;
	joueur.inventaire.contenu[0]=5;
	printf("\nInit : id:%i hp:%i\n", joueur.id, joueur.hp);
}

void Joueur_agir(t_salle labyrinthe, entity joueur, entity monstre) { /* Permet de faire agir le joueur pendant le tour */
}

void Joueur_tester(int var){ /* Vérification des fonctions publiques */
	entity joueur;
	entity monstre;
	t_salle labyrinthe;
	
	do{
		printf("\nMenu :\n");
		printf(" 1 - Initialisation de départ\n");
		printf(" 2 - Faire jouer le joueur\n");
		printf(" 0 - Quitter\n");
		printf("Votre choix (choisis bien !): ");
		scanf("%i", &var);
		switch(var){
			case 1: Joueur_initialiser(joueur); break;
			case 2: Joueur_agir(labyrinthe, joueur, monstre); break;
			case 0: break;
			default: Dis("Je t'ai dit entre 1 et 2, patate !\n");
		}
	}while(var!=0);
	Dis("C'est tellement dommage que l'on se quitte.\n");
}

void Joueur_amorcer(){ /* A utiliser seulement une fois (début de partie) */
	entity joueur;
	Joueur_initialiser(joueur);
}

int main(){
	int var;
	Joueur_amorcer();
	Joueur_tester(var);
	return 0;
}
