
//Fonctions d'initialisation
void Joueur_initialiser(entity joueur); // Initialise les stats du joueur, peut être réutilisé plusieurs fois
void Joueur_amorcer(); // A utiliser seulement une fois (début de partie)

//Fonctions booléennes
int bPartie_finie(); //Indique la fin de partie
int bLabyrinthe_checker(t_salle labyrinthe[N][N]); //Vérifie le contenu d'une case de la salle
int bObjet(t_salle labyrinthe); //Indique la présence ou non d'un objet au sol
int bMonstre(); //Indique la présence ou non d'un monstre devant soi
int bMur(); //Indique la présence ou non du mur dans les 4 directions


//Fonctions Joueur
void Joueur_deplacer(entity joueur, t_salle labyrinthe[N][N]);
void Joueur_combattre(entity joueur); // Fait combattre le joueur contre un monstre
void Joueur_agir(t_salle labyrinthe, entity joueur, entity monstre); // Permet de faire agir le joueur pendant le tour 
void Joueur_tester(int var); // Vérification des fonctions 

