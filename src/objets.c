#include <stdio.h>
#include <stdlib.h>

/**
\file objets.c
\brief Lecture des fichiers contenant les différents éléments du jeu
\date Décembre 2015
\author Bastien
*/


typedef struct {int id; char nom[30]; char description[30]; int valeur; int atk; int def; int vitesse; int hp; int heal;}t_objet;
t_objet table[100];
char control[15];
/**
\fn void lire_chaine(FILE * obj, char chaine[30])
\brief Permet de lire une chaîne de caractères terminée par le marqueur @
\param obj Variable de type FILE permettant de lire un fichier
\param chaine[30] tableau de caractères permettant de lire une chaine de caractères
*/
void lire_chaine(FILE * obj, char chaine[30])
{
	char c;
	int a = 0;
	
	do{
	fscanf(obj, "%c", &c);
		
		if (c != '@')
		{
			chaine[a] = c;
		}
	a++;
	}while (c != '@');
}
/**
\fn void objet_stats(int i)
\brief Affiche les statistiques de l'objet en question
\param i Correspond à l'indice du tableau contenant les informations sur l'objet
*/
void objet_stats(int i)
{
	printf("╔════════════════════════════════════════════════════\n║	ID : %i\n", table[i].id);
	printf("║	Nom : %s\n", table[i].nom);
	printf("║	Description : %s\n", table[i].description);
	printf("║	Valeur : %i$\n", table[i].valeur);
	printf("║	ATK : %i\n", table[i].atk);
	printf("║	DEF : %i\n", table[i].def);
	printf("║	VITESSE = %i\n", table[i].vitesse);
	printf("║	HP : %i\n", table[i].hp);
	printf("║	heal : %i\n", table[i].heal);
	printf("╚════════════════════════════════════════════════════\n");
}
/**
\fn void ctrl_disp(void)
\brief Affiche les commandes que l'utilisateur utilise pour jouer au jeu
*/
void ctrl_disp()
{
	printf("╔════════════════════════════════════════════════════\n║	Avancé / Haut : %c\n", control[0]);
	printf("║	Reculé / Bas : %c\n", control[2]);
	printf("║	Gauche : %c\n", control[1]);
	printf("║	Droite : %c\n", control[3]);
	printf("║	Rotation Gauche : %c\n", control[4]);
	printf("║	Rotation Droite : %c\n", control[5]);
	printf("║	Inventaire : %c\n", control[6]);
	printf("║	Valider : %c\n", control[7]);
	printf("║	Retour / Menu : %c\n", control[8]);
	printf("╚════════════════════════════════════════════════════\n");
}


int main(){

	int i = 0;
	char charact;

	FILE *obj;
	obj = fopen("item.txt", "r");
	FILE *ctrl;
	ctrl = fopen("control.txt", "r");
	
	do{
		fscanf(obj, "%i", &table[i].id);
		lire_chaine(obj, table[i].nom);
		lire_chaine(obj, table[i].description);
		fscanf(obj, "%i\n", &table[i].valeur);
		fscanf(obj, "%i\n", &table[i].atk);
		fscanf(obj, "%i\n", &table[i].def);
		fscanf(obj, "%i\n", &table[i].vitesse);
		fscanf(obj, "%i\n", &table[i].hp);
		fscanf(obj, "%i\n", &table[i].heal);
		
		objet_stats(i);
		
		i++;
	}while (!feof(obj));
	
	i = 0;
	
	do{

		fscanf(ctrl, "%c", &charact);
		if (charact != '@')
		{
			control[i] = charact;
		}
		
		i++;
	}while (charact != '@');
	
	ctrl_disp();
	
	fclose(obj);
	fclose(ctrl);
	
	return 0;
}
