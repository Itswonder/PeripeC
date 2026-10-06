#define TAILLE_MOT 32
#define NB_LIEUX 8
int lire_mot(char buffer[], int taille_max);
typedef struct cmd{
    char verbe[TAILLE_MOT];
    char complement[TAILLE_MOT];
    int a_complement;
}commande;

commande lire_commande(void);


typedef struct{
    int lieu_actuel;
    int pv;
    int inventaire[NB_LIEUX];
}joueur;

joueur nouveau_joueur(void);

void question1(void);

int mot_vers_direction(char mot[]);

void executer_aller(joueur *j, char complement[]);

void executer_prendre(joueur *j);

void executer_ouvrir(joueur *j, char complement[]);

int dir_opp(int d);







