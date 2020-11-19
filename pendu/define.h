#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED

//constantes
#define NBMOTS 5        //nombre de mots dans le tableau des choix
#define TAILLEMAX 20    //longueur max d'un mot
#define ESSAIS  10      //nombre de tentatives donnees au joueur

//prototypes
    extern void regles();
    extern char lecture();
    extern char *comparaison(int tailleMot, int *compteur, int *gagne,
                             char lettre, char motDevine[], char motRand[]);
    extern void defaite(int compteur, char motRand[]);
    extern int victoire(int tailleMot, char motDevine[], char motRand[]);

    extern void init(int *tailleMot, int *compteur, int *gagne, char *lettre);
    extern char *init_tableau(char motTab[TAILLEMAX]);

    extern char *choixMot(char motTab[TAILLEMAX]);

#endif // DEFINE_H_INCLUDED
