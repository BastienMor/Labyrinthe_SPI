#include "../include/constante.h"
#include "../include/module_joueur.h"
#include "../include/module_menu.h"

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




void init_laby()
{
	int i, j;
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			labyrinthe[i][j].etat = 1;
			labyrinthe[i][j].isvisit = 0;
			labyrinthe[i][j].droite = 1;
			labyrinthe[i][j].gauche = 1;
			labyrinthe[i][j].haut = 1;
			labyrinthe[i][j].bas = 1;
			labyrinthe[i][j].entite.id = 0;
			labyrinthe[i][j].objet.etat = 0;
		}
	}
}




void Laby_generator()
{
	int cycle = 1;
	int a, b;
	int invert = 0;
	int nb = 0;
	
	srand(time(NULL));
	labyrinthe[rand()%N][rand()%N].etat = 0;
	
	while(nb < 143)
	{
	
		if(cycle == 1)
		{
			a = rand()%N;
			b = rand()%N;
			
			if(labyrinthe[a][b].etat + labyrinthe[a][b+1].etat == 1 && b+1 != N)
			{
				labyrinthe[a][b].etat = 0;
				labyrinthe[a][b].droite = 0;
				labyrinthe[a][b+1].gauche = 0;
				labyrinthe[a][b+1].etat = 0;
				
				invert = 1;
				nb++;
			}
		}
		
		if(cycle == -1)
		{
			a = rand()%N;
			b = rand()%N;
			
			if(labyrinthe[a][b].etat + labyrinthe[a+1][b].etat == 1 && a+1 != N)
			{
				labyrinthe[a][b].etat = 0;
				labyrinthe[a][b].bas = 0;
				labyrinthe[a+1][b].haut = 0;
				labyrinthe[a+1][b].etat = 0;
				
				invert = 1;
				nb++;
			}
		}
		
		if(invert == 1)
		{
			cycle = -cycle;
			invert = 0;
		}
	}
}


//trouver les x et y du joueur
void joueurpos(int * x, int * y)
{
	int i, j;
	
	for (i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			if (labyrinthe[i][j].entite.id == 1)
			{
				*x = i;
				*y = j;
			}
		}
	}
}

//trouver les x et y du flag d'arrivé
void winpos(int * x)
{
	int i;
	
	for (i=0; i<N; i++)
	{
		if (labyrinthe[i][11].objet.etat == 10)
		{
			*x = i;
		}
	}
}




void labyrinthe_afficher(int carte)
{
	int i;
	int j;
	
	printf("\033[0;43;37m╔");
	for (i=0; i<N; i++)
	{
		printf("════");
	}
	printf("╗\033[0;40;37m\n\033[0;43;37m");
	
	for (i=0; i<N; i++)
	{
		printf("║");
		for(j=0; j<N; j++)
		{
			if(labyrinthe[i][j].isvisit == 1 || labyrinthe[i][j].isvisit == carte)
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
				printf("╗ ");
			}
			else
			{
				printf("    ");
			}
		}
		printf("║\033[0;40;37m\n\033[0;43;37m");
	
	///////////////////////////////////////////////
	
	
		printf("║");
		for(j=0; j<N; j++)
		{
			if(labyrinthe[i][j].isvisit == 1 || labyrinthe[i][j].isvisit == carte)
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
				else if (labyrinthe[i][j].entite.id == 1)
				{
					printf("\033[0;43;32m■\033[0;43;37m");
				}
				else if (labyrinthe[i][j].objet.etat == 10)
				{
					printf("\033[0;43;34mX\033[0;43;37m");
				}
				else
				{
					printf(" ");
				}
		
				if(labyrinthe[i][j].droite == 1)
				{
					printf("║ ");
				}
				else
				{
					printf("  ");
				}
			}
			else
			{
				printf("    ");
			}
		}
		printf("║\033[0;40;37m\n\033[0;43;37m║");

	///////////////////////////////////////////////
	
		for(j=0; j<N; j++)
		{
			if(labyrinthe[i][j].isvisit == 1 || labyrinthe[i][j].isvisit == carte)
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
				printf("╝ ");
			}
			else
			{
				printf("    ");
			}
		}
		printf("║\033[0;40;37m\n\033[0;43;37m");
	}
	
	printf("╚");
	for (i=0; i<N; i++)
	{
		printf("════");
	}
	printf("╝\033[0;40;37m\n");
}


