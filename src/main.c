#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//#include "Outil.h"

#define N 5


//typedef enum{};

typedef struct inventaire{int etat; int contenue[50]; struct inventaire *locker[10];}t_inventaire;

typedef struct {int id; int hp; t_inventaire inventaire; int x; int y; int orientation;}entity;

typedef struct {int etat; int haut;int bas;int gauche; int droite; t_inventaire objets; entity entite;}t_salle;

t_salle labyrinthe[N][N];
entity joueur;
entity tab[10];


//trouver les x et y du joueur
void joueurpos(int * x, int * y)
{
	*x = joueur.x;
	*y = joueur.y;
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
{//maj ds labyrinthe[x][y] les dirctions valides si XY est la place du joueur
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
	if (bCroitStrict(0,orientation,5))
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
	{printf("\nErreur mauvoais param de deplacer.\n");}
	
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
	int j = 0;
	
	printf("╔");
	for(j=0; j<N-1; j++)
	{
		printf("═╦");
	}
	printf("═╗\n");
	
	
	
	for (i=0; i<N-1; i++)
	{
		//printf("║");
		printf(" ");
		for(j=0; j<N-1; j++)
		{
			if(labyrinthe[i][j].droite == 1)
			{
				printf(" ║");
			}
			else
			{
				printf("  ");
			}
			printf(" ║\n");


			printf("╠");
			for(j=0; j<N-1; j++)
			{
				printf("═╬");
			}
			printf("═╣\n");
		}
	}
		
	
	
	printf(" ");
	if(labyrinthe[i][j].droite == 1)
	{
		printf(" ║");
	}
	else
	{
		printf("  ");
	}
	printf(" ║\n");
	
	
	printf("╚");
	for(i=0; i<N-1; i++)
	{
		printf("═╩");
	}
	printf("═╝\n");
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
				if (i == 4)
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
	
	for (i=0; i<N-1; i++)
	{
	
		for(j=0; j<N-1; j++)
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






/*
void ligne_print(int i, int j)
{
if (labyrinthe[i][j].gauche == 0)
{
printf(" ");
}
else
{
printf("|");
}
if (labyrinthe[i][j].entite.id == 1)
{
printf("▣");
}
else if (labyrinthe[i][j].etat == 0)
{
printf("□");
}
else if (labyrinthe[i][j].etat == 1)
{
printf("■");
}
if (labyrinthe[i][j].droite == 0)
{
printf(" ");
}
else
{
printf("|");
}
}
void mur_print(int i, int j)
{
if (i == 0)
{
if (labyrinthe[i][j].haut == 0)
{
printf(" ");
}
else
{
printf("_");
}
}
else
{
if (labyrinthe[i][j-1].bas == 0 && labyrinthe[i][j].haut == 0)
{
printf(" ");
}
else if (labyrinthe[i][j-1].bas == 1 && labyrinthe[i][j].haut == 0)
{
printf("⎺");
}
else if (labyrinthe[i][j-1].bas == 0 && labyrinthe[i][j].haut == 1)
{
printf("_");
}
else if (labyrinthe[i][j-1].bas == 1 && labyrinthe[i][j].haut == 1)
{
printf("=");
}
}






void affichage()
{
	int i = 0;
	int j;
	printf(" ");
	for (j=0; j<N; j++)
	{
		mur_print(i, j);
		printf(" ");
	}
	printf("\n");

	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			ligne_print(i, j);
		}
		printf("\n ");
		for (j=0; j<N; j++)
		{
			mur_print(i, j);
			printf(" ");
		}
		printf("\n");
	}
}

int deplace (int *x, int *y, char dep)
{
	if (dep == 'z' && labyrinthe[*x-1][*y].etat == 0)
	{
		labyrinthe[*x-1][*y].entite.id = 1;
		labyrinthe[*x][*y].entite.id = 0;
		return 0;
	}
	else if (dep == 'q'&& labyrinthe[*x][*y-1].etat == 0)
	{
		labyrinthe[*x][*y-1].entite.id = 1;
		labyrinthe[*x][*y].entite.id = 0;
		return 0;
	}
	else if (dep == 's'&& labyrinthe[*x][*y+1].etat == 0)
	{
		labyrinthe[*x][*y+1].entite.id = 1;
		labyrinthe[*x][*y].entite.id = 0;
		return 0;
	}
	else if (dep == 'd'&& labyrinthe[*x+1][*y].etat == 0)
	{
		labyrinthe[*x+1][*y].entite.id = 1;
		labyrinthe[*x][*y].entite.id = 0;
		return 0;
	}
	return 1;
}

int main() {
	char input;
	int x = 4;
	int y = 2;
	int a = 1;
	init_couloir();
	labyrinthe[x][y].entite.id = 1;
	affichage();
	scanf("%c", &input);
	while (input != 'q')
	{
		a = 1;
		while(a != 0)
		{
			scanf("%c", &input);
			a = deplace(&x, &y, input);
		}
		system ("clear");
		affichage();
	}
	return 0;
}
*/



int main() {

	init_couloir();
	salle_conditionner();
	labyrinthe_afficher();

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
