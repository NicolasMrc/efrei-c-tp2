#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fonctions.h"

int afficherFilm(){
    return 0;
}

void creerFilm(){
    struct Film newFilm;
    char titre[30];
    int anneeDeSortie;
    //struct Personne realisateur;
    int nbActeur;
    //struct Personne acteur[3];
    int duree;
    //enum Genre genre;
    int choixRealisateur;
    int choixActeur;

    printf("Interface de creation de film\n"
                   "-------------------------------------------------\n"
                   "1-Quel est son titre?\n");
    scanf("%s",titre);
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
        default:
            break;
    }
    printf("Combien d'acteurs y a-t-il:\n");
    scanf("%d",&nbActeur);
    for (int i = 0; i < nbActeur ; ++i) {
        printf("Quels sont les acteurs\n"
                       "1-Choisir parmi la liste\n"
                       "2-Creer un acteur\n");
        scanf("%d",&choixActeur);
        fflush(stdin);
        switch (choixActeur){
            case 1 :
                newFilm.acteur[i]=consulterActeur();
            case 2:
                newFilm.acteur[i]=creerActeur();
            default:
                break;
        }
    }
    printf("Quelle est la durée du film?\n");
    scanf("%d",&duree);
    newFilm.duree=duree;
    printf("Quel est le genre de ce film?\n");
    newFilm.genre=choixGenre();
    printf("Film créer avec succès");
}

void afficheFilmParActeur(){

}

void afficheFilmParRealisateur(){

}

void supprimeFilm(){

}

enum Genre choixGenre(){
    return Action;
}

struct Personne* creerActeur(){
    struct Personne *newActeur = malloc(sizeof(Personne));
    newActeur->dateDeNaissance = 2;
    strcpy(newActeur->nationalite, "fr");
    strcpy(newActeur->nom, "Norris");
    strcpy(newActeur->prenom, "Chuck");
    return newActeur;
}

struct Personne* consulterActeur(){
    struct Personne *newActeur = malloc(sizeof(Personne));
    newActeur->dateDeNaissance = 2;
    strcpy(newActeur->nationalite, "fr");
    strcpy(newActeur->nom, "Norris");
    strcpy(newActeur->prenom, "Chuck");
    return newActeur;
}

struct Personne* creerRealisateur(){
    struct Personne *newActeur = malloc(sizeof(Personne));
    newActeur->dateDeNaissance = 2;
    strcpy(newActeur->nationalite, "fr");
    strcpy(newActeur->nom, "Norris");
    strcpy(newActeur->prenom, "Chuck");
    return newActeur;
}

struct Personne* consulterRealisateur(){
    struct Personne *newActeur = malloc(sizeof(Personne));
    newActeur->dateDeNaissance = 2;
    strcpy(newActeur->nationalite, "fr");
    strcpy(newActeur->nom, "Norris");
    strcpy(newActeur->prenom, "Chuck");
    return newActeur;
}

/**
 * Methode permettant de sauvegarder les films et les personnes dans des fichiers text
 * @param films
 *      le tableau de film
 * @param personnes
 *      le tableau de personne
 */
void save(struct Film *films, struct Personne *personnes, int nbFilms, int nbPersonnes){
    writeFilms(films, nbFilms);
    writePersonnes(personnes, nbPersonnes);
}


/**
 * methode permettant d'initialiser les tableaux de films et de personnes avec les
 * données contenues dans les fichier text
 * @param films
 *      le tableau de films
 * @param personnes
 *      le tableau de personnes
 */
void loadFile(struct Film *films, struct Personne *personnes){
    loadFilms(films);
    loadPersonnes(personnes);
}

/**
 * Permet de sauvegarder dans un fichier films.txt les films du tableaux
 * @param films
 * @param nbFilms
 */
void writeFilms(struct Film *films, int nbFilms){
    for(int i = 0; i < nbFilms ; i++) {
        FILE *f = fopen("/Users/Nico/Desktop/EFREI/C C++/TP2/films.txt", "w");
        if (f == NULL) {
            printf("Error opening file!\n");
        }

        fwrite(&films[i], sizeof(films), 1, f);

        fclose(f);
    }
}

/**
 * methode permettant d'ecrire dans le fichier personnes.txt la liste des personnes
 * @param personnes
 *          le tableau de personnes
 */
void writePersonnes(struct Personne *personnes, int nbPersonnes){
    for(int i = 0; i < nbPersonnes ; i++) {
        FILE *f = fopen("/Users/Nico/Desktop/EFREI/C C++/TP2/personnes.txt", "r");
        if (f == NULL) {
            printf("Error opening file!\n");
        }

        fwrite(&personnes[i], sizeof(personnes), 1, f);

        fclose(f);
    }
}

/**
 * Methode permettant de charger la liste de films d'apres le fichier fimls.txt
 * @param films
 *      le tableau de films
 */
void loadFilms(struct Film *films){
    for(int i = 0; i < 100 ; i++) {
        FILE *f = fopen("/Users/Nico/Desktop/EFREI/C C++/TP2/films.txt", "r");
        if (f == NULL) {
            printf("Error opening Films file!\n");
        }

        fread(&films[i], sizeof(films), 1, f );
        printf("titre:%s\n", films[i].titre);
        printf("annee de sortie:%d\n", films[i].anneeDeSortie);
        printf("realisateurs:%p\n", films[i].realisateur);
        printf("acteurs:%p\n", films[i].acteur);

        fclose(f);
    }
}

/**
 * methode permettant de charge la liste de personnes enregistrées dans le fichier personnes.txt
 * @param personnes
 *      le tableau de personnes
 */
void loadPersonnes(struct Personne *personnes){
    for(int i = 0; i < 100 ; i++) {
        FILE *f = fopen("/Users/Nico/Desktop/EFREI/C C++/TP2/personnes.txt", "r");
        if (f == NULL) {
            printf("Error opening Personnes file!\n");
        }

        fread(&personnes[i], sizeof(personnes), 1, f );
        printf("nom:%s\n", personnes[i].nom);
        printf("prenom:%s\n", personnes[i].prenom);
        printf("date de naissance:%d\n", personnes[i].dateDeNaissance);
        printf("nationalité:%s\n", personnes[i].nationalite);

        fclose(f);
    }
}