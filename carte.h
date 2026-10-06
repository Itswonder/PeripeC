#ifndef CARTE_H
#define CARTE_H

#define NB_LIEUX 8

typedef enum{
    NORD, SUD, EST, OUEST

}direction;

typedef struct {
    char nom[32];
    char description[256];
    int sorties[4];
    int porte_fermee[4];
    int objet_present;
}lieu;

extern lieu carte[NB_LIEUX];

void initialiser_carte(void);
void question3(void);

void afficher_lieu(int id);


#endif
