#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define N 12

typedef struct {int etat; int contenu[20];}t_inventaire;

typedef struct {int id; int hp; int action; t_inventaire inventaire; int orientation;}entity;

typedef struct {int etat; int isvisit; int haut; int bas; int gauche; int droite; t_inventaire objets; entity entite;}t_salle;

t_salle labyrinthe[N][N];

entity joueur;
int id_character = 1;



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


void labyrinthe_afficher(int carte)
{
	int i;
	int j;
	
	printf("╔");
	for (i=0; i<N; i++)
	{
		printf("═══");
	}
	printf("╗\n");
	
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
				printf("╗");
			}
			else
			{
				printf("   ");
			}
		}
		printf("║\n");
	
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
			else
			{
				printf("   ");
			}
		}
		printf("║\n║");

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
				printf("╝");
			}
			else
			{
				printf("   ");
			}
		}
		printf("║\n");
	}
	
	printf("╚");
	for (i=0; i<N; i++)
	{
		printf("═══");
	}
	printf("╝\n");
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



void stat_disp(int action)
{
	int i;
	int hp = joueur.hp;
	int max = 400;
	int maction = joueur.action;
	int orientation = joueur.orientation;
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





void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}


void init_player()
{
	joueur.id = id_character;
	joueur.hp = 100;
	joueur.action = 8;
	joueur.orientation = 1;
	
	labyrinthe[4][2].entite = joueur;
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
	joueurpos(&x, &y);
	labyrinthe[x][y].isvisit = 1;
}


int Joueur_deplacer(int action){
	int nord, sud, est, ouest;
	int devant, droite, derriere, gauche;
	int fin_action = 0;
	int agir = 1;
	char bouger;
	int x, y;
	joueurpos(&x, &y);
	
	devant = labyrinthe[x][y].entite.orientation;
	if (devant == 1)
	{
		droite = 2;
		gauche = 4;
		derriere = 3;
		nord = labyrinthe[x][y].haut;
		est = labyrinthe[x][y].droite;
		sud = labyrinthe[x][y].bas;
		ouest = labyrinthe[x][y].gauche;
	}
	else if (devant == 2)
	{
		droite = 3;
		gauche = 1;
		derriere = 4;
		nord = labyrinthe[x][y].droite;
		est = labyrinthe[x][y].bas;
		sud = labyrinthe[x][y].gauche;
		ouest = labyrinthe[x][y].haut;
	}
	else if (devant == 3)
	{
		droite = 4;
		gauche = 2;
		derriere = 1;
		nord = labyrinthe[x][y].bas;
		est = labyrinthe[x][y].gauche;
		sud = labyrinthe[x][y].haut;
		ouest = labyrinthe[x][y].droite;
	}
	else if (devant == 4)
	{
		droite = 1;
		gauche = 3;
		derriere = 2;
		nord = labyrinthe[x][y].gauche;
		est = labyrinthe[x][y].haut;
		sud = labyrinthe[x][y].droite;
		ouest = labyrinthe[x][y].bas;
	}
	
	do{
		labyrinthe_disp();
		printf("╔═Déplacement(s)═disponible(s)══");
		stat_disp(action);
		if(nord != 1)
			printf("║ z - Avancer                                               ║\n");
		if(ouest != 1)
			printf("║ q - Strafé à gauche                                       ║\n");
		if(sud != 1)
			printf("║ s - Reculé                                                ║\n");
		if(est != 1)
			printf("║ d - Strafé à droite                                       ║\n");
		printf("║ c - Retour                                                ║\n");
		printf("╚═══════════════════════════════════════════════════════════╝\n\n");
		
		scanf("%c", &bouger);
		switch(bouger){
			case 'z': if(nord != 1){deplacement(devant); fin_action=1;}else{printf("Déplacement impossible !\n");} break;
			case 'q': if(ouest != 1){deplacement(gauche); fin_action=1;}else{printf("Déplacement impossible !\n");} break;
			case 's': if(sud != 1){deplacement(derriere); fin_action=1;}else{printf("Déplacement impossible !\n");} break;
			case 'd': if(est != 1){deplacement(droite); fin_action=1;}else{printf("Déplacement impossible !\n");} break;
			case 'c': agir=0; fin_action=1; break;
			default: printf("Entrée non valide\n");
		}
	}while(!fin_action);
	viderBuffer();
	return agir;
}






int tourne (int t, int x, int y)
{
	labyrinthe[x][y].entite.orientation += t;
	
	if (labyrinthe[x][y].entite.orientation > 4)
	{
		labyrinthe[x][y].entite.orientation -= 4;
	}
	else if (labyrinthe[x][y].entite.orientation < 1)
	{
		labyrinthe[x][y].entite.orientation += 4;
	}
	return labyrinthe[x][y].entite.orientation;
}


void Joueur_tourne(int action)
{
	int x, y;
	int fin_action = 0;
	char tour;
	joueurpos(&x, &y);
	int orientation = labyrinthe[x][y].entite.orientation;

	do{
		labyrinthe_disp();
		printf("╔══Sens═ou═touné═?════════");
		stat_disp(action);
		printf("║ q - Tourner à gauche                                ║\n");
		printf("║ s - Se retourner                                    ║\n");
		printf("║ d - Tourner à droite                                ║\n");
		printf("║ c - Retour                                          ║\n");
		printf("╚═════════════════════════════════════════════════════╝\n\n");
		
		scanf("%c", &tour);
		switch(tour){
			case 'q': joueur.orientation = tourne(-1, x, y); fin_action=1; break;
			case 'd': joueur.orientation = tourne(1, x, y); fin_action=1; break;
			case 's': joueur.orientation = tourne(2, x, y); fin_action=1; break;
			case 'c': fin_action=1; break;
			default: printf("Entrée non valide\n");
		}
	}while(!fin_action);
	viderBuffer();
}


void Joueur_agir() { // Permet de faire agir le joueur pendant le tour 
	int tour=0;
	
	//joueur_stats();
	int action = joueur.action;
	int x, y;
	joueurpos(&x, &y);
	int hp = joueur.hp;
	int orientation = joueur.orientation;
	int agir = 0;
	int fin_action = 0;
	char c;
	
	labyrinthe[x][y].isvisit = 1;
	
	do{
		labyrinthe_disp();
		printf("╔════Menu═D'action═════════════");
		stat_disp(action);
		printf("║ 1 - Déplacement                                          ║\n");
		printf("║ 2 - Check salle                                          ║\n");
		printf("║ 3 - Se tourné                                            ║\n");
		printf("║ 4 - Combattre                                            ║\n");
		printf("║ 5 - Carte                                                ║\n");
		printf("║ 6 - Fin de tour                                          ║\n");
		if (action == joueur.action)
			printf("║ 7 - Menu principal                                       ║\n");
		printf("╚══════════════════════════════════════════════════════════╝\n\n");
		scanf("%c", &c);
		switch(c){
			case '1': viderBuffer(); agir = Joueur_deplacer(action); break;
			case '2': break;
			case '3': viderBuffer(); agir = 0; Joueur_tourne(action); break;
			case '4': break;
			case '5': viderBuffer(); agir = 0; labyrinthe_afficher(0); break;
			case '6': fin_action = 1;break;
			case '7': if (action == joueur.action){/*Menu();*/}else{printf("NON !");} break;
			default: printf("Action non valide !\n");
		}
		action -= agir;
	}while (action > 0 && !fin_action);
}
