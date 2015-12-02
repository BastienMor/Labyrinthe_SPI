#include <stdio.h>
#include <stdlib.h>

typedef struct {int id; char nom[30]; char description[30]; int valeur; int atk; int def; int vitesse; int hp; int heal;}t_objet;

t_objet table[100];

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

void objet_stats(int i)
{
	printf("	ID : %i\n", table[i].id);
	printf("	Nom : %s\n", table[i].nom);
	printf("	Description : %s\n", table[i].description);
	printf("	Valeur : %i$\n", table[i].valeur);
	printf("	ATK : %i\n", table[i].atk);
	printf("	DEF : %i\n", table[i].def);
	printf("	VITESSE = %i\n", table[i].vitesse);
	printf("	HP : %i\n", table[i].hp);
	printf("	heal : %i\n", table[i].heal);
	printf("___________________\n");
}

int main(){

	int i = 0;

	FILE *obj;
	obj = fopen("item.txt", "r");
	
	t_objet read;
	
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
	
	fclose(obj);
	
	return 0;
}