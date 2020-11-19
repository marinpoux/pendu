#include "define.h"

void choixMot(){
    char tabMots[NBMOTS][TAILLEMAX]={  //ATTENTION: tenir NBMOTS et TAILLEMAX a jour!!
            "bonjour",
            "couscous",
            "pantoufles",
            "lapin",
            "neurotransmetteur"
            };

    int nbRand = rand()%NBMOTS;
    int j=0;

    //printf("%d\n", nbRand);

    while ((j<TAILLEMAX) && (tabMots[nbRand][j] != '\0')) {
    //for (i=0; i<MOTMAX;i++){

        motRand[j] = tabMots[nbRand][j];
        j++;
    }
    //printf("%s\n", motRand);
}


void regles(){

    printf("Vous avez %d essais pour reussir a deviner le mot cache !\n", ESSAIS);

}


char lecture(){
    char lettre;

    printf("Proposez une lettre !\n");
    scanf("%c", &lettre);

    return lettre;
}


int comparaison(int tailleMot, char lettre, char motDevine[]){
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

        compteur--;
        printf("Non, le mot ne contient pas la lettre %c !\nIl vous reste %d essais !\n", lettre, compteur);
    }

    printf_s(motDevine);

    defaite();

    if (victoire(motDevine, tailleMot)){

        return 1;
    } else {
        return 0;
    }
}


void defaite(){

    if (compteur == 0){

        printf("Dommage, vous avez perdu !\nLe mot etait '%s' !\n", motRand);
    }
}

int victoire(char motDevine[], int tailleMot){
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
