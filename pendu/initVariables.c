#include "define.h"

extern void init(int *tailleMot, int *compteur, int *gagne, char *lettre){

    *tailleMot=0;

    *compteur=ESSAIS;

    *gagne=0;

    *lettre=0;
}


extern char *init_tableau(){
    int iTemp=0;
    char initMot[TAILLEMAX];

    for (iTemp=0; iTemp<TAILLEMAX-1; iTemp++){
        initMot[iTemp]=0;
    }
    return initMot;
}


extern char *choixMot(char motTemp[TAILLEMAX]){
    int jTemp=0;
    int nbRand = rand()%NBMOTS;

    char tabMots[NBMOTS][TAILLEMAX]={  //ATTENTION: tenir NBMOTS et TAILLEMAX a jour!!
            "bonjour",
            "couscous",
            "pantoufles",
            "lapin",
            "neurotransmetteur"
            };

    //printf("%d\n", nbRand);

    while ((jTemp<TAILLEMAX) && (tabMots[nbRand][jTemp] != '\0')) {

        motTemp[jTemp] = tabMots[nbRand][jTemp];
        jTemp++;
    }
    //printf("%s\n", motTemp);

    return motTemp;
}
