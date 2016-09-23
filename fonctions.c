#include <string.h>
#include <stdlib.h>
#include <libintl.h>
#include <string.h>
#include "fonctions.h"
#include <stdio.h>
/*
char fileFilm ="/Users/Nico/Desktop/EFREI/C C++/TP2/films.txt";
char filePersonne="/Users/Nico/Desktop/EFREI/C C++/TP2/personnes.txt";
char fileData="/Users/Nico/Desktop/EFREI/C C++/TP2/nbData.txt";
*/
char fileFilm[] ="C:\\Users\\ben_s\\ClionProjects\\efrei-c-tp2\\films.txt";
char filePersonne[]="C:\\Users\\ben_s\\ClionProjects\\efrei-c-tp2\\personnes.txt";
char fileData[]="C:\\Users\\ben_s\\ClionProjects\\efrei-c-tp2\\nbData.txt";

void afficherFilms(struct Film *films, int nbFilms){
    for(int i = 0; i < nbFilms; i++) {
        afficherFilm(films[i]);
    }
}
void afficherFilm(struct Film films){
    printf("lol");
    printf("titre:%s\n", films.titre);
    printf("annee de sortie:%d\n", films.anneeDeSortie);
    printf("realisateur:%s\n", films.realisateur->prenom);
    printf("acteurs:%s, ", films.acteur[0]->prenom);
    printf("%s\n\n", films.acteur[1]->prenom);
}
void afficherActeurs(struct Personne *personnes, int nbPersonnes){// A modifier pour le choix
    for(int i = 0; i < nbPersonnes; i++){
        printf("Acteur [%d]\n",i+1);
        printf("nom: %s - ", personnes[i].nom);
        printf("prenom: %s - ", personnes[i].prenom);
        printf("date de naissance: %d - ", personnes[i].dateDeNaissance);
        printf("nationalite: %s\n", personnes[i].nationalite);
    }
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
void afficheFilmParActeur(struct Film *films,struct Personne *personnes, int nbFilms, int nbPersonnes){
    printf("Quelle acteurs veut tu voir?\n");
    int choixActeur;
    afficherActeurs(personnes,nbPersonnes);
    scanf("%d",&choixActeur);
    for(int i = 0; i < nbFilms; i++) {
        for (int j = 0; j <2 ; ++j) {
            if (strcmp(personnes[choixActeur].nom, films[i].acteur[j]->nom)) {
                printf("titre:%s\n", films[i].titre);
                printf("annee de sortie:%d\n", films[i].anneeDeSortie);
                printf("realisateur:%s\n", films[i].realisateur->prenom);
                printf("acteurs:%s, ", films[i].acteur[0]->prenom);
                printf("%s\n\n", films[i].acteur[1]->prenom);
            }
        }
    }

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
    writeNbData(nbFilms, nbPersonnes);
}
/**
 * methode permettant d'initialiser les tableaux de films et de personnes avec les
 * données contenues dans les fichier text
 * @param films
 *      le tableau de films
 * @param personnes
 *      le tableau de personnes
 */
void loadFile(struct Film *films, struct Personne *personnes, int nbFilms, int nbPersonnes){
    loadPersonnes(personnes, nbPersonnes);
    loadFilms(films, nbFilms);
}
/**
 * Permet de sauvegarder dans un fichier films.txt les films du tableaux
 * @param films
 * @param nbFilms
 */
void writeFilms(struct Film *films, int nbFilms){
    FILE *f = fopen(fileFilm, "w+");
    if (f == NULL) {
        printf("Error opening file!\n");
    } else{
        for(int i = 0; i < nbFilms ; i++) {
            fwrite(&films[i], sizeof(struct Film), 1, f);
        }
    }
    fclose(f);
}
/**
 * methode permettant d'ecrire dans le fichier personnes.txt la liste des personnes
 * @param personnes
 *          le tableau de personnes
 */
void writePersonnes(struct Personne *personnes, int nbPersonnes){

    FILE *f = fopen(filePersonne, "w+");
    if (f == NULL) {
        printf("Error opening file!\n");
    } else{
        for(int i = 0; i < nbPersonnes ; i++) {
            fwrite(&personnes[i], sizeof(struct Personne), 1, f);
        }
    }
    fclose(f);
}
/**
 * Methode permettant de charger la liste de films d'apres le fichier fimls.txt
 * @param films
 *      le tableau de films
 */
void loadFilms(struct Film *films, int nbFilms){
    FILE *f = fopen(fileFilm, "r+");
    if (f == NULL) {
        printf("Error opening Films file!\n");
    }

    for(int i = 0; i < nbFilms; i++){
        fread(&films[i], sizeof(films), 1, f );
    }
    //afficherFilms(films, nbFilms);

    fclose(f);
}
/**
 * methode permettant de charge la liste de personnes enregistrées dans le fichier personnes.txt
 * @param personnes
 *      le tableau de personnes
 */
void loadPersonnes(struct Personne *personnes, int nbPersonnes){
    FILE *f = fopen(filePersonne, "r+");
    if (f == NULL) {
        printf("Error opening Personnes file!\n");
    }

    for(int i = 0; i < nbPersonnes; i++){
        fread(&personnes[i], sizeof(personnes), 1, f );
    }
    //afficherActeur(personnes, nbPersonnes);

    fclose(f);
    printf("\n\n");
}
void loadNbData(int *nbPersonnes, int *nbFilms){
    FILE *f = fopen(fileData, "r+");
    if (f == NULL) {
        printf("Error opening Personnes file!\n");
    } else{
        fread(nbFilms, sizeof(int), 1, f );
        fread(nbPersonnes, sizeof(int), 1, f );
    }

    fclose(f);
}
void writeNbData(int nbFilms, int nbPersonnes){
    FILE *f = fopen(fileData, "w+");
    if (f == NULL) {
        printf("Error opening file!\n");
    } else{
        fwrite(&nbFilms, sizeof(int), 1, f);
        fwrite(&nbPersonnes, sizeof(int), 1, f);
    }
    fclose(f);
}