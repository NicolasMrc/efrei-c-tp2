#include <stdio.h>
#include "fonctions.h"

afficherFilm(){

}

creerFilm(){
    struct Film newFilm;
    char* titre;
    int anneeDeSortie;
    struct Personne realisateur;
    int nbActeur;
    struct Personne acteur[3];
    int duree;
    enum Genre genre;
    int choixRealisateur;
    int choixActeur;

    printf("Interface de creation de film\n"
                   "-------------------------------------------------\n"
                   "1-Quel est son titre?\n");
    scanf("%s",&titre);
    strcpy(newFilm.titre,titre);
    printf("2-L'annee de sa sortie\n");
    scanf("%d",&anneeDeSortie);
    newFilm.anneeDeSortie = anneeDeSortie;
    printf("Le realisateur\n"
                   "1-Creer un realisateur\n"
                   "2-Choisir parmi la liste\n");
    scanf("%d",&choixRealisateur);
    switch (choixRealisateur){
        case 1:
            newFilm.realisateur=creerRealisateur();
        case 2:
            newFilm.realisateur=consulterRealisateur();
    }
    printf("Combien d'acteurs y a-t-il:\n");
    scanf("%d",nbActeur);
    for (int i = 0; i < nbActeur ; ++i) {
        printf("Quels sont les acteurs\n"
                       "1-Choisir parmi la liste\n"
                       "2-Creer un acteur\n");
        scanf("%d",choixActeur);
        fflush(stdin);
        switch (choixActeur){
            case 1 :
                newFilm.acteur[i]=consulterActeur();
            case 2:
                newFilm.acteur[i]=creerActeur();
        }
    }
    printf("Quelle est la durée du film?\n");
    scanf("%d",duree);
    newFilm.duree=duree;
    printf("Quel est le genre de ce film?\n");
    newFilm.genre=choixGenre();
    printf("Film créer avec succès");
}
