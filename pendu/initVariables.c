#include "define.h"

extern void init(int *tailleMot, int *compteur, char *lettre){

    *tailleMot=0;

    *compteur=ESSAIS;

    *lettre=0;
}


extern void init_tableau(char initMot[TAILLEMAX]){
    int iTemp=0;

    for (iTemp=0; iTemp<TAILLEMAX-1; iTemp++){
        initMot[iTemp]='\0';
    }
}


extern void choixMot(char motTemp[TAILLEMAX]){
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

}
