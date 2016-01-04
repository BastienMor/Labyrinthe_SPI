#include "../include/constante.h"
#include "../include/module_labyrinthe.h"
#include "../include/module_menu.h"

/**
\file module_joueur.c
\brief Module du joueur avec ses fonctions associées
\author Bastien, Alizée
\date Décembre 2015
\version 1.0
*/




/**
\fn void stat_disp(int action)
\brief Fonction servant à calculer et afficher les points de vie du joueur (barre d'hp).
\param action Variable action dépendant du nombre d'actions que le joueur peut effectuer
*/
void stat_disp(int action){
	int i;
	int hp = joueur.hp;
	int max = 400;
	int maction = joueur.action;
	int x, y;
	joueurpos(&x, &y);
	int orientation = labyrinthe[x][y].entite.orientation;
	hp = (100*hp/max);
	
	if (action >= 10){
		printf("═PA:%i/%i══╣HP", action, maction);
	}else{
		printf("═PA:0%i/%i══╣HP", action, maction);
	}
	
	for (i=0; i<10; i++){
		if (hp > 10){
			hp -= 10;
			printf("█");
		}else if (hp < 10 && hp > 0){
			hp = 0;
			printf("▓");
		}else{
			printf("░");
		}
	}
	
	printf("╠══");
	
	if (orientation == 1){
		printf("N");
	}else if (orientation == 2){
		printf("E");
	}else if (orientation == 3){
		printf("S");
	}else if (orientation == 4){
		printf("O");
	}
	printf("═╗\n");
}

/**
\fn void viderBuffer()
\brief Permet de vider le buffer à chaque action effectuée afin d'éviter une saturation de mémoire
*/
void viderBuffer(){
    int c = 0;
    while (c != '\n' && c != EOF){
        c = getchar();
    }
}

/**
\fn void init_player()
\brief Permet d'initialiser le joueur avec ses différents caractéristiques
*/
void init_player(){
	joueur.id = 1;
	joueur.hp = 100;
	joueur.action = 8;
	joueur.orientation = 1;
	
	labyrinthe[rand()%N][0].entite = joueur;
}

/**
\fn void deplacement(int action)
\brief Fonction qui permet d'affecter du joueur à l'intérieur du labyrinthe 
\param action Variable action dépendant des points d'actions du joueur
*/
void deplacement(int direction)
{
	int x, y;
	joueurpos(&x, &y);
	
	if (direction == 1){
		labyrinthe[x-1][y].entite = labyrinthe[x][y].entite;
	}
	else if (direction == 2){
		labyrinthe[x][y+1].entite = labyrinthe[x][y].entite;
	}
	else if (direction == 3){
		labyrinthe[x+1][y].entite = labyrinthe[x][y].entite;
	}
	else if (direction == 4){
		labyrinthe[x][y-1].entite = labyrinthe[x][y].entite;
	}
	labyrinthe[x][y].entite.id = 0;
	joueurpos(&x, &y);
	labyrinthe[x][y].isvisit = 1;
}

/**
\fn int Joueur_deplacer(int action)
\brief Permet de faire déplacer le joueur à l'intérieur du labyrinthe en utilisant la fonction deplacement pour son orientation. Affichage du menu de déplacement
\param action Variable servant de nombre de points d'action du joueur
\return agir Variable indiquant si oui ou non le joueur s'est déplacé (afin d'enlever un point d'action)
*/
int Joueur_deplacer(int action){
	int nord, sud, est, ouest;
	int devant, droite, derriere, gauche;
	int fin_action = 0;
	int agir = 1;
	char bouger;
	int x, y;
	joueurpos(&x, &y);
	
	devant = labyrinthe[x][y].entite.orientation;
	if (devant == 1){
		droite = 2;
		gauche = 4;
		derriere = 3;
		nord = labyrinthe[x][y].haut;
		est = labyrinthe[x][y].droite;
		sud = labyrinthe[x][y].bas;
		ouest = labyrinthe[x][y].gauche;
	}else if (devant == 2){
		droite = 3;
		gauche = 1;
		derriere = 4;
		nord = labyrinthe[x][y].droite;
		est = labyrinthe[x][y].bas;
		sud = labyrinthe[x][y].gauche;
		ouest = labyrinthe[x][y].haut;
	}else if (devant == 3){
		droite = 4;
		gauche = 2;
		derriere = 1;
		nord = labyrinthe[x][y].bas;
		est = labyrinthe[x][y].gauche;
		sud = labyrinthe[x][y].haut;
		ouest = labyrinthe[x][y].droite;
	}else if (devant == 4){
		droite = 1;
		gauche = 3;
		derriere = 2;
		nord = labyrinthe[x][y].gauche;
		est = labyrinthe[x][y].haut;
		sud = labyrinthe[x][y].droite;
		ouest = labyrinthe[x][y].bas;
	}
	
	do{
		labyrinthe_disp();
		printf("╔═Déplacement(s)═disponible(s)══");
		stat_disp(action);
		if(nord != 1)
			printf("║ z - S'avancer                                             ║\n");
		if(ouest != 1)
			printf("║ q - Se déplacer à gauche sans changer d'orientation       ║\n");
		if(sud != 1)
			printf("║ s - Se reculer                                            ║\n");
		if(est != 1)
			printf("║ d - Se déplacer à droite sans changer d'orientation       ║\n");
		printf("║ c - Retour                                                ║\n");
		printf("╚═══════════════════════════════════════════════════════════╝\n\n");
		
		bouger=getchar();
		switch(bouger){
			case 'z': if(nord != 1){deplacement(devant); fin_action=1;}else{printf("Déplacement impossible !\n");} break;
			case 'q': if(ouest != 1){deplacement(gauche); fin_action=1;}else{printf("Déplacement impossible !\n");} break;
			case 's': if(sud != 1){deplacement(derriere); fin_action=1;}else{printf("Déplacement impossible !\n");} break;
			case 'd': if(est != 1){deplacement(droite); fin_action=1;}else{printf("Déplacement impossible !\n");} break;
			case 'c': agir=0; fin_action=1; break;
			default: printf("Entrée non valide\n");
		}
	}while(!fin_action);
	viderBuffer();
	return agir;
}

/**
\fn int tourne()
\brief Fonction qui permet de récupérer l'orientation du joueur
\return labyrinthe[x][y].entite.orientation Nombre indiquant la direction
*/
int tourne(int t, int x, int y){
	labyrinthe[x][y].entite.orientation += t;
	
	if (labyrinthe[x][y].entite.orientation > 4){
		labyrinthe[x][y].entite.orientation -= 4;
	}else if (labyrinthe[x][y].entite.orientation < 1){
		labyrinthe[x][y].entite.orientation += 4;
	}
	return labyrinthe[x][y].entite.orientation;
}

/**
\fn void Joueur_tourne(int action)
\brief En récupérant l'orientation du joueur, permet de faire tourner le joueur de l'orientation que l'on souhaite. Affichage d'un menu adapté
\param action Variable indiquant le nombre d'action du joueur
*/
void Joueur_tourne(int action){
	int x, y;
	int fin_action = 0;
	char tour;
	joueurpos(&x, &y);
	int orientation = labyrinthe[x][y].entite.orientation;

	do{
		labyrinthe_disp();
		printf("╔══Sens═ou═tourner═?══════");
		stat_disp(action);
		printf("║ q - Tourner à gauche                                ║\n");
		printf("║ s - Se retourner                                    ║\n");
		printf("║ d - Tourner à droite                                ║\n");
		printf("║ c - Retour                                          ║\n");
		printf("╚═════════════════════════════════════════════════════╝\n\n");
		
		tour=getchar();
		switch(tour){
			case 'q': joueur.orientation = tourne(-1, x, y); fin_action=1; break;
			case 'd': joueur.orientation = tourne(1, x, y); fin_action=1; break;
			case 's': joueur.orientation = tourne(2, x, y); fin_action=1; break;
			case 'c': fin_action=1; break;
			default: printf("Entrée non valide\n");
		}
	}while(!fin_action);
	viderBuffer();
}

