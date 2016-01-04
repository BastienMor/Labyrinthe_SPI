#include "../include/constante.h"
#include "../include/module_joueur.h"
#include "../include/module_labyrinthe.h"


void print_title(int isdead)
{
	int a;

	if (isdead)
	{
		printf("\n\n\n ██▓    ▄▄▄       ▄▄▄▄ ▓██   ██▓ ██▀███   ██▓ ███▄    █ ▄▄▄█████▓ ██░ ██ ▓█████\n▓██▒   ▒████▄    ▓█████▄▒██  ██▒▓██ ▒ ██▒▓██▒ ██ ▀█   █ ▓  ██▒ ▓▒▓██░ ██▒▓█   ▀\n▒██░   ▒██  ▀█▄  ▒██▒ ▄██▒██ ██░▓██ ░▄█ ▒▒██▒▓██  ▀█ ██▒▒ ▓██░ ▒░▒██▀▀██░▒███\n▒██░   ░██▄▄▄▄██ ▒██░█▀  ░ ▐██▓░▒██▀▀█▄  ░██░▓██▒  ▐▌██▒░ ▓██▓ ░ ░▓█ ░██ ▒▓█  ▄\n░██████▒▓█   ▓██▒░▓█  ▀█▓░ ██▒▓░░██▓ ▒██▒░██░▒██░   ▓██░  ▒██▒ ░ ░▓█▒░██▓░▒████▒\n░ ▒░▓  ░▒▒   ▓▒█░░▒▓███▀▒ ██▒▒▒ ░ ▒▓ ░▒▓░░▓  ░ ▒░   ▒ ▒   ▒ ░░    ▒ ░░▒░▒░░ ▒░ ░\n░ ░ ▒  ░ ▒   ▒▒ ░▒░▒   ░▓██ ░▒░   ░▒ ░ ▒░ ▒ ░░ ░░   ░ ▒░    ░     ▒ ░▒░ ░ ░ ░  ░\n  ░ ░    ░   ▒    ░    ░▒ ▒ ░░    ░░   ░  ▒ ░   ░   ░ ░   ░       ░  ░░ ░   ░\n    ░  ░     ░  ░ ░     ░ ░        ░      ░           ░           ░  ░  ░   ░  ░\n                       ░░ ░                                                     \n\n\n");
	}
	else
	{
		a = (rand()%2)+1;
		if (a == 1)
		{
			printf("\033[5;40;93m __           ___      .______   ____    ____ .______       __  .__   __. .___________. __    __   _______ \n|  |         /   \\     |   _  \\  \\   \\  /   / |   _  \\     |  | |  \\ |  | |           ||  |  |  | |   ____|\n|  |        /  ^  \\    |  |_)  |  \\   \\/   /  |  |_)  |    |  | |   \\|  | `---|  |----`|  |__|  | |  |__   \n|  |       /  /_\\  \\   |   _  <    \\_    _/   |      /     |  | |  . `  |     |  |     |   __   | |   __|  \n|  `----. /  _____  \\  |  |_)  |     |  |     |  |\\  \\----.|  | |  |\\   |     |  |     |  |  |  | |  |____ \n|_______|/__/     \\__\\ |______/      |__|     | _| `._____||__| |__| \\__|     |__|     |__|  |__| |_______|\033[0m\n\n\n");
		}
		else
		{
			printf("\n\n\n\033[0;40;32m██╗      █████╗ ██████╗ ██╗   ██╗██████╗ ██╗███╗   ██╗████████╗██╗  ██╗███████╗\n██║     ██╔══██╗██╔══██╗╚██╗ ██╔╝██╔══██╗██║████╗  ██║╚══██╔══╝██║  ██║██╔════╝\n██║     ███████║██████╔╝ ╚████╔╝ ██████╔╝██║██╔██╗ ██║   ██║   ███████║█████╗  \n██║     ██╔══██║██╔══██╗  ╚██╔╝  ██╔══██╗██║██║╚██╗██║   ██║   ██╔══██║██╔══╝  \n███████╗██║  ██║██████╔╝   ██║   ██║  ██║██║██║ ╚████║   ██║   ██║  ██║███████╗\n╚══════╝╚═╝  ╚═╝╚═════╝    ╚═╝   ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝   ╚═╝   ╚═╝  ╚═╝╚══════╝\033[0m\n\n\n");
		}
	}	
}


void Jeu_sauver(){
	FILE * save;
	save = fopen("p1.sav", "w");
	fwrite(labyrinthe, sizeof(t_salle), sizeof(labyrinthe)/sizeof(t_salle), save);
	fclose(save);
	
	printf("\n\n              ╔═══════════════════════════════════════════════╗\n");
	printf("              ║      La partie a bien été sauvegardée !       ║\n");
	printf("              ╚═══════════════════════════════════════════════╝\n\n");
}

void Jeu_charger(){
	FILE * load;
	load = fopen("p1.sav", "r");
	fread(labyrinthe, sizeof(t_salle), sizeof(labyrinthe)/sizeof(t_salle), load);
	fclose(load);
	
	printf("\n\n              ╔═══════════════════════════════════════════════╗\n");
	printf("              ║        La partie a bien été chargée !         ║\n");
	printf("              ╚═══════════════════════════════════════════════╝\n\n");
}



void initialisation()
{
	int a = rand()%N;
	init_laby();
	Laby_generator();
	init_player();
	labyrinthe[a][N-1].objet.etat = 10;
	labyrinthe[a][N-1].isvisit = 1;
}



//Menu lors du démarrage du jeu et menu pause du jeu
void Menu(){

	int choix;
	int isdead = 0;
	
	do{
		print_title(isdead);
		printf("              ╔═══════════════════════════════════════════════╗\n");
		printf("              ║                Menu principal                 ║\n");
		printf("              ║   1 - Commencer une nouvelle partie           ║\n");
		printf("              ║   2 - Continuer la partie                     ║\n");
		printf("              ║   3 - Sauvegarder la partie                   ║\n");
		printf("              ║   4 - Charger une partie                      ║\n");
		printf("              ║   5 - Options                                 ║\n");
		printf("              ║   6 - Quitter                                 ║\n");
		printf("              ╚═══════════════════════════════════════════════╝\n");
		printf("                       ⇢ Que voulez-vous faire ?  ");
		scanf("%i", &choix);
		printf("\n");
		switch(choix){
			case 1: viderBuffer(); initialisation(); isdead = play(); break;
			case 2: viderBuffer(); isdead = play(); break;
			case 3: viderBuffer(); if (!isdead){Jeu_sauver();} break;
			case 4: viderBuffer(); Jeu_charger(); break;
			case 5: viderBuffer(); /*Options_afficher();*/ break;
			case 6: break;	
		}
	}while(choix != 6);
	printf("\n                                Au revoir !\n\n");
}



int main() {
	
	initialisation();
	Menu();
		
	return 0;
}
