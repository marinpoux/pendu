#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "define.h"

int main()
{
    //variables
    int i=0;            //compteur d'iteration (boucles)
    int tailleMot=0;    //longueur du mot e deviner
    int compteur=ESSAIS;        // compteur de tentatives restantes
    int gagne=0;        //passe a 1 si le mot est trouve

    char proposition=0;           // lettre proposee par le joueur

    char motRand[TAILLEMAX];    // contient le mot a deviner (selectione aleatoirement)
    char motDevine[TAILLEMAX];  // contient la progression du jour

    //pointeurs
    char *p_motRand;
    char *p_motDevine;

    ///////////////////////////////////

    //initialisation

    init(&tailleMot, &compteur, &gagne, &proposition, &motRand, &motDevine);

    srand(time(NULL));          //initialisation de la generation de nombres aleatoires
    *=choixMot();                 //pioche du mot a deviner

    tailleMot=strlen(motRand);  //determination de la taille du mot a deviner
    //printf("%d\n", tailleMot);

    ///////////////////////////////////

    //algorithme
    printf("LE JEU DU PENDU\n");

    regles();                   //explication des regles

    for (i=0; i<tailleMot; i++){            //generation des '_'
        motDevine[i]='_';
    }
    for (i=tailleMot; i<TAILLEMAX; i++){    //remplissage des cellules "vides"
        motDevine[i]=' ';
    }

    printf("Voici le mot : %s\n", motDevine);


    while ((gagne == 0) && (compteur > 0)){

        proposition=lecture();
        fflush(stdin);

        gagne=comparaison(tailleMot, proposition, motDevine);
    }

    return 0;
}
