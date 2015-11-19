#Laby SPI
##La boucle principale :

`Jeu_Initialiser(##Labyrinthe, Joueur_Objet, Monstre_Objet_Liste);`

##Boucle du jeu
```
while(!bPartie_finie(Joueur_Objet)){
  Joueur_Agir(#Labyrinthe, Joueur_Objet, Monstre_Objet_Liste);
  Ecran_Afficher(Labyrinthe);

  if(bMonstre_Present(Monstre_Objet_Liste) && !bPartie_finie(Joueur_Objet)){
    Monstre_Agir(#Labyrinthe, Joueur_Objet, Monstre_Objet_Liste#);
    Ecran_Afficher(Labyrinthe);
  }
}
Gameover_Afficher();
```