/**
\fn int Joueur_agir()
\brief Permet de faire agir le joueur pendant les points d'actions disponibles par tour
\return retour_menu Variable indiquant si oui ou non on retourne au menu principal
*/
int Joueur_agir(){  
	int tour=0;
	
	int action = joueur.action;
	int x, y;
	int retour_menu = 0;
	joueurpos(&x, &y);
	int hp = joueur.hp;
	int agir = 0;
	int fin_action = 0;
	char c;
	
	labyrinthe[x][y].isvisit = 1;
	
	do{
		labyrinthe_disp();
		printf("╔════Menu═D'action═════════════");
		stat_disp(action);
		printf("║ 1 - Déplacement                                          ║\n");
		printf("║ 2 - Check salle                                          ║\n");
		printf("║ 3 - Se tourner                                           ║\n");
		printf("║ 4 - Combattre                                            ║\n");
		printf("║ 5 - Carte                                                ║\n");
		printf("║ 6 - Fin de tour                                          ║\n");
		if (action == joueur.action)
			printf("║ 7 - Menu principal                                       ║\n");
		printf("╚══════════════════════════════════════════════════════════╝\n\n");
		c=getchar();
		switch(c){
			case '1': viderBuffer(); agir = Joueur_deplacer(action); break;
			case '2': break;
			case '3': viderBuffer(); agir = 0; Joueur_tourne(action); break;
			case '4': break;
			case '5': viderBuffer(); agir = 0; labyrinthe_afficher(0); break;
			case '6': viderBuffer(); fin_action = 1; break;
			case '7': viderBuffer(); if (action == joueur.action){fin_action = 1; retour_menu = 1;}else{printf("NON !");} break;
			default: printf("Action non valide !\n");
		}
		action -= agir;
	}while (action > 0 && !fin_action);
	return retour_menu;
}

/**
\fn int fin_partie()
\brief Fonction indiquant la fin de partie ou non
\return Une valeur indiquant si vrai la partie terminée
*/
int fin_partie(){
	int x, y;
	joueurpos(&x, &y);
	int i, j=11;
	winpos(&i);
	
	
	if ((x == i && y == j) || joueur.hp == 0){
		return 1;
	}else{
		return 0;
	}
}


/**
\fn int play()
\brief Fonction qui permet de faire jouer le joueur avec des conditions d'arrêt telles que la mort du joueur ou bien la fin de partie
\return Une valeur indiquant si le jeu continue ou est terminé
*/
int play (){
	int retour_menu = 0;
	int fin = 0;
	
	while (!fin && retour_menu == 0){
		retour_menu = Joueur_agir();
		//Monstres agir ???
		
		fin = fin_partie();
	}
	
	if (fin && joueur.hp != 0){
		printf("\n        __     __\n        \\ \\   / /__  _   _ ___    __ ___   _____ ____\n         \\ \\ / / _ \\| | | / __|  / _` \\ \\ / / _ \\_  /\n          \\ V / (_) | |_| \\__ \\ | (_| |\\ V /  __// /\n           \\_/ \\___/ \\__,_|___/  \\__,_| \\_/_\\___/___|\n                 __ _  __ _  __ _ _ __   /_/| |\n                / _` |/ _` |/ _` | '_ \\ / _ \\ |\n               | (_| | (_| | (_| | | | |  __/_|\n                \\__, |\\__,_|\\__, |_| |_|\\___(_)\n                |___/       |___/\n\n\n");
	}
	
	if (joueur.hp == 0){
		return 1;
	}
	
	else{
		return 0;
	}
}
