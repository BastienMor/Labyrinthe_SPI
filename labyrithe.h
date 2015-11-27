typedef struct inventaire{int etat; int contenue[10]; struct inventaire *locker[10];}t_inventaire;

typedef struct {int id; int hp; t_inventaire inventaire; int x; int y; int orientation;}entity;

typedef struct {int etat; int haut;int bas;int gauche; int droite; t_inventaire objets; entity entite;}t_salle;

t_salle labyrinthe[N][N];
entity joueur;
entity tab[10];


//trouver les x et y du joueur
void joueurpos(int * x, int * y)


//retourne ou l'on peut se déplacé JOUEUR UNIQUEMENT
void labyrinthe_orienter(int * nord, int * est, int * sud, int * ouest)


//info sur une salle
//[-1;-1] en paramettre prendra les infos sur la case du joueur.
void labyrinthe_examiner(int x, int y, t_inventaire * quoi)


//info sur les entité alentours d'une entité
//[-1;-1] prendra le x et y du joueur.
void labyrinthe_presencer(int x, int y, entity * nord, entity * est, entity * sud, entity * ouest)


//deplace une entité (orientation = [1; 2; 3; 4])
void labyrinthe_deplacer(entity qui, int orientation)


//affiche le labyrinthe
void labyrinthe_afficher()


//creation d'une salle
void labyrinthe_saller()