#include "define.h"

extern void init(int *tailleMot, int *compteur, int *gagne, char *lettre){

    *tailleMot=0;

    *compteur=ESSAIS;

    *gagne=0;

    *lettre=0;
}


extern char *init_tableau(char motTab[TAILLEMAX]){
    int iTemp=0;

    for (iTemp=0; iTemp<TAILLEMAX; iTemp++){
        motTab[iTemp]=0;
    }
    return motTab;
}


extern char *choixMot(char motTab[TAILLEMAX]){
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

        motTab[jTemp] = tabMots[nbRand][jTemp];
        jTemp++;
    }
    //printf("%s\n", motTab);

    return motTab;
}
