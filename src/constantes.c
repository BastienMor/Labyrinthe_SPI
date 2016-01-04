#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#define N 12

/**
\file constantes.c
\brief Fichier contenant les différentes structures utilisées
\author Bastien, Alizée
\date Décembre 2015
\version 1.0
*/

/**
\struct t_inventaire
\brief t_inventaire est une structures utilisant une variable etat pour l'état de l'objet (présent ou non par exemple) et un tableau de 20 caractères pour le contenu de l'objet
*/
typedef struct {int etat; int contenu[20];}t_inventaire;


/**
\struct entity
\brief entity est une struture se composant d'une variable id pour l'identité de l'entité, d'une variable hp pour ses points de vie, d'une variable action pour ses points d'actions, d'une variable orientation pour son orientation et la structure t_inventaire pour contenir les différents objets que l'entité peut posséder.
*/
typedef struct {int id; int hp; int action; t_inventaire inventaire; int orientation;}entity;


/**
\struct t_salle
\brief t_salle est une structure possédant une variable etat pour l'état de la salle, une variable isvisit pour savoir si la salle du labyrinthe a été visitée par le joueur, quatre variables cardinaux pour la direction et les structures t_inventaire objets pour les objets présents dans le labyrinthe et entity pour les entités.
*/
typedef struct {int etat; int isvisit; int haut; int bas; int gauche; int droite; t_inventaire objet; entity entite;}t_salle;

t_salle labyrinthe[N][N];

entity joueur;