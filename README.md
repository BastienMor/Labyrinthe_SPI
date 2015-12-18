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

⇢ Lors du démarrage, le titre du jeu de même qu'un menu principal apparaît avec plusieurs possibilités disponibles. On peut commencer une nouvelle partie, en charger une et au cours du jeu, la sauvegarder.  
⇢ Une fois que la partie est commencée, un affichage à la première personne ainsi qu'un autre menu sont présents et donnent les indications à effectuer par l'utilisateur. Sur le menu sont indiqués la barre de vie progressive, une lettre pour les points cardinaux et correspondant à l'orientation du joueur et les PA, pour les points d'action.  
⇢ Ces points permettent de faire plusieurs actions parmi les suivantes : le joueur peut se déplacer, afficher la carte, afficher les objets (de l'inventaire du joueur ou bien de la salle de labyrinthe), changer d'orientation, retourner au menu principal ou bien terminer le tour sans utiliser tous les points d'action.  
⇢ Sur la carte, le joueur, représenté par un carré creux, se déplace dans un labyrinthe où les carrés pleins sont les murs. La carte n'est pas complète, elle est définie en fonction des cases que le joueur a découvert. Il faut donc utiliser tous les points d'actions pour terminer le tour et ainsi faire place au tour des monstres.  


#Instructions de compilation
Pour compiler l'ensemble du programme, il faut effectuer la commande sur terminal :  
	`$ make `
Cela crée le fichier exécutable laby qui sera disponible dans `./bin/laby`  

Pour exécuter le programme, il suffit alors d'effectuer la commande :  
	`$ ./bin/laby`

Si l'on veut supprimer les fichiers indésirables (comme les fichiers *.o), il suffit de faire :  
	`$ make clear`	

##Programmation du jeu
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



