#include "define.h"

int main()
{
    //variables
    int i=0;                    //compteur d'iteration (boucles)
    int tailleMot=0;            //longueur du mot e deviner
    int compteur=ESSAIS;        // compteur de tentatives restantes

    char proposition=0;         // lettre proposee par le joueur

    char motRand[TAILLEMAX];    // contient le mot a deviner (selectione aleatoirement)
    char motDevine[TAILLEMAX];  // contient la progression du jour

    //pointeurs


    ///////////////////////////////////

    //initialisation

    init(&tailleMot, &compteur, &proposition);

    init_tableau(motRand);
    init_tableau(motDevine);

    srand(time(NULL));                      //initialisation de la generation de nombres aleatoires
    choixMot(motRand);           //pioche du mot a deviner

    tailleMot = strlen(motRand);            //determination de la taille du mot a deviner
    //printf("%d\n", tailleMot);

    for (i=0; i<tailleMot; i++){            //generation des '_'
        motDevine[i]='_';
    }

    ///////////////////////////////////

    //algorithme
    printf("LE JEU DU PENDU\n");

    regles();

    printf("Voici le mot : %s\n", motDevine);

    while ((strcmp(motDevine, motRand) != 0) && (compteur > 0)){

        proposition = lecture();
        fflush(stdin);

        comparaison(tailleMot, &compteur, proposition, motDevine, motRand);
    }

    defaite(compteur, motRand);

    victoire(motDevine, motRand);

    return 0;
}
