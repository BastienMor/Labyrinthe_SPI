//gcc joueur.c Outil.c -o joueur

#include <stdio.h>
#include <stdlib.h>
#define N 5

// Structures de données 

typedef struct inventaire{int etat; int contenue[50]; struct inventaire *locker[10];}t_inventaire;

typedef struct {int id; int hp; int action; t_inventaire inventaire; int orientation;}entity;

typedef struct {int etat; int haut;int bas;int gauche; int droite; t_inventaire objets; entity entite;}t_salle;


entity joueur;

/*
//Fonctions d'initialisation
void Joueur_initialiser(entity joueur){ // Initialise les stats du joueur, peut être réutilisé plusieurs fois
	joueur.id=1;
	joueur.hp=100;
	joueur.inventaire.etat=1;
	joueur.inventaire.contenu[0]=5;
	joueur.x=0;
	joueur.y=0;
	joueur.orientation=rand()*4-1;
	printf("\nInitialisation : id:%i hp:%i\n", joueur.id, joueur.hp);
}*/

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
/*
int bLabyrinthe_checker(t_salle labyrinthe[N][N]){ //Vérifie le contenu d'une case de la salle	
	int cellule;
	//monstre=1, objet=2, mur=3;
	scanf("%i", &cellule);
	if(cellule == 1)
		return 1;
	if(cellule == 2)
		return 2;
	if(cellule == 3)
		return 3;
	return 0;
}

int bObjet(t_salle labyrinthe){ //Indique la présence ou non d'un objet au sol 
	int x; int y;
	joueurpos(&x, &y);
	if(bLabyrinthe_checker(labyrinthe[x][y]) == 2){
		return 1;
	}
	return 0;
}

int bMonstre(t_salle labyrinthe[N][N]){ //Indique la présence ou non d'un monstre devant soi
	entity monstre;
	int x; int y;
	joueurpos(&x, &y);
	if(bLabyrinthe_checker(labyrinthe[x-1][y]) ==1 || bLabyrinthe_checker(labyrinthe[x+1][y])==1 || bLabyrinthe_checker(labyrinthe[x][y-1])==1 || bLabyrinthe_checker(labyrinthe[x][y+1])==1)
		return 1;
	return 0;
}

int bMur(entity joueur, t_salle labyrinthe[N][N]){ //Indique la présence ou non du mur dans les 4 directions
	int i, x, y;
	joueurpos(&x, &y);
	for(i=1; i<=4; i++){
		joueur.orientation = i;
		if(bLabyrinthe_checker(labyrinthe[x-1][y]) ==3 || bLabyrinthe_checker(labyrinthe[x+1][y])==3 || bLabyrinthe_checker(labyrinthe[x][y-1])==3 || bLabyrinthe_checker(labyrinthe[x][y+1])==3)
			return 1;
		return 0;	
	}
}
*/

void deplacement(int direction)
{
	int x, y;
	joueurpos(&x, &y);
	
	if (direction == 1)
	{
		labyrinthe[x-1][y].entite = labyrinthe[x][y].entite;
	}
	else if (direction == 2)
	{
		labyrinthe[x][y+1].entite = labyrinthe[x][y].entite;
	}
	else if (direction == 3)
	{
		labyrinthe[x-1][y].entite = labyrinthe[x][y].entite;
	}
	else if (direction == 4)
	{
		labyrinthe[x-1][y].entite = labyrinthe[x][y].entite;
	}
	labyrinthe[x][y].entite.id = 0;
}

// Fonctions Joueur
int Joueur_deplacer(int action){
	int nord, sud, est, ouest;
	int action = 0;
	int agir = 1;
	char bouger;
	
	labyrinthe_orienter(&nord, &est, &sud, &ouest);
	
	do{
		printf("\n══Déplacement(s)═disponible(s)══PA:%i/8═\n", action);
		if(nord == 1)
			printf(" z - Avancer\n");
		if(ouest == 1)
			printf(" q - Strafé à gauche\n");
		if(sud == 1)
			printf(" s - Reculé\n");
		if(est == 1)
			printf(" d - Strafé à droite\n");
		printf(" c - Retour\n");
		
		scanf("%c", &bouger);
		switch(bouger){
			case 'z': if(nord == 1){deplacement(1); fin_action=1;}else{printf("Déplacement impossible !\n");} break;
			case 'q': if(ouest == 1){deplacement(4); fin_action=1;}else{printf("Déplacement impossible !\n");} break;
			case 's': if(sud == 1){deplacement(3); fin_action=1;}else{printf("Déplacement impossible !\n");} break;
			case 'd': if(est == 1){deplacement(2); fin_action=1;}else{printf("Déplacement impossible !\n");} break;
			case 'c': agir=0; fin_action=1; break;
			default: printf("Entré non valide\n");
		}
	}while(!fin_action);
	return agir;
}

/*
void Joueur_combattre(entity joueur){ // Fait combattre le joueur contre un monstre
	entity monstre;	
	Combattre(monstre, joueur);
}
*/
void Joueur_agir() { // Permet de faire agir le joueur pendant le tour 
	int tour=0;
	
	//joueur_stats();
	int action = joueur.action;
	int hp = joueur.hp;
	int agir = 0;
	int fin_action = 0;
	char c;
	
	do{
		labyrinthe_afficher();
		printf("════Menu═══PA:%i/══%i/══\n\n 1 - Déplacement\n 2 - Check salle\n 3 - Se tourné\n 4 - combattre\n 5 - Fin de tour\n", action, hp);
		c = getchar();
		switch(c){
			case '1': agir = Joueur_deplacer(action); break;
			case '2': break;
			case '3': break;
			case '4': break;
			case '5': fin_action = 1;break;
			default: Dis("Action non valide !\n");
		}
		action -= agir;
	}while (action > 0 && !fin_action);
	
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
	Dis(" A bientôt !\n");
}
/*

//Programme principal
int main(){  
	int var;
	Joueur_amorcer();
	Joueur_tester(var);
	return 0;
}

*/
