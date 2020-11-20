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


extern void comparaison(int tailleMot, int *compteur, char lettre, char motDevine[], char motRand[]){
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
        printf("%s\n",motDevine);

    } else {

        (*compteur)--;
        printf("Non, le mot ne contient pas la lettre %c !\nIl vous reste %d essais !\n", lettre, *compteur);
    }
}


extern void defaite(int compteur, char motRand[]){

    if (compteur == 0){

        printf("Dommage, vous avez perdu !\nLe mot etait '%s' !\n", motRand);
    }
}

extern void victoire(char motDevine[], char motRand[]){

    if (strcmp(motDevine, motRand) == 0){

        printf("Bravo, vous avez trouve !\n");
    }
}
