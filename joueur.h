void Joueur_deplacer(entity joueur); //Déplace le joueur
void Joueur_initialiser(entity joueur); // Initialise les stats du joueur, peut être réutilisé plusieurs fois
void Joueur_combattre(entity joueur); // Fait combattre le joueur contre un monstre
void Joueur_agir(t_salle labyrinthe, entity joueur, entity monstre); // Permet de faire agir le joueur pendant le tour 
void Joueur_tester(int var); // Vérification des fonctions 
void Joueur_amorcer(); // A utiliser seulement une fois (début de partie)