#Laby SPI
3 étudiants ont réalisé "La vie dans un labyrinthe" : Bodineau Bastien, Duran Alizée et Ngatchou Junior  

##Règles du jeu
Le jeu se déroule comme suit :  
⇢ Le joueur se déplace dans un labyrinthe généré aléatoirement. Les statistiques du joueur peuvent changer au cours du jeu. Pour vivre, le joueur doit récupérer des objets disposés au sol et vaincre des monstres qui sont présents dans le labyrinthe.

##Comment jouer ?
	Lors du démarrage, le titre du jeu de même qu'un menu principal apparaît avec plusieurs possibilités disponibles. On peut commencer une nouvelle partie, en charger une et au cours du jeu, la sauvegarder.  
	Une fois que la partie est commencée, un affichage à la première personne ainsi qu'un autre menu sont présents et donnent les indications à effectuer par l'utilisateur. Sur le menu sont indiqués la barre de vie progressive, une lettre pour les points cardinaux et correspondant à l'orientation du joueur et les PA, pour les points d'action. 
	Ces points permettent de faire plusieurs actions parmi les suivantes : le joueur peut se déplacer, afficher la carte, afficher les objets (de l'inventaire du joueur ou bien de la salle de labyrinthe), changer d'orientation, retourner au menu principal ou bien terminer le tour sans utiliser tous les points d'action.  
	Sur la carte, le joueur, représenté par un carré creux, se déplace dans un labyrinthe où les carrés pleins sont les murs. La carte n'est pas complète, elle est définie en fonction des cases que le joueur a découvert. Il faut donc utiliser tous les points d'actions pour terminer le tour et ainsi faire place au tour des monstres.  

##Programmation du jeu
###Se donner une idée du main - La boucle principale
`Jeu_Initialiser(##Labyrinthe, Joueur_Objet, Monstre_Objet_Liste);`  

###Se donner une idée du main - Boucle du jeu  
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

	`typedef struct {int etat; int contenu[10];}t_inventaire;`  
	`typedef struct {int id; int hp; t_inventaire inventaire; int x; int y; int orientation;}entity;`  
	`typedef struct {int etat; int haut;int bas;int gauche; int droite; t_inventaire objets; entity entite;}t_salle;`  
    	`t_salle labyrinthe[N][N];`  
   	 `entity joueur;`  
    	`entity tab[10];`  

* Labyrinthe (Junior)  

	`void Labyrinthe_initialiser();` // Initialise le labyrinthe avec des caractères Unicode pour la forme et des nombres  
	`void Labyrinthe_afficher();` //Affichage du labyrinthe  

* Labyrinthe (Bastien)  

	`void joueurpos(int * x, int * y);` //trouver les x et y du joueur  
	`void labyrinthe_orienter(int * nord, int * est, int * sud, int * ouest);` //retourne où l'on peut se déplacer JOUEUR UNIQUEMENT  
	`void labyrinthe_examiner(int x, int y, t_inventaire * quoi);` //informations sur une salle, [-1;-1] en paramètre prendra les infos sur la case du joueur  
	`void labyrinthe_presencer(int x, int y, entity * nord, entity * est, entity * sud, entity * ouest);` //info sur les entités alentours d'une entité, [-1;-1] prendra le x et y du joueur  
	`void labyrinthe_deplacer(entity qui, int orientation);` //déplace une entité (orientation = [1; 2; 3; 4])  
	`void labyrinthe_afficher();` //affiche le labyrinthe  
	`void labyrinthe_saller();` //création d'une salle  
	
* Joueur (Alizée)  
//Fonctions d'initialisation  
	`void Joueur_initialiser(entity joueur);` // Initialise les stats du joueur, peut être réutilisé plusieurs fois  
	`void Joueur_amorcer();` // A utiliser seulement une fois (début de partie)  

//Fonctions booléennes  
	`int bPartie_finie();` //Indique la fin de partie  
	`int bLabyrinthe_checker(t_salle labyrinthe[N][N]);` //Vérifie le contenu d'une case de la salle  
	`int bObjet(t_salle labyrinthe);` //Indique la présence ou non d'un objet au sol  
	`int bMonstre();` //Indique la présence ou non d'un monstre devant soi  
	`int bMur();` //Indique la présence ou non du mur dans les 4 directions  

//Fonctions Joueur  
	`void Joueur_deplacer(entity joueur, t_salle labyrinthe[N][N])`  
	`void Joueur_combattre(entity joueur);` // Fait combattre le joueur contre un monstre  
	`void Joueur_agir(t_salle labyrinthe, entity joueur, entity monstre);` // Permet de faire agir le joueur pendant le tour  
	`void Joueur_tester(int var);` // Vérification des fonctions  

