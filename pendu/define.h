#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//constantes
#define NBMOTS 5        //nombre de mots dans le tableau des choix
#define TAILLEMAX 20    //longueur max d'un mot
#define ESSAIS  10      //nombre de tentatives donnees au joueur

//prototypes
    extern void regles();
    extern char lecture();
    extern void comparaison(int tailleMot, int *compteur, char lettre,
                             char motDevine[], char motRand[]);
    extern void defaite(int compteur, char motRand[]);
    extern void victoire(char motDevine[], char motRand[]);

    extern void init(int *tailleMot, int *compteur, char *lettre);
    extern void init_tableau(char initMot[TAILLEMAX]);

    extern void choixMot(char motTemp[TAILLEMAX]);
    extern int rand();

#endif // DEFINE_H_INCLUDED
