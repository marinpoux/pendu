#include "define.h"

extern void regles(){

    printf("Vous avez %d essais pour reussir a deviner le mot cache !\n", ESSAIS);

}


extern char lecture(){
    char lettre;

    printf("Proposez une lettre !\n");
    scanf("%c", &lettre);

    return lettre;
}


extern char *comparaison(int tailleMot, int *compteur, int *gagne, char lettre, char motDevine[], char motRand[]){
    int j=0;
    int oui=0;                          //incrementation si la lettre est contenue

    for (j=0; j< tailleMot; j++){

        if (lettre == motRand[j]){

            motDevine[j]=lettre;
            oui++;
        }
    }

    if (oui > 0) {

        printf("Oui, le mot contient la lettre %c !\n", lettre);
    } else {

        *compteur--;
        printf("Non, le mot ne contient pas la lettre %c !\nIl vous reste %d essais !\n", lettre, compteur);
    }

    printf_s(motDevine);

    defaite(compteur, motRand);

    if (victoire(tailleMot, motDevine, motRand)){

        *gagne=1;
    }

    return motDevine;
}


extern void defaite(int compteur, char motRand[]){

    if (compteur == 0){

        printf("Dommage, vous avez perdu !\nLe mot etait '%s' !\n", motRand);
    }
}

extern int victoire(int tailleMot, char motDevine[], char motRand[]){
    int k=0;

    while (motDevine[k] == motRand[k]){

        k++;
    }

    if (k == tailleMot){

        printf("Bravo, vous avez trouve !\nLe mot etait bien '%s' !\n", motRand);

        return 1;
    } else {

        return 0;
    }
}
