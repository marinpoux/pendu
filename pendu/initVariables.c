#include "define.h"

extern void init(int *tailleMot, int *compteur, int *gagne,
                char *lettre,
                char motRand[TAILLEMAX], char motDevine[TAILLEMAX]){

    *tailleMot=init_tailleMot();

    *compteur=init_compteur();

    *gagne=init_gagne();

    *lettre=init_proposition();

    *motRand=init_motRand(int motRand[TAILLEMAX]);

    *motDevine=init_motDevine(int motDevine[TAILLEMAX]);


}

extern int init_tailleMot(){
    return 0;
}

extern int init_compteur(){
    return ESSAIS;
}

extern int init_gagne(){
    return 0;
}

extern char init_proposition(int lettre){
    return 0;
}

extern char *init_motRand(int motRand[TAILLEMAX]){
    int iTemp=0;

    for (iTemp=0; iTemp<TAILLEMAX; iTemp++){
        motRand[iTemp]=0;
    }
    return motRand;
}

extern char *init_motDevine(int motDevine[TAILLEMAX]){
    int iTemp=0;

    for (iTemp=0; iTemp<TAILLEMAX; iTemp++){
        motDevine[iTemp]=0;
    }
    return motDevine;
}
