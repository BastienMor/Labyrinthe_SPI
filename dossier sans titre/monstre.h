typedef struct {int etat; int contenu[10];}t_inventaire;
typedef struct {int id; int hp; int x,y;t_inventaire inventaire;}entity;
typedef struct {int etat; int haut;int bas;int gauche;int droite; t_inventaire objets; int entite;}t_salle;

void Monstre_initialiser(entity monstre);
void Monstre_deplacer(entity monstre);
void labyrinthe_orienter(int * nord, int * est, int * sud, int * ouest, entity monstre);
