#include <stdio.h>
#include <string.h>



#include "colors.h"
#include "carte.h"
#include "commande.h"


void display_banner() {
    printf("\n%s====================================================================================\n%s", BOLD, RESET);
    printf("%sPéripéC - v0.0.0 - Concocté par FlakeDo, avec un peu d'aide.\n\n", GREY);

    printf("%s%sBienvenue dans %sPéripé%sC%s\n", RESET, BOLD, GREEN, CYAN, RESET);
    printf("Un petit projet de jeu d'aventure textuelle pour revoir les concepts du langage !%s\n\n", DEFAULT);
}

int peripec_main(int argc, char* argv[]) {
    commande c;
    int i;
    joueur jey ;
    display_banner();


    printf("Initialisation de la carte...\n");
    initialiser_carte();

    printf("Initialisation du joueur...\n\n\n");
    jey = nouveau_joueur();

    afficher_lieu(jey.lieu_actuel);

    while( (strcmp(c.verbe,"q")) != 0 ){
        printf("%sCommande >> %s", BOLD, RESET);
        c = lire_commande();

        printf("%s %s\n",c.verbe,c.complement);

        if( strcmp(c.verbe, "aller") == 0  && c.a_complement != 0){
            executer_aller(&jey, c.complement);
        }
        else if( strcmp(c.verbe,  "regarder") == 0 ){
            afficher_lieu(jey.lieu_actuel);
        }
        else if(strcmp(c.verbe, "prendre") == 0){
            executer_prendre(&jey);
        }
        else if(strcmp(c.verbe,  "ouvrir") == 0 && c.a_complement != 0){
            executer_ouvrir(&jey,c.complement);
        }
        else if(strcmp(c.verbe,  "inventaire") == 0 && c.a_complement != 0){
            for(i=0; i<=8; i++){
                if(jey.inventaire[i] == 0){printf("Votre inventaire est vide.\n"); break;}
            }
            for(i=0; i<=8; i++){
                if(jey.inventaire[i]!=0) printf("%d",jey.inventaire[i]);
            }
        }
        else{
            printf("Commande inconnue\n");
        }

    }


    question1();

    return 0;
}
