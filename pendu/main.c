#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//constantes
#define NBMOTS 5        //nombre de mots dans le tableau des choix
#define TAILLEMAX 20    //longueur max d'un mot
#define ESSAIS  10      //nombre de tentatives donnees au joueur

//variables globales
    char motRand[TAILLEMAX];    // contient le mot a deviner (selectione aleatoirement)
    int compteur=ESSAIS;        // compteur de tentatives restantes

//prototypes
    void choixMot();
    void regles();
    char lecture();
    int comparaison(int tailleMot, char lettre, char motDevine[]);
    void defaite();
    int victoire(char motDevine[], int tailleMot);


int main()
{
    //variables
    int i=0;            //compteur d'iteration (boucles)
    int tailleMot=0;    //longueur du mot e deviner
    int gagne=0;        //passe a 1 si le mot est trouve

    char proposition=0;           // lettre proposee par le joueur

    char motDevine[TAILLEMAX];  // contient la progression du jour


    //algorithme
    printf("LE JEU DU PENDU\n");

    //init();

    srand(time(NULL));          //initialisation de la generation de nombres aleatoires
    choixMot();                 //pioche du mot a deviner

    tailleMot=strlen(motRand);  //determination de la taille du mot a deviner
    //printf("%d\n", tailleMot);

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
