/* Mise en oeuvre contigue d'une liste d'entiers */
#define TAILLE_MAX 100
#include<stdio.h>
#include<stdlib.h>

/* Déclaration du type t_element */
typedef struct element{entity entite; struct element * precedent; struct element * suivant;}t_element;
/* Déclaration des indices de queue et d'élément courant */
t_element * flag;
t_element * elem;

void init_liste(void)
/* Initialise la liste à vide */
{	
	flag = malloc(sizeof(t_element));
	flag->suivant = flag;
	flag->precedent = flag;
	elem = flag;
}

int liste_vide(void)
/* Rend vrai si la liste est vide, faux sinon */
{	
	return (flag->suivant == flag);
}

int hors_liste(void)
/* Rend vrai si l'elt courant est hors de la liste, faux sinon */
{	
	return(elem == flag);
}

void entite_ajouter(entity entite_nouv)
{
	t_element * nouv;
	
	if(liste_vide()||!hors_liste())
	{
		nouv = malloc(sizeof(t_element));
		nouv->suivant = elem->suivant;
		nouv->precedent = elem;
		elem->suivant->precedent = nouv;
		elem->suivant = nouv;
		elem = nouv;
		elem->entite = entite_nouv;
	}
}

void entite_suprimer()
{
	t_element * x;
	
	if(!hors_liste())
	{
		elem->suivant->precedent = elem->precedent;
		elem->precedent->suivant = elem->suivant;
		x = elem;
		precedent();
		free(x);
	}
}

void entite_joueur(entity * joueur)
{
	if (!liste_vide)
	{
		en_tete();
		*joueur = elem->entite;
	}
}



void en_tete(void)
/* Positionne en tete de la liste */
{	
	if(!liste_vide()) 
		elem = flag->suivant;
}

void en_queue(void)
/* Positionne en queue de la liste */
{	
	if(!liste_vide())
		elem = flag->precedent;
}

void precedent(void)
/* Positionne sur l'elt precedent*/
{	
	if(!hors_liste()) 
		elem = flag->precedent;
}

void suivant(void)
/* Positionne sur l'elt suivant*/
{	
	if(!hors_liste()) 
		elem = elem->suivant;
}

void valeur_elt(int* v)
/* Renvoie dans e la veleur de l'elt courant */
{	
	if(!hors_liste()) 
		*v = elem->valeur;
}

void modif_elt(int v)
/* Affecte v à l'elt courant */
{	
	if(!hors_liste()) 
		elem->valeur = v;
}

void oter_elt(void)
/* Supprime l'elt courant et positionne sur le precedent */
{
	t_element * x;
	if(!hors_liste())
	{
		elem->suivant->precedent = elem->precedent;
		elem->precedent->suivant = elem->suivant;
		x = elem;
		precedent();
		free(x);
	}
}

void ajout_droit(int v)
/* Ajoute v a droite de l'elt courant */
{	
	t_element * nouv;
	
	if(liste_vide()||!hors_liste())
	{
		nouv = malloc(sizeof(t_element));
		nouv->suivant = elem->suivant;
		nouv->precedent = elem;
		elem->suivant->precedent = nouv;
		elem->suivant = nouv;
		elem = nouv;
		elem->valeur = v;
	}
}

void ajout_gauche(int v)
/* Ajoute v a gauche de l'elt courant */
{	
	t_element * nouv;
	
	if(liste_vide()||!hors_liste())
	{
		nouv = malloc(sizeof(t_element));
		nouv->suivant = elem->precedent;
		nouv->precedent = elem;
		elem->precedent->suivant = nouv;
		elem->precedent = nouv;
		elem = nouv;
		elem->valeur = v;
	}
}
