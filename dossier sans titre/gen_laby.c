#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define N 5
#define M 4 

typedef struct {int etat; int haut;int bas;int gauche; int droite; int entite;}t_salle;

t_salle labyrinthe[N][N];

//génération d'une grille
void Labyrinthe_initialiser()
{
	int i,j;
	int nombre=0;
	
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			labyrinthe[i][j].etat=nombre;
			labyrinthe[i][j].droite = 0;
			labyrinthe[i][j].gauche = 0;
			labyrinthe[i][j].haut = 0;
			labyrinthe[i][j].bas = 0;
			nombre++;
		}
	}
}


//affiche le labyrinthe
void Labyrinthe_afficher(){
	int i,j,k;
	
	for(i=0;i<N;i++){
		printf("\t");
		for(k=0;k<N-1;k++){
			printf("------ ");
		}
		printf("-\n\t|");
		for(j=0;j<M;j++){
			printf("  %i  ", labyrinthe[i][j].etat);
			printf("|");
			
		}
		
		printf("\n");
	}
}

int main(){
	//Labyrinthe_initialiser();
	Labyrinthe_afficher();
	
	return 0;
}
