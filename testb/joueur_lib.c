#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define N 7

typedef struct inventaire{int etat; int contenue[20]; struct inventaire *locker[10];}t_inventaire;

typedef struct {int id; int hp; int action; t_inventaire inventaire; int orientation;}entity;

typedef struct {int etat; int haut;int bas;int gauche; int droite; t_inventaire objets; entity entite;}t_salle;

t_salle labyrinthe[N][N];
entity joueur;

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
		printf("\n══Déplacement(s)═disponible(s)══PA:%i/8═══%i\n", action, devant);
		if(nord != 1)
			printf(" z - Avancer\n");
		if(ouest != 1)
			printf(" q - Strafé à gauche\n");
		if(sud != 1)
			printf(" s - Reculé\n");
		if(est != 1)
			printf(" d - Strafé à droite\n");
		printf(" c - Retour\n");
		
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






void tourne (int t, int x, int y)
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
}


void Joueur_tourne(int action)
{
	int x, y;
	int fin_action = 0;
	char tour;
	joueurpos(&x, &y);

	do{
		labyrinthe_disp();
		printf("\n══Sens═ou═touné═?══PA:%i/8═\n", action);
		printf(" q - Tourner à gauche\n");
		printf(" s - Se retourner\n");
		printf(" d - Tourner à droite\n");
		printf(" c - Retour\n");
		
		scanf("%c", &tour);
		switch(tour){
			case 'q': tourne(-1, x, y); fin_action=1; break;
			case 'd': tourne(1, x, y); fin_action=1; break;
			case 's': tourne(2, x, y); fin_action=1; break;
			case 'c': fin_action=1; break;
			default: printf("Entrée non valide\n");
		}
	}while(!fin_action);
	viderBuffer();
	labyrinthe_disp();
}


void Joueur_agir() { // Permet de faire agir le joueur pendant le tour 
	int tour=0;
	
	//joueur_stats();
	int action = joueur.action;
	int hp = joueur.hp;
	int orientation = joueur.orientation;
	int agir = 0;
	int fin_action = 0;
	char c;
	
	do{
		labyrinthe_afficher();
		printf("════Menu═══PA:%i/══%i/══\n\n 1 - Déplacement\n 2 - Check salle\n 3 - Se tourné\n 4 - combattre\n 5 - Fin de tour\n", action, hp);
		scanf("%c", &c);
		switch(c){
			case '1': viderBuffer(); agir = Joueur_deplacer(action); break;
			case '2': break;
			case '3': viderBuffer(); agir = 0; Joueur_tourne(action); break;
			case '4': break;
			case '5': fin_action = 1;break;
			default: printf("Action non valide !\n");
		}
		action -= agir;
	}while (action > 0 && !fin_action);  
}



