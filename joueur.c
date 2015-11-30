//gcc joueur.c Outil.c -o joueur

#include <stdio.h>
#include <stdlib.h>
#include "Outil.h"
#define N 5

// Structures de données 
typedef struct {int etat; int contenu[50];}t_inventaire;
typedef struct {int id; int hp; t_inventaire inventaire;}entity;
typedef struct {int etat; int haut;int bas;int gauche;int droite; t_inventaire objets; int entite;}t_salle;


//Fonctions d'initialisation
void Joueur_initialiser(entity joueur){ // Initialise les stats du joueur, peut être réutilisé plusieurs fois
	joueur.id=0;
	joueur.hp=100;
	joueur.inventaire.etat=1;
	joueur.inventaire.contenu[0]=5;
	printf("\nInitialisation : id:%i hp:%i\n", joueur.id, joueur.hp);
}

void Joueur_amorcer(){ // A utiliser seulement une fois (début de partie)
	entity joueur;
	Joueur_initialiser(joueur);
}

//Fonctions booléennes
int bPartie_finie(){ //Indique la fin de partie
	entity joueur;
	if(joueur.hp == 0){
		return 1;
	}
	return 0;
}

int bLabyrinthe_checker(t_salle labyrinthe[N][N]){ //Vérifie le contenu d'une case de la salle	
	int cellule;
	scanf("%i", &cellule);
	if(cellule == 1)
		return 1;
	return 0;
}

int bObjet(t_salle labyrinthe){ //Indique la présence ou non d'un objet au sol 
	if(bLabyrinthe_checker(labyrinthe[N][N])){
		return 1;
	}
	return 0;
}

int bMonstre(){ //Indique la présence ou non d'un monstre devant soi
	entity monstre;
	labyrinthe[N][N];
	int x; int y;
	joueurpos(&x, &y);
	if(joueur)
		return 1;
	return 0;
}

int bMur(){ //Indique la présence ou non du mur dans les 4 directions
}


//Fonctions de modification
void HP_modifier(entity joueur){ //Modification des points de vie du joueur
}


// Fonctions Joueur 
void Joueur_deplacer(entity joueur, t_salle labyrinthe[N][N]){
	int nord, est, sud, ouest;
	int var;
	// Labyrinthe_orienter(&nord, &est, &sud, &ouest);

	While(10); // Fait cette action pour 10 tours - Modification possible
	do{
		//Labyrinthe_orienter(&nord, &est, &sud, &ouest);
		printf("\nDéplacement(s) disponible(s) :\n");
		if(nord == 1)
			printf(" 1 - Nord\n");
		if(est == 1)
			printf(" 2 - Est\n");
		if(sud == 1)
			printf(" 3 - Sud\n");
		if(ouest == 1)
			printf(" 4 - Ouest\n");
		printf("Votre choix : ");
		switch(var){
			case 'z': Labyrinthe_deplacer(labyrinthe, joueur); break; //Regarder la façon dont la fonction Labyrinthe_deplacer est construite
			case 'q': Labyrinthe_deplacer(labyrinthe, joueur); break; //Changer la structure de cette fonction pour la manip du joueur
			case 's': Labyrinthe_deplacer(labyrinthe, joueur); break;
			case 'd': Labyrinthe_deplacer(labyrinthe, joueur); break;
			case 0: break;
			default: Dis("Déplacement impossible !\n");
		}
	}while(bWhile(var!=0)); /* Fait la boucle tant qu'il n'atteint pas les tours donnés. Après cela, sort du jeu 
			 Assertion failed: (zWhilE[ipWhilE]>=0), function bWhile, file Outil.c, line 1031. <- A modifier */
}

void Joueur_combattre(entity joueur){ // Fait combattre le joueur contre un monstre
	Dis("Cette fonction est encore en cours de construction. Veuillez patienter !");
}

void Joueur_agir(t_salle labyrinthe[N][N], entity joueur, entity monstre) { // Permet de faire agir le joueur pendant le tour 
	Dis("Cette fonction est encore en cours de construction. Veuillez patienter !");
	/* Boucle tour du joueur
	 Vérification de la présence d'objets au sol 
		 Si présence alors récupération de l'objet 
	 Vérification de la présence ou non d'un monstre 
		 Si présence du monstre autour de lui alors combat !
		 Perte des points de vie possible 
	 Vérfication des murs présents ou absents autour de lui 
		 Si absence du mur dans une direction alors possibilité de se déplacer 
	   Fin du tour du joueur */
	
	   
}
void Joueur_tester(int var){ // Vérification des fonctions 
	entity joueur;
	entity monstre;
	t_salle labyrinthe[N][N];
	
	do{
		printf("\nMenu :\n");
		printf(" 1 - Initialisation de départ\n");
		printf(" 2 - Faire agir le joueur\n");
		printf(" 3 - Faire déplacer le joueur\n");
		printf(" 4 - Faire combattre le joueur\n");
		printf(" 0 - Quitter\n");
		printf("Votre choix : ");
		scanf("%i", &var);
		switch(var){
			case 1: Joueur_initialiser(joueur); break;
			case 2: Joueur_agir(labyrinthe, joueur, monstre); break; 
			case 3: Joueur_deplacer(joueur, labyrinthe); break;
			case 4: Joueur_combattre(joueur); break;
			case 0: break;
			default: Dis("Ca passe pas !\n");
		}
	}while(var!=0);
	Dis("C'est tellement dommage que l'on se quitte. A bientôt ! :)\n");
}


//Programme principal
int main(){  
	int var;
	Joueur_amorcer();
	Joueur_tester(var);
	return 0;
}
