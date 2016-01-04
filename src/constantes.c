#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#define N 12


typedef struct {int etat; int contenu[20];}t_inventaire;

typedef struct {int id; int hp; int action; t_inventaire inventaire; int orientation;}entity;

typedef struct {int etat; int isvisit; int haut; int bas; int gauche; int droite; t_inventaire objet; entity entite;}t_salle;

t_salle labyrinthe[N][N];

entity joueur;
