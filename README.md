#Laby SPI
3 étudiants ont réalisé "La vie dans un labyrinthe" : Bodineau Bastien, Duran Alizée et Ngatchou Junior  

##Jeu

###La boucle principale
`Jeu_Initialiser(##Labyrinthe, Joueur_Objet, Monstre_Objet_Liste);`  

###Boucle du jeu  
	while(!bPartie_finie(Joueur_Objet)){  
		Joueur_Agir(#Labyrinthe, Joueur_Objet, Monstre_Objet_Liste#);  
		Labyrinthe_Afficher(Labyrinthe);  
		if(bMonstre_Present(Monstre_Objet_Liste) && !bPartie_finie(Joueur_Objet)){  
    		Monstre_Agir(#Labyrinthe, Joueur_Objet, Monstre_Objet_Liste#);  
    		Labyrinthe_Afficher(Labyrinthe);  
  		}  
	}  
	Gameover_Afficher();  

###Fonctions et structures utilisées

* Structures de données  

	typedef struct inventaire{int etat; int contenue[10]; struct inventaire *locker[10];}t_inventaire;
	typedef struct {int id; int hp; t_inventaire inventaire; int x; int y; int orientation;}entity;
	typedef struct {int etat; int haut;int bas;int gauche; int droite; t_inventaire objets; entity entite;}t_salle;
    t_salle labyrinthe[N][N];
    entity joueur;
    entity tab[10];

* Labyrinthe (Junior)  

	void Labyrinthe_initialiser();  
    void Labyrinthe_afficher();  

* Labyrinthe (Bastien)

	void joueurpos(int * x, int * y); //trouver les x et y du joueur  
	void labyrinthe_orienter(int * nord, int * est, int * sud, int * ouest); //retourne où l'on peut se déplacer JOUEUR UNIQUEMENT  
	void labyrinthe_examiner(int x, int y, t_inventaire * quoi); //informations sur une salle, [-1;-1] en paramètre prendra les infos sur la case du joueur  
	void labyrinthe_presencer(int x, int y, entity * nord, entity * est, entity * sud, entity * ouest); //info sur les entités alentours d'une entité, [-1;-1] prendra le x et y du joueur.  
	void labyrinthe_deplacer(entity qui, int orientation); //déplace une entité (orientation = [1; 2; 3; 4])  
	void labyrinthe_afficher(); //affiche le labyrinthe  
	void labyrinthe_saller(); //création d'une salle  
	
* Joueur  

	void Joueur_deplacer(entity joueur); //Déplace le joueur  
	void Joueur_initialiser(entity joueur); // Initialise les stats du joueur, peut être réutilisé plusieurs fois  
	void Joueur_combattre(entity joueur); // Fait combattre le joueur contre un monstre  
	void Joueur_agir(t_salle labyrinthe, entity joueur, entity monstre); // Permet de faire agir le joueur pendant le tour  
	void Joueur_tester(int var); // Vérification des fonctions  
	void Joueur_amorcer(); // A utiliser seulement une fois (début de partie)  