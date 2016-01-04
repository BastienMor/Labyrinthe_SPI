#include "../include/constante.h"
#include "../include/module_labyrinthe.h"
#include "../include/module_joueur.h"
#include "../include/module_menu.h"

/**
\file main.c
\brief Fichier comportant l'initialisation et le lancement du jeu
\author Bastien, Alizée
\date Décembre 2015
\version 1.0
*/

int main() {
	initialisation();
	Menu();
		
	return 0;
}
