#include "constantes.h"

/**
\file
\brief Module du labyrinthe avec ses fonctions associées
\date Décembre 2015
\author Alizée, Junior, Bastien
*/


/**
\fn void labyrinthe_orienter(int * nord, int * est, int * sud, int * ouest)
\brief Retourne où le joueur peut se déplacer selon les murs présents à l'intérieur du labyrinthe
\param nord Variable indiquant la direction du nord
\param est Variable indiquant la direction de l'est
\param sud Variable indiquant la direction du sud
\param ouest Variable indiquant la direction de l'ouest
*/
void labyrinthe_orienter(int * nord, int * est, int * sud, int * ouest)
{
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
/*
/**
\fn void labyrinthe_examiner(int x, int y, t_inventaire * quoi)
\brief Renvoie les objets présents dans le labyrinthe
\param x Variable indiquant la coordonnée verticale du labyrinthe
\param y Variable indiquant la coordonnée horizontale du labyrinthe
\param quoi Variable de type t_inventaire concernant l'objet

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
*/

/**
\fn void labyrinthe_presencer(int x, int y, entity * nord, entity * est, entity * sud, entity * ouest)
\brief Donne les informations sur les entités présentes autour d'une entité en question
\param x Variable indiquant la coordonnée verticale 
\param y Variable indiquant la coordonnée horizontale
\param nord Variable de type entity reprenant l'orientation de l'entité présente
\param est Variable de type entity reprenant l'orientation de l'entité présente
\param sud Variable de type entity reprenant l'orientation de l'entité présente
\param est Variable de type entity reprenant l'orientation de l'entité présente
/*
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
*/
/**
\fn void labyrinthe_deplacer(entity qui, int orientation)
\brief Fait déplacer une entité (orientation = [1; 2; 3; 4])
\param qui Variable de type entity permettant de désigner l'entité voulue
\param orientation Variable qui permet de situer l'orientation

/*
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


/**
\fn void init_laby()
\brief Permet d'initialiser le labyrinthe 
*/
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
		}
	}
}


/**
\fn void Laby_generator()
\brief Permet de générer un labyrinthe aléatoirement
*/
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

/**
\fn void joueurpos(int * x, int * y)
\brief Permet de récupérer les positions x et y du joueur
\param x Variable correspondant à la coordonnée verticale du joueur
\param y Variable correspondant à la coordonnée horizontale du joueur
*/
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
/**
\fn void winpos(int * x, int * y)
\brief Permet de récupérer les positions x et y de l'endroit où le joueur doit arriver pour sortir du labyrinthe
\param x Variable correspondant à la coordonnée verticale de l'arrivée
\param y Variable correspondant à la coordonnée horizontale de l'arrivée
*/
void winpos(int * x, int * y)
{
	int i, j;
	
	for (i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			if (labyrinthe[i][j].entite.id == 10)
			{
				*x = i;
				*y = j;
				printf("%i, %i", i, j);
			}
		}
	}
}


/**
\fn void labyrinthe_afficher(int carte)
\brief Affiche le labyrinthe entier sous la forme d'une carte. La variable carte est un paramètre de débogage. Si carte vaut 0, il affiche le labyrinthe en entier. Si carte vaut 1 alors le labyrinthe affiche seulement les endroits où le joueur s'est déplacé.
\param carte Variable de débogage
*/
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
				else if (labyrinthe[i][j].entite.id == 10)
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

/**
\fn void labyrinthe_disp()
\brief 
*/
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



void stat_disp(int action)
{
	int i;
	int hp = joueur.hp;
	int max = 400;
	int maction = joueur.action;
	int x, y;
	joueurpos(&x, &y);
	int orientation = labyrinthe[x][y].entite.orientation;
	hp = (100*hp/max);
	
	if (action >= 10)
	{
		printf("═PA:%i/%i══╣HP", action, maction);
	}
	else
	{
		printf("═PA:0%i/%i══╣HP", action, maction);
	}
	
	for (i=0; i<10; i++)
	{
		if (hp > 10)
		{
			hp -= 10;
			printf("█");
		}
		else if (hp < 10 && hp > 0)
		{
			hp = 0;
			printf("▓");
		}
		else
		{
			printf("░");
		}
	}
	
	printf("╠══");
	
	if (orientation == 1)
	{
		printf("N");
	}
	else if (orientation == 2)
	{
		printf("E");
	}
	else if (orientation == 3)
	{
		printf("S");
	}
	else if (orientation == 4)
	{
		printf("O");
	}
	printf("═╗\n");
}



