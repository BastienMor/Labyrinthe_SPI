typedef struct inventaire{int etat; int contenue[50]; struct inventaire *locker[10];}t_inventaire;
typedef struct {int id; int hp; t_inventaire inventaire; int x; int y; int orientation;}entity;

void Combattre(entity monstre, entity joueur);
int Rencontre(entity monstre, entity joueur);
