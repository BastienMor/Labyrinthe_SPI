#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//#include "Outil.h"

#define N 5


//typedef enum{};

typedef struct inventaire{int etat; int contenue[50]; struct inventaire *locker[10];}t_inventaire;

typedef struct {int id; int hp; int action; t_inventaire inventaire; int orientation;}entity;

typedef struct {int etat; int haut;int bas;int gauche; int droite; t_inventaire objets; entity entite;}t_salle;

char control[15];

t_salle labyrinthe[N][N];
entity joueur;
entity tab[10];
int id_character = 1;


void init_player()
{
	joueur.id = id_character;
	joueur.hp = 100;
	joueur.action = 8;
	joueur.orientation = 1;
	
	labyrinthe[4][2].entite = joueur;
}

//trouver les x et y du joueur
void joueurpos(int * x, int * y)
{
	int i, j;
	
	for (i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			if (labyrinthe[i][j].entite.id == id_character)
			{
				*x = i;
				*y = j;
			}
		}
	}
}

//génération d'une grille
void labyrinthe_initialiser()
{

}

void labyrinthe_amorcer()
{
	labyrinthe_initialiser();
}

//retourne ou l'on peut se déplacé JOUEUR UNIQUEMENT
void labyrinthe_orienter(int * nord, int * est, int * sud, int * ouest)
{//maj ds labyrinthe[x][y] les directions valides si XY est la place du joueur
	int x, y;
	joueurpos(&x, &y);
	
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



//info sur une salle
//[-1;-1] en paramettre prendra les infos sur la case du joueur.
void labyrinthe_examiner(int x, int y, t_inventaire * quoi)
{
	if (x == -1 && y == -1)
	{
		joueurpos(&x, &y);
		*quoi = labyrinthe[x][y].objets;
	}
	else
	{
		*quoi = labyrinthe[x][y].objets;
	}
}


//info sur les entité alentours d'une entité
//[-1;-1] prendra le x et y du joueur.
void labyrinthe_presencer(int x, int y, entity * nord, entity * est, entity * sud, entity * ouest)
{
	if (x == -1 && y == -1)
	{
		joueurpos(&x, &y);
		*nord = labyrinthe[x-1][y].entite;
		*ouest = labyrinthe[x][y+1].entite;
		*sud = labyrinthe[x+1][y].entite;
		*est = labyrinthe[x][y-1].entite;
	}
	else
	{
		*nord = labyrinthe[x-1][y].entite;
		*ouest = labyrinthe[x][y+1].entite;
		*sud = labyrinthe[x+1][y].entite;
		*est = labyrinthe[x][y-1].entite;
	}
}

/*
//deplace une entité (orientation = [1; 2; 3; 4])
void labyrinthe_deplacer(entity qui, int orientation)
{
	int x = qui.x;
	int y = qui.y;
	int depx = 0;
	int depy = 0;
	if (0<orientation && orientation<5)
	{
		if (orientation == 1)
		{
			depx = -1;
		}
		else if (orientation == 2)
		{
			depy = 1;
		}
		else if (orientation == 3)
		{
			depx = 1;
		}
		else
		{
			depy = -1;
		}
	}
	else
	{printf("\nErreur mauvais param de deplacer.\n");}
	
	if (labyrinthe[qui.x+depx][qui.y+depy].entite.id == 0)
	{
		labyrinthe[qui.x+depx][qui.y+depy].entite = qui;
		labyrinthe[x][y].entite.id = 0;
	}
}*/



//affiche le labyrinthe
void labyrinthe_afficher()
{
	int i;
	int j;
	
	for (i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			printf("╔");
			if(labyrinthe[i][j].haut == 1)
			{
				printf("═");
			}
			else
			{
				printf(" ");
			}
			printf("╗");
		}
		printf("\n");
	
	///////////////////////////////////////////////
	
	
		for(j=0; j<N; j++)
		{
			if(labyrinthe[i][j].gauche == 1)
			{
				printf("║");
			}
			else
			{
				printf(" ");
			}
		
			if(labyrinthe[i][j].etat == 1)
			{
				printf("■");
			}
			else if (labyrinthe[i][j].entite.id == id_character)
			{
				printf("□");
			}
			else
			{
				printf(" ");
			}
		
			if(labyrinthe[i][j].droite == 1)
			{
				printf("║");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");

	///////////////////////////////////////////////
	
		for(j=0; j<N; j++)
		{
			printf("╚");
			if(labyrinthe[i][j].bas == 1)
			{
				printf("═");
			}
			else
			{
				printf(" ");
			}
			printf("╝");
		}
		printf("\n");
	}
}


//creation d'une salle
void labyrinthe_saller()
{
	
}





void init_couloir ()
{
	int i, j;
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			labyrinthe[i][j].etat = 1;
			labyrinthe[i][j].droite = 1;
			labyrinthe[i][j].gauche = 1;
			labyrinthe[i][j].haut = 1;
			labyrinthe[i][j].bas = 1;
			if (j == 2)
			{
				labyrinthe[i][j].etat = 0;	
				labyrinthe[i][j].haut = 0;
				labyrinthe[i][j].bas = 0;
				if (i == 0)
				{
					labyrinthe[i][j].haut = 1;
				}
				if (i == N-1)
				{
					labyrinthe[i][j].bas = 1;
				}
			}
		}
	}
}





void salle_conditionner()
{

	int i, j;
	
	for (i=0; i<N; i++)
	{
	
		for(j=0; j<N; j++)
		{
			if (labyrinthe[i-1][j].bas == 1)
			{
				labyrinthe[i][j].haut = 1;
			}
			if (labyrinthe[i][j+1].gauche == 1)
			{
				labyrinthe[i][j].droite = 1;
			}
			if (labyrinthe[i+1][j].haut == 1)
			{
				labyrinthe[i][j].bas = 1;
			}
			if (labyrinthe[i][j-1].droite == 1)
			{
				labyrinthe[i][j].gauche = 1;
			}
		}
	}
}





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
		labyrinthe[x+1][y].entite = labyrinthe[x][y].entite;
	}
	else if (direction == 4)
	{
		labyrinthe[x][y-1].entite = labyrinthe[x][y].entite;
	}
	labyrinthe[x][y].entite.id = 0;
}

// Fonctions Joueur
int Joueur_deplacer(int action){
	int nord, sud, est, ouest;
	int fin_action = 0;
	int agir = 1;
	char bouger;
	
	labyrinthe_orienter(&nord, &est, &sud, &ouest);
	while(getchar() != '\n');
	
	do{
		labyrinthe_afficher();
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
			default: printf("Action non valide !\n");
		}
		action -= agir;
	}while (action > 0 && !fin_action);  
}




int main() {

	init_couloir();
	salle_conditionner();
	init_player();
	labyrinthe_afficher();
	//labyrinthe_disp();
	Joueur_agir();
	
	

	/*Jeux_Initialiser(##labyrinthe, Joueur_Objet, Monstre_Objet_Liste);

	while (!bPartie_finie(Joueur_Objet))
	{
		Joueur_Agir(#labyrinthe, Joueur_Objet, Monstre_Objet_Liste#);
		Ecran_Afficher(labyrinthe);
		if (bMonstre_Present(Monstre_Objet_Liste) && !bPartie_finie(Joueur_Objet))
		{
			Monstre_Agir(#labyrinthe, Joueur_Objet, Monstre_Objet_Liste#);
			Ecran_Afficher(labyrinthe);
		}
	}
	Gameover_Afficher();*/
	
	return 0;
}

