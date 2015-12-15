#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "lib.h"
#define N 12

//fwrite();

typedef struct {int etat; int contenu[20];}t_inventaire;

typedef struct {int id; int hp; int action; t_inventaire inventaire; int orientation;}entity;

typedef struct {int etat; int haut;int bas;int gauche; int droite; t_inventaire objets; entity entite;}t_salle;

t_salle labyrinthe[N][N];

entity joueur;

char control[15];
entity tab[10];


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
			if (j == 2 || i == 2)
			{
				labyrinthe[i][j].etat = 0;	
				labyrinthe[i][j].haut = 0;
				labyrinthe[i][j].bas = 0;
				labyrinthe[i][j].gauche = 0;
				labyrinthe[i][j].droite = 0;
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
			if (i == 0)
			{
				labyrinthe[i][j].haut = 1;
			}
			if (i == N-1)
			{
				labyrinthe[i][j].bas = 1;
			}
			if (j == 0)
			{
				labyrinthe[i][j].gauche = 1;
			}
			if (j == N-1)
			{
				labyrinthe[i][j].droite = 1;
			}
		}
	}
}

//void play (int choix)


int main() {

	init_couloir();
	salle_conditionner();
	init_player();
	//labyrinthe_afficher();
	Joueur_agir();
	
	

	//Jeux_Initialiser();
/*
	while (joueur.hp != 0 || )
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

