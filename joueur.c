#include <stdio.h>

/* Structures de données */
typedef struct {int etat; int contenue[10];}t_inventaire;
typedef struct {int id; int hp; t_inventaire inventaire;}entity;
typedef struct {int etat; int haut;int bas;int gauche;int droite; t_inventaire objets; int entite;}t_salle;

/* Fonctions Joueur */
void Joueur_initialiser() /* Initialise le joueur avec les données de départ */
{}

void Joueur_agir(t_salle labyrinthe, Joueur_Objet, Monstre_Objet_Liste) /* Cela donne toutes les possibilités de jouer pendant le tour donné */
{}


