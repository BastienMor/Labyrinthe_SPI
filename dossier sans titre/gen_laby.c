#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "monstre.h"

#define N 15
#define M 12 

t_salle labyrinthe[N][M];

/**
\file gen_laby.c
\brief Génération de labyrinthe
\author Junior
\date Décembre 2015
*/

/**
\fn void Labyrinthe_initialiser
\brief Génère un labyrinthe
*/
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
		for(k=0;k<M;k++){
			printf("+---");
			if(k==M-1) printf("+");
		}
		printf("\n\t|");
		for(j=0;j<M;j++){
			
			if(labyrinthe[i][j].etat>=0 && labyrinthe[i][j].etat<=9){
				printf(" %i ", labyrinthe[i][j].etat);
			}
			else if(labyrinthe[i][j].etat>9 && labyrinthe[i][j].etat<=99){
				printf(" %i", labyrinthe[i][j].etat);
			}
			else{
				printf("%i", labyrinthe[i][j].etat);
			}
			printf("|");	
		}
		
		printf("\n");
	}
	
}

void Labyrinthe_afficher2(int ligne){
	int i,j,k;
	
	for(i=0;i<N;i++){
		printf("\t");
		for(k=0;k<M;k++){
			printf("+---");
			if(k==M-1) printf("+");
		}
		if(i == ligne) printf("\n\t ");
		else printf("\n\t|");
		for(j=0;j<M;j++){
		
			if(i == ligne){
				if(labyrinthe[i][j].etat>=0 && labyrinthe[i][j].etat<=9){
					printf(" %i ", labyrinthe[i][j].etat);
				}
				else if(labyrinthe[i][j].etat>9 && labyrinthe[i][j].etat<=99){
					printf(" %i", labyrinthe[i][j].etat);
				}
				else{
					printf("%i", labyrinthe[i][j].etat);
				}
				printf(" ");
			}
			else{
				if(labyrinthe[i][j].etat>=0 && labyrinthe[i][j].etat<=9){
					printf(" %i ", labyrinthe[i][j].etat);
				}
				else if(labyrinthe[i][j].etat>9 && labyrinthe[i][j].etat<=99){
					printf(" %i", labyrinthe[i][j].etat);
				}
				else{
					printf("%i", labyrinthe[i][j].etat);
				}
				if(i == ligne) printf(" ");
				else printf("|");
			}	
		}
		
		printf("\n");
	}
	
}

int ligne_connaitre(int a){
	int i,j;
	
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			if(labyrinthe[i][j].etat == a) return i;
		}
	}
	return 0;
}

int colonne_connaitre(int a){
	int i,j;
	
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			if(labyrinthe[i][j].etat == a) return j;
		}
	}
	return 0;
}

void remplacer_ligne(int a,int ligne_a, int colonne_a){
	int i,j;
	
	for(j=colonne_a-1; j>=0; j--){
		labyrinthe[ligne_a][j].etat= a;
	}
	for(j=colonne_a+1; j<M; j++){
		labyrinthe[ligne_a][j].etat= a;
	}
	
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			if(labyrinthe[i][j].etat != labyrinthe[ligne_a][colonne_a].etat){
				labyrinthe[i][j].etat = 0;
			}
		}
	}
}

int remplacer_nb(int ligne, int colonne){
	labyrinthe[ligne][colonne].etat= 1;
	return labyrinthe[ligne][colonne].etat; 
}

void placement_monstre(int ligne, entity monstre){
	labyrinthe[ligne][0].etat= 99;	
}

int main(){
	int nb_choisi;
	int ligne, colonne;
	entity monstre;
	
	Monstre_initialiser(monstre);
	
	Labyrinthe_initialiser();
	Labyrinthe_afficher();
	
	printf("\nChoisir un nombre\n");
	scanf("%i",&nb_choisi);
	
	ligne = ligne_connaitre(nb_choisi);
	colonne = colonne_connaitre(nb_choisi);
	
	nb_choisi=remplacer_nb(ligne, colonne);
	remplacer_ligne(nb_choisi,ligne,colonne);
	
	placement_monstre(ligne, monstre);
	
	monstre.x = ligne;
	monstre.y=0;
	
	Labyrinthe_afficher2(ligne);
	
	return 0;
}
