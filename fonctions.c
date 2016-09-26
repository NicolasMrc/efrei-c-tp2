#include <string.h>
#include <stdlib.h>
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
        printf("Film [%d]\n",i+1);
        afficherFilm(films[i]);
    }
}
void afficherFilm(struct Film films){
    printf("titre:%s\n", films.titre);
    printf("annee de sortie:%d\n", films.anneeDeSortie);
    printf("realisateur:%s\n", films.realisateur.prenom);

    for (int i = 0; i <films.nbActeur ; ++i) {
        printf("acteurs:%s ", films.acteur[i].prenom);
    }
    printf("duree %s min: ",films.duree);


}
void afficherActeurs(struct Personne *personnes, int nbPersonnes){
    for(int i = 0; i < nbPersonnes; i++){
        printf("Acteur [%d]\n",i+1);
        printf("nom: %s - ", personnes[i].nom);
        printf("prenom: %s - ", personnes[i].prenom);
        printf("date de naissance: %d - ", personnes[i].dateDeNaissance);
        printf("nationalite: %s\n", personnes[i].nationalite);
    }
}
void creerFilm(struct Personne *personnes, int nbPersonnes, struct Film *films, int nbFilms){
    struct Film newFilm;
    char titre[30];
    int anneeDeSortie;
    struct Personne realisateur;
    int nbActeur;
    struct Personne acteur[3];
    int duree;
    int choixRealisateur;
    int choixActeur;
    printf("nbFilm %d nbPersonne %d\n",nbFilms,nbPersonnes);
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
            personnes[nbPersonnes]=newFilm.realisateur;
            nbPersonnes++;
            break;
        case 2:
            newFilm.realisateur = consulterRealisateur(personnes, nbPersonnes);
            break;
        default:
            break;
    }
    printf("nbFilm %d nbPersonne %d\n",nbFilms,nbPersonnes);
    printf("Combien d'acteurs y a-t-il:\n");
    scanf("%d",&nbActeur);
    newFilm.nbActeur=nbActeur;
    for (int i = 0; i < nbActeur ; i++) {
        printf("Qui est le %d acteur\n"
                       "1-Creer un acteur\n"
                       "2-Consulter la liste des acteurs\n",i+1);
        scanf("%d",&choixActeur);
        fflush(stdin);
        switch (choixActeur){
            case 1 :
                newFilm.acteur[i]=creerActeur();
                personnes[nbPersonnes] = newFilm.acteur[i];
                nbPersonnes++;
                break;
            case 2:
                newFilm.acteur[i]=consulterActeur(personnes,nbPersonnes);
                break;

            default:
                break;
        }
    }
    printf("Quelle est la durée du film?\n");
    scanf("%d",&duree);
    newFilm.duree=duree;
    printf("Quel est le genre de ce film?\n");
    newFilm.genre=choixGenre();

    films[nbFilms]= newFilm;
    nbFilms++;
    save(films, personnes, nbFilms, nbPersonnes);// Sauvegarde ne remonte pas
    afficherFilm(newFilm);
    printf("\nFilm créer avec succès\n");
}
void afficheFilmParActeur(struct Film *films,struct Personne *personnes, int nbFilms, int nbPersonnes){
    printf("Quel acteur veut tu voir?\n");
    int choixActeur;
    afficherActeurs(personnes,nbPersonnes);
    scanf("%d",&choixActeur);
    fflush(stdin);
    for(int i = 0; i < nbFilms; i++) {
        for (int j = 0; j <films[i].nbActeur ; ++j) {
            if (strcmp(personnes[choixActeur-1].nom, films[i].acteur[j].nom)==0) {//Ne fonctionne pas du au pb des acteurs dans film
                afficherFilm(films[i]);
            }
            else{
                printf("Pas de film de cette acteur");
            }
        }
    }
}
void afficheFilmParRealisateur(struct Film *films,struct Personne *personnes, int nbFilms, int nbPersonnes){
    printf("Quel realisateur veut tu voir?\n");
    int choixActeur;
    afficherActeurs(personnes,nbPersonnes);
    scanf("%d",&choixActeur);
    fflush(stdin);
    for(int i = 0; i < nbFilms; i++) {
            if (strcmp(personnes[choixActeur-1].nom, films[i].realisateur.nom)==0) {//Ne fonctionne pas du au pb des acteurs dans film
                afficherFilm(films[i]);
            }
            else{
                printf("Pas de film de ce realisateur");
            }

    }
}
void supprimeFilm(struct Film *films, int nbFilms, int nbPersonnes){

printf("Quel film voulez vous supprimer?\n");
    afficherFilms(films,nbFilms);
    int choix;
    scanf("%d",&choix);
    films[choix-1]=films[nbFilms];

    nbFilms--;
    writeFilms(films,nbFilms);
    writeNbData(nbFilms,nbPersonnes);
}
char* choixGenre(){
    int i=0;
    printf("Quel genre?\n");
while(listGenre[i]!="0"){
    printf("%d - %s ",i+1,listGenre[i]);
    i++;
}
 int choix;
    scanf("%d",&choix);
    fflush(stdin);
    printf("Genre %s \n",listGenre[choix-1]);
    return listGenre[choix-1];
}
struct Personne creerActeur(){
    struct Personne newActeur;
    int dateDeNais; char natio[15],nom[15],prenom[15];
    printf("Nom de l'acteur?\n");
    scanf("%s",nom);fflush(stdin);
    printf("Prenom de l'acteur?\n");
    scanf("%s",prenom);fflush(stdin);
    printf("Nationalité de l'acteur?\n");
    scanf("%s",natio);fflush(stdin);
    printf("Date de naissance?\n");
    scanf("%d",&dateDeNais);fflush(stdin);
    newActeur.dateDeNaissance = dateDeNais;
    strcpy(newActeur.nationalite, natio);
    strcpy(newActeur.nom, nom);
    strcpy(newActeur.prenom, prenom);
    return newActeur;
}
struct Personne consulterActeur(struct Personne *personnes, int nbPersonnes){
    afficherActeurs(personnes,nbPersonnes);
    printf("Qui est l'acteur?");
    int choixReal;
    scanf("%d",&choixReal);
    return personnes[choixReal-1];
}
struct Personne creerRealisateur(){
    struct Personne newActeur;
    int dateDeNais; char natio[15],nom[15],prenom[15];
    printf("Nom du realisateur\n");
    scanf("%s",nom);fflush(stdin);
    printf("Prenom du realisateur?\n");
    scanf("%s",prenom);fflush(stdin);
    printf("Nationalité du realisateur?\n");
    scanf("%s",natio);fflush(stdin);
    printf("Date de naissance?\n");
    scanf("%d",&dateDeNais);fflush(stdin);
    newActeur.dateDeNaissance = dateDeNais;
    strcpy(newActeur.nationalite, natio);
    strcpy(newActeur.nom, nom);
    strcpy(newActeur.prenom, prenom);
    return newActeur;
}
struct Personne consulterRealisateur(struct Personne *personnes, int nbPersonnes){
    afficherActeurs(personnes,nbPersonnes);
    printf("Qui est le réalisateur?");
    int choixReal;
    scanf("%d",&choixReal);
    return personnes[choixReal-1];
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
        fread(&films[i], sizeof(struct Film), 1, f );
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
        fread(&personnes[i], sizeof(struct Personne), 1, f );
    }
    //afficherActeurs(personnes, nbPersonnes);

    fclose(f);
    printf("\n\n");
}
void loadNbData(int *nbFilms, int *nbPersonnes){
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