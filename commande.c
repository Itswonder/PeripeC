#include <stdio.h>
#include <string.h>
#include "commande.h"
#include "carte.h"


int lire_mot(char buffer[], int taille_max){
    char c;
    int n=0;
    c=getchar();
    while(c==' ') c = getchar(); /*vide les espaces avant le mot*/
    while( c != ' ' && c != EOF &&c !='\n'){
        if(n< taille_max-1){
            buffer[n]=c; /*ajoute les caractères du mot au buffer*/
            n++; /*incrémente le nombre de caractères du mot*/
        }
        c = getchar();
    }
    buffer[n] = '\0';
    return n;

}

commande lire_commande(void){
    commande c;
    lire_mot(c.verbe, TAILLE_MOT); /*on lit le premier mot*/
    c.a_complement = (lire_mot(c.complement,TAILLE_MOT)>=1); /*on lit le deuxième mot. S'il n'y en a pas, la taille du mot sera <1 et  a_complement sera mis à 0 et vice versa. */
    return c;
}

void question1(void){
    char * chaine1 = "       aller sud"; /*renvoie 5*/
    char * chaine2 = "prendre"; /*renvoie 7*/
    char * chaine3 = "Je voudrais trouver le trésor"; /*renvoie 2*/
    char * chaine4 = "aller     sud"; /*renvoie 5*/
    char * chaine5 = "azertyuiopqsdfghjklmwxcvbn1234567 "; /*renvoie 0 car le mot est trop long*/

    int res1 = lire_mot(chaine1,TAILLE_MOT);
    int res2 = lire_mot(chaine2,TAILLE_MOT);
    int res3 = lire_mot(chaine3,TAILLE_MOT);
    int res4 = lire_mot(chaine4,TAILLE_MOT);
    int res5 = lire_mot(chaine5,TAILLE_MOT);

    printf("première chaîne de caractères : %s : %d caractères.\n",chaine1,res1);
    printf("deuxième chaîne de caractères : %s : %d caractères.\n",chaine2,res2);
    printf("troisième chaîne de caractères : %s : %d caractères.\n",chaine3,res3);
    printf("quatrième chaîne de caractères : %s : %d caractères.\n",chaine4,res4);
    printf("cinquième chaîne de caractères : %s : %d caractères.\n",chaine5,res5);


}

joueur nouveau_joueur(void){
    joueur ji; int i;
    ji.lieu_actuel = 1;
    ji.pv = 20;
    for(i=0; i<8; i++){
        ji.inventaire[i] = 0;
    }
    return ji;
}


int mot_vers_direction(char mot[]){ /*retourne la direction correspondante au mot sous forme de int*/
    if(strcmp(mot, "nord") == 0) return 0;
    else if(strcmp(mot,"sud") == 0) return 1;
    else if(strcmp(mot, "est") == 0) return 2;
    else if(strcmp(mot, "ouest") == 0) return 3;
    else return -1;
}

void executer_aller(joueur *j, char complement[]){
    int dir = mot_vers_direction(complement);
    int d=carte[j->lieu_actuel].porte_fermee[dir];
    if(dir == -1){printf("Direction inconnue.\n"); return;}
    d = carte[j->lieu_actuel].sorties[dir];
    if(d == -1){printf("Vous ne pouvez pas aller par là.\n");}
    if(d == 1){printf("La porte est fermée.\n");}
    else {
        j->lieu_actuel = carte[j->lieu_actuel].sorties[dir];
        afficher_lieu(j->lieu_actuel);
    }
}

void executer_prendre(joueur *j){
    if( (carte[j->lieu_actuel].objet_present) != -1 ){ /*s'il y a une clef*/

        j->inventaire[carte[j->lieu_actuel].objet_present] = 1;         /*ajoute l'id de la clef à l'inventaire, dans la case correspondante au lieu*/


        carte[j->lieu_actuel].objet_present = -1; /*retire la clef de l'endroit*/
        printf("Clef saisie.\n");

    }
    else{
        printf("Il n'y a rien à prendre ici.\n");
    }

}

int dir_opp(int d){
    if(d == 0) return 1;
    if(d == 1) return 0;
    if(d == 2) return 3;
    if(d == 3) return 2;
    else return -1;

}






void executer_ouvrir(joueur *j, char complement[]) {
    /* Conversion du mot en direction (ex: "nord" -> 0, etc.) */
    int m = mot_vers_direction(complement);

    /* Direction opposée (utile pour ouvrir la porte dans les deux sens) */
    int d_opposee = dir_opp(m);

    /* Si la direction n'est pas reconnue */
    if (m == -1) {
        printf("Direction inconnue.\n");
        return;  /*on arrête la fonction*/
    }

    /* Vérifie qu'il existe une sortie dans cette direction */
    if (carte[j->lieu_actuel].sorties[m] != -1) {

        /* Vérifie si la porte est fermée */
        if (carte[j->lieu_actuel].porte_fermee[m] == -1) {

            /* Vérifie si le joueur possède la clé correspondante */
            if (j->inventaire[carte[j->lieu_actuel].sorties[m]] == 1) {

                /* Ouvre la porte dans le lieu actuel */
                carte[j->lieu_actuel].porte_fermee[m] = 0;

                /* Ouvre aussi la porte dans le lieu voisin (sens inverse) */
                carte[carte[j->lieu_actuel].sorties[m]].porte_fermee[d_opposee] = 0;

                printf("Porte ouverte !\n");
            }
        }
    }
}
