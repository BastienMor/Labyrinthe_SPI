#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define N 5
//typedef enum{};
typedef struct {int etat; int contenue[10];}t_inventaire;
<<<<<<< HEAD
typedef struct {int id; int hp; t_inventaire inventaire;}entity;
typedef struct {int etat; int haut;int bas;int gauche;int droite; t_inventaire objets; int entite;}t_salle;
t_salle labyrinthe[N][N];
=======

typedef struct {int id; int hp; t_inventaire inventaire;}entity;

typedef struct {int etat; int haut;int bas;int gauche;int droite; t_inventaire objets; int entite;}t_salle;

t_salle labyrinthe[N][N];



>>>>>>> 18714c622632ba8c66629be1aee453713f302491
void init_couloir ()
{
int i, j;
for (i=0; i<N; i++)
{
for (j=0; j<N; j++)
{
labyrinthe[i][j].etat = 1;
labyrinthe[i][j].droite = 0;
labyrinthe[i][j].gauche = 0;
labyrinthe[i][j].haut = 0;
labyrinthe[i][j].bas = 0;
if (j == 2)
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
if (labyrinthe[i][j].entite == 1)
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
}
void affichage()
{
int i = 0;
int j;
/*printf(" ");
for (j=0; j<N; j++)
{
mur_print(i, j);
printf(" ");
}
printf("\n");
*/
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
labyrinthe[*x-1][*y].entite = 1;
labyrinthe[*x][*y].entite = 0;
return 0;
}
else if (dep == 'q'&& labyrinthe[*x][*y-1].etat == 0)
{
labyrinthe[*x][*y-1].entite = 1;
labyrinthe[*x][*y].entite = 0;
return 0;
}
else if (dep == 's'&& labyrinthe[*x][*y+1].etat == 0)
{
labyrinthe[*x][*y+1].entite = 1;
labyrinthe[*x][*y].entite = 0;
return 0;
}
else if (dep == 'd'&& labyrinthe[*x+1][*y].etat == 0)
{
labyrinthe[*x+1][*y].entite = 1;
labyrinthe[*x][*y].entite = 0;
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
labyrinthe[x][y].entite = 1;
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
/*
int main() {
Jeux_Initialiser(##Labyrinthe, Joueur_Objet, Monstre_Objet_Liste);
while (!bPartie_finie(Joueur_Objet))
{
Joueur_Agir(#Labyrinthe, Joueur_Objet, Monstre_Objet_Liste#);
Ecran_Afficher(Labyrinthe);
if (bMonstre_Present(Monstre_Objet_Liste) && !bPartie_finie(Joueur_Objet))
{
Monstre_Agir(#Labyrinthe, Joueur_Objet, Monstre_Objet_Liste#);
Ecran_Afficher(Labyrinthe);
}
}
Gameover_Afficher();
return 0;
}
*/
