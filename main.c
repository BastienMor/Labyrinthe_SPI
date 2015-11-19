#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define N 5


//typedef enum{};

typedef struct {int etat; int contenue[10];}t_inventaire;


typedef struct{int etat; int haut;int bas;int gauche;int droite; t_inventaire objets;}t_salle;


t_salle labyrinthe[N][N];

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
			if (j == 3)
			{
				labyrinthe[i][j].etat = 0;
				labyrinthe[i][j].droite = 1;
				labyrinthe[i][j].gauche = 1;
				labyrinthe[i][j].haut = 0;
				labyrinthe[i][j].bas = 0;
				if (i == 0)
				{
					labyrinthe[i][j].haut = 1;
				}
				if (i == 4)
				{
					labyrinthe[i][j].bas = 1;
				}
			}
		}
	}
}


void affichage()
{
	int i, j;
	
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			if (labyrinthe[i][j].gauche = 0)
			{
				printf(" ");
			}
			else
			{
				printf("|");
			}
			
			if (labyrinthe[i][j].etat = 0)
			{
				printf("□");
			}
			if (labyrinthe[i][j].etat = 1)
			{
				printf("■");
			}
			
			if (labyrinthe[i][j].droite = 0)
			{
				printf(" ");
			}
			else
			{
				printf("|");
			}
		}
		printf("\n");
	}	
}


int main() {
	
	init_couloir();
	affichage();
	
	
    return 0;
}
