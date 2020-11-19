#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED

//constantes
#define NBMOTS 5        //nombre de mots dans le tableau des choix
#define TAILLEMAX 20    //longueur max d'un mot
#define ESSAIS  10      //nombre de tentatives donnees au joueur

//prototypes
    extern void choixMot();
    extern void regles();
    extern char lecture();
    extern int comparaison(int tailleMot, char lettre, char motDevine[]);
    extern void defaite();
    extern int victoire(char motDevine[], int tailleMot);

    extern void init(int *tailleMot, int *compteur, int *gagne,
                char *lettre,
                char motRand[TAILLEMAX], char motDevine[TAILLEMAX]);
        extern int init_tailleMot();
        extern int init_compteur();
        extern int init_gagne();
        extern char init_proposition();
        extern char *init_motRand(int motRand[TAILLEMAX]);
        extern char *init_motDevine(int motDevine[TAILLEMAX]);

#endif // DEFINE_H_INCLUDED
