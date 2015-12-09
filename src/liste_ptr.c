#define TAILLE_MAX 100
#include<stdio.h>
#include<stdlib.h>

/**
\file liste_ptr.c
\brief Mise en oeuvre par pointeurs d'une liste d'entites
\author Bastien
\date D�cembre 2015
*/

/* D�claration du type t_element */
typedef struct element{entity entite; struct element * precedent; struct element * suivant;}t_element;
/* D�claration des indices de flag et d'�l�ment courant */
t_element * flag;
t_element * elem;


/**
\fn void init_liste(void)
\brief Initialise la liste � vide
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
\return 1 si le suivant de flag est identique � lui-m�me 0 sinon
*/
int liste_vide(void)
{	
	return (flag->suivant == flag);
}

/**
\fn int hors_liste(void)
\brief Rend vrai si l'elt courant est hors de la liste, faux sinon
\return 1 si elem est identique � flag 0 sinon
*/
int hors_liste(void){	
	return(elem == flag);
}

/**
\fn void entite_ajouter(entity entite_nouv)
\brief Ajoute une entit� � la liste
\param entite_nouv Correspond � la variable qui va �tre ajout� de type entity
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
\brief Supprime une entit�
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
\brief Positionne l'�l�ment courant sur l'entit� joueur
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
\brief Positionne en t�te de liste l'�l�ment courant
*/
void en_tete(void){	
	if(!liste_vide()) 
		elem = flag->suivant;
}
/**
\fn void en_queue(void)
\brief Positionne en queue de liste l'�l�ment courant
*/
void en_queue(void){	
	if(!liste_vide())
		elem = flag->precedent;
}

/**
\fn void precedent(void)
\brief Positionne sur l'�l�ment pr�c�dent
*/
void precedent(void){	
	if(!hors_liste()) 
		elem = flag->precedent;
}

/**
\fn void suivant(void)
\brief Positionne sur l'�l�ment suivant
*/
void suivant(void){	
	if(!hors_liste()) 
		elem = elem->suivant;
}
/**
\fn void valeur_elt(int*v)
\brief Renvoie dans la variable v la valeur de l'�l�ment courant
\param v Variable de type int qui est modifi� en donnant la valeur de l'�l�ment courant
*/
void valeur_elt(int* v){	
	if(!hors_liste()) 
		*v = elem->valeur;
}
/**
\fn void modif_elt(int v)
\brief Affecte la variable v � l'�l�ment courant
\param v Variable de type int qui est affect�e � l'�l�ment courant
*/
void modif_elt(int v){	
	if(!hors_liste()) 
		elem->valeur = v;
}
/**
\fn void oter_elt(void)
\brief Supprime l'�l�ment courant et positionne sur l'�l�ment pr�c�dent
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
\brief Ajoute une novelle structure et sa valeur v � droite de l'�l�ment courant
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
\brief Ajoute une nouvelle structure et sa valeur v � gauche de l'�l�ment courant
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
