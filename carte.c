#include "carte.h"
#include "commande.h"
#include <string.h>
#include <stdio.h>
#include "colors.h"

lieu carte[NB_LIEUX];
void initialiser_carte(void){
    /*-------0--Sanctuaire ---------*/
    strcpy(carte[0].nom, "Sanctuaire") ;

    strcpy(carte[0].description, "Une petite salle silencieuse éclairée par des bougies. Le trésor final repose ici.\n");

    carte[0].porte_fermee[0] = 0;
    carte[0].porte_fermee[1] = 0;
    carte[0].porte_fermee[2] = 0;
    carte[0].porte_fermee[3] = 0;

    carte[0].sorties[0]=1;
    carte[0].sorties[1]=-1;
    carte[0].sorties[2]=-1;
    carte[0].sorties[3]=-1;


/*-------1--Village ---------*/

    strcpy(carte[1].nom, "Village") ;

    strcpy (carte[1].description, "La place du village, calme et familière. Une porte fermée part vers le sud.\n");

    carte[1].porte_fermee[0] = 0;
    carte[1].porte_fermee[1] = 1;
    carte[1].porte_fermee[2] = 0;
    carte[1].porte_fermee[3] = 0;

    carte[1].sorties[0]=3;
    carte[1].sorties[1]=0;
    carte[1].sorties[2]=2;
    carte[1].sorties[3]=-1;

/*-------2--Pont---------*/
    strcpy(carte[2].nom, "Pont" );

    strcpy(carte[2].description, "Un vieux pont de pierre enjambant une rivière.\n");

    carte[2].porte_fermee[0] = 0;
    carte[2].porte_fermee[1] = 0;
    carte[2].porte_fermee[2] = 0;
    carte[2].porte_fermee[3] = 0;

    carte[2].sorties[0]=-1;
    carte[2].sorties[1]=-1;
    carte[2].sorties[2]=5;
    carte[2].sorties[3]=1;

/*-------3--Forêt Nord ---------*/
    strcpy(carte[3].nom, "Forêt Nord" );

    strcpy(carte[3].description, "Une forêt sombre. Un grognement se fait entendre au loin.\n");

    carte[3].porte_fermee[0] = 0;
    carte[3].porte_fermee[1] = 0;
    carte[3].porte_fermee[2] = 0;
    carte[3].porte_fermee[3] = 0;

    carte[3].sorties[0]=-1;
    carte[3].sorties[1]=1;
    carte[3].sorties[2]=4;
    carte[3].sorties[3]=-1;

/*-------4--Clairière ---------*/
    strcpy(carte[4].nom, "Clairière" );

    strcpy(carte[4].description, "Une clairière baignée de lumière, avec un vieux puits au centre.\n");

    carte[4].porte_fermee[0] = 0;
    carte[4].porte_fermee[1] = 0;
    carte[4].porte_fermee[2] = 0;
    carte[4].porte_fermee[3] = 0;

    carte[4].sorties[0]=6;
    carte[4].sorties[1]=-1;
    carte[4].sorties[2]=5;
    carte[4].sorties[3]=3;

/*-------5--Grotte ---------*/
    strcpy(carte[5].nom, "Grotte" );

    strcpy(carte[5].description, "L'entrée d'une grotte humide. Une porte de fer en bloque le fond.\n");

    carte[5].porte_fermee[0] = 0;
    carte[5].porte_fermee[1] = 0;
    carte[5].porte_fermee[2] = 1;
    carte[5].porte_fermee[3] = 0;

    carte[5].sorties[0]=-1;
    carte[5].sorties[1]=2;
    carte[5].sorties[2]=7;
    carte[5].sorties[3]=4;

/*-------6--Tour ---------*/
    strcpy(carte[6].nom, "Tour" );

    strcpy(carte[6].description, "Le sommet d'une tour en ruines, vue dégagée sur toute la carte.\n");

    carte[6].porte_fermee[0] = 0;
    carte[6].porte_fermee[1] = 0;
    carte[6].porte_fermee[2] = 0;
    carte[6].porte_fermee[3] = 0;

    carte[6].sorties[0]=-1;
    carte[6].sorties[1]=4;
    carte[6].sorties[2]=-1;
    carte[6].sorties[3]=-1;

/*-------7--Donjon ---------*/
    strcpy(carte[7].nom, "Donjon" );

    strcpy(carte[7].description, "Le repaire du gardien. L'air est lourd.\n");

    carte[7].porte_fermee[0] = 0;
    carte[7].porte_fermee[1] = 0;
    carte[7].porte_fermee[2] = 0;
    carte[7].porte_fermee[3] = 0;

    carte[7].sorties[0]=-1;
    carte[7].sorties[1]=-1;
    carte[7].sorties[2]=-1;
    carte[7].sorties[3]=5;

    carte[4].objet_present = 0;
    carte[6].objet_present = 7;
    carte[0].objet_present = -1;
    carte[1].objet_present = -1;
    carte[2].objet_present = -1;
    carte[3].objet_present = -1;
    carte[5].objet_present = -1;
    carte[7].objet_present = -1;


}

void afficher_lieu(int id){
    char *name = carte[id].nom;
    char * desc = carte[id].description;
    int i;

    printf("== %s ==\n%s\nSorties :\n",name,desc);

    for(i=0; i<=3; i++){
        if(carte[i].sorties[i] != -1){
            switch (i) {
            case 0:
                printf("NORD\n");
                break;
            case 1:
                printf("SUD\n");
                break;
            case 2:
                printf("EST\n");
                break;
            case 3:
                printf("OUEST\n");
                break;

            }
        }
        if(carte[id].objet_present != -1){
            printf("Vous voyez ici : une clef.\n");
        }

    }

}

void question3(void){
    int i;
    initialiser_carte();
    for(i=0;i<=NB_LIEUX;i++){
        afficher_lieu(i);
    }

}
