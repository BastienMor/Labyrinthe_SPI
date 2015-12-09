#define TAILLE_MAX 100
#include<stdio.h>
#include<stdlib.h>

/**
\file liste_ptr.c
\brief Mise en oeuvre par pointeurs d'une liste d'entites
\author Bastien
\date Décembre 2015
*/

/* Déclaration du type t_element */
typedef struct element{entity entite; struct element * precedent; struct element * suivant;}t_element;
/* Déclaration des indices de flag et d'élément courant */
t_element * flag;
t_element * elem;


/**
\fn void init_liste(void)
\brief Initialise la liste à vide
*/
void init_liste(void){	
	flag = malloc(sizeof(t_element));
	flag->suivant = flag;
	flag->precedent = flag;
	elem = flag;
}

/**
\fn int liste_vide(void)
\brief Rend vrai si la liste est vide, faux sinon
\return 1 si le suivant de flag est identique à lui-même 0 sinon
*/
int liste_vide(void)
{	
	return (flag->suivant == flag);
}

/**
\fn int hors_liste(void)
\brief Rend vrai si l'elt courant est hors de la liste, faux sinon
\return 1 si elem est identique à flag 0 sinon
*/
int hors_liste(void){	
	return(elem == flag);
}

/**
\fn void entite_ajouter(entity entite_nouv)
\brief Ajoute une entité à la liste
\param entite_nouv Correspond à la variable qui va être ajouté de type entity
*/
void entite_ajouter(entity entite_nouv){
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

/**
\fn void entite_supprimer(void)
\brief Supprime une entité
*/
void entite_supprimer()
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

/**
\fn void entite_joueur(entity * joueur)
\brief Positionne l'élément courant sur l'entité joueur
\param joueur Variable de type entity
*/
void entite_joueur(entity * joueur)
{
	if (!liste_vide)
	{
		en_tete();
		*joueur = elem->entite;
	}
}

/**
\fn void en_tete(void)
\brief Positionne en tête de liste l'élément courant
*/
void en_tete(void){	
	if(!liste_vide()) 
		elem = flag->suivant;
}
/**
\fn void en_queue(void)
\brief Positionne en queue de liste l'élément courant
*/
void en_queue(void){	
	if(!liste_vide())
		elem = flag->precedent;
}

/**
\fn void precedent(void)
\brief Positionne sur l'élément précédent
*/
void precedent(void){	
	if(!hors_liste()) 
		elem = flag->precedent;
}

/**
\fn void suivant(void)
\brief Positionne sur l'élément suivant
*/
void suivant(void){	
	if(!hors_liste()) 
		elem = elem->suivant;
}
/**
\fn void valeur_elt(int*v)
\brief Renvoie dans la variable v la valeur de l'élément courant
\param v Variable de type int qui est modifié en donnant la valeur de l'élément courant
*/
void valeur_elt(int* v){	
	if(!hors_liste()) 
		*v = elem->valeur;
}
/**
\fn void modif_elt(int v)
\brief Affecte la variable v à l'élément courant
\param v Variable de type int qui est affectée à l'élément courant
*/
void modif_elt(int v){	
	if(!hors_liste()) 
		elem->valeur = v;
}
/**
\fn void oter_elt(void)
\brief Supprime l'élément courant et positionne sur l'élément précédent
*/
void oter_elt(void){
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
/**
\fn void ajout_droit(int v)
\brief Ajoute une novelle structure et sa valeur v à droite de l'élément courant
\param v Valeur de la nouvelle structure
*/
void ajout_droit(int v){	
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
/**
\fn void ajout_gauche(int v)
\brief Ajoute une nouvelle structure et sa valeur v à gauche de l'élément courant
\param v Valeur de la nouvelle structure
*/
void ajout_gauche(int v){	
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