void labyrinthe_disp()
{
	int x, y, i, j, a;
	joueurpos(&x, &y);
	
	printf("\n\n\n╔══════════════════════════════════════════════════════════╗\n");//14
	int orientation = labyrinthe[x][y].entite.orientation;
	
	if (orientation == 1)
	{
		for(a=0; a<10; a++)
		{
			if (labyrinthe[x][y].haut == 0)
			{
				if(labyrinthe[x-1][y].gauche == 1)
				{
					printf("║ ■■■■■■■■■║");
				}
				else
				{
					printf("║ _________║");
				}
			
				if (labyrinthe[x-1][y].haut == 0)
				{
					if (labyrinthe[x-2][y].gauche == 1)
					{
						printf("■■■■■■■║");
					}
					else
					{
						printf("_______║");
					}
			
					if (labyrinthe[x-2][y].haut == 1)
					{
						printf("■■■■■■■■■■■■■■■■■■■■");
					}
					else
					{
						printf("____________________");
					}
			
					if (labyrinthe[x-2][y].droite == 1)
					{
						printf("║■■■■■■■");
					}
					else
					{
						printf("║_______");
					}
				}
				else
				{
					printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
				}
			
				if (labyrinthe[x-1][y].droite == 1)
				{
					printf("║■■■■■■■■■ ║\n");
				}
				else
				{
					printf("║_________ ║\n");
				}
			}
			else
			{
				printf("║ ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ ║\n");
			}
		}
		printf("╚══════════════════════════════════════════════════════════╝\n\n");
	}
	else if (orientation == 2)
	{
		for(a=0; a<10; a++)
		{
			if (labyrinthe[x][y].droite == 0)
			{
				if(labyrinthe[x][y+1].haut == 1)
				{
					printf("║ ■■■■■■■■■║");
				}
				else
				{
					printf("║ _________║");
				}
			
				if (labyrinthe[x][y+1].droite == 0)
				{
					if (labyrinthe[x][y+2].haut == 1)
					{
						printf("■■■■■■■║");
					}
					else
					{
						printf("_______║");
					}
			
					if (labyrinthe[x][y+2].droite == 1)
					{
						printf("■■■■■■■■■■■■■■■■■■■■");
					}
					else
					{
						printf("____________________");
					}
			
					if (labyrinthe[x][y+2].bas == 1)
					{
						printf("║■■■■■■■");
					}
					else
					{
						printf("║_______");
					}
				}
				else
				{
					printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
				}
			
				if (labyrinthe[x][y+1].bas == 1)
				{
					printf("║■■■■■■■■■ ║\n");
				}
				else
				{
					printf("║_________ ║\n");
				}
			}
			else
			{
				printf("║ ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ ║\n");
			}
		}
		printf("╚══════════════════════════════════════════════════════════╝\n\n");
	}
	else if (orientation == 3)
	{
		for(a=0; a<10; a++)
		{
			if (labyrinthe[x][y].bas == 0)
			{
				if(labyrinthe[x+1][y].droite == 1)
				{
					printf("║ ■■■■■■■■■║");
				}
				else
				{
					printf("║ _________║");
				}
			
				if (labyrinthe[x+1][y].bas == 0)
				{
					if (labyrinthe[x+2][y].droite == 1)
					{
						printf("■■■■■■■║");
					}
					else
					{
						printf("_______║");
					}
			
					if (labyrinthe[x+2][y].bas == 1)
					{
						printf("■■■■■■■■■■■■■■■■■■■■");
					}
					else
					{
						printf("____________________");
					}
			
					if (labyrinthe[x+2][y].gauche == 1)
					{
						printf("║■■■■■■■");
					}
					else
					{
						printf("║_______");
					}
				}
				else
				{
					printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
				}
			
				if (labyrinthe[x+1][y].gauche == 1)
				{
					printf("║■■■■■■■■■ ║\n");
				}
				else
				{
					printf("║_________ ║\n");
				}
			}
			else
			{
				printf("║ ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ ║\n");
			}
		}
		printf("╚══════════════════════════════════════════════════════════╝\n\n");
	}
	else if (orientation == 4)
	{
		for(a=0; a<10; a++)
		{
			if (labyrinthe[x][y].gauche == 0)
			{
				if(labyrinthe[x][y-1].bas == 1)
				{
					printf("║ ■■■■■■■■■║");
				}
				else
				{
					printf("║ _________║");
				}
			
				if (labyrinthe[x][y-1].gauche == 0)
				{
					if (labyrinthe[x][y-2].bas == 1)
					{
						printf("■■■■■■■║");
					}
					else
					{
						printf("_______║");
					}
			
					if (labyrinthe[x][y-2].gauche == 1)
					{
						printf("■■■■■■■■■■■■■■■■■■■■");
					}
					else
					{
						printf("____________________");
					}
			
					if (labyrinthe[x][y-2].haut == 1)
					{
						printf("║■■■■■■■");
					}
					else
					{
						printf("║_______");
					}
				}
				else
				{
					printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
				}
			
				if (labyrinthe[x][y-1].haut == 1)
				{
					printf("║■■■■■■■■■ ║\n");
				}
				else
				{
					printf("║_________ ║\n");
				}
			}
			else
			{
				printf("║ ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ ║\n");
			}
		}
		printf("╚══════════════════════════════════════════════════════════╝\n\n");
	}
}

