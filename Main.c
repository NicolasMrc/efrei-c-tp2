#include "fonctions.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    struct Film films[100];
    struct Personne personnes[100];

    struct Film film;
    struct Personne personne;

    int nbFilms = 1, nbPersonnes = 2;

    //loadNbData(&nbFilms, &nbPersonnes);

    strcpy(personne.prenom, "Zora");
    strcpy(personne.nom, "Explorer");
    strcpy(personne.nationalite, "Francais");
    personne.dateDeNaissance = 1995;

    struct Personne personne2;

    strcpy(personne2.prenom, "Nico");
    strcpy(personne2.nom, "Mrc");
    strcpy(personne2.nationalite, "Francais");
    personne2.dateDeNaissance = 1995;


    film.acteur[0] = &personne2;
    film.acteur[1] = &personne;
    film.anneeDeSortie = 2016;
    film.duree = 122;
    film.genre = Action;
    film.realisateur = &personne;
    strcpy(film.titre, "Zora l'exploratrice");

    films[0] = film;
    personnes[0] = personne;
    personnes[1] = personne2;

    loadFile(films, personnes, nbFilms, nbPersonnes);
    //save(films, personnes, nbFilms, nbPersonnes);



    printf("Welcome\n");//Bienvenue
    int choix;
    printf("1-Consulter un film\n"
                   "2-Creer un film\n"
                   "3-Supprimer un film\n");
    scanf("%d",&choix);
    fflush(stdin);
    switch(choix){
        case 1:
            printf("1-Consulter tous les films\n"
                           "2-Consulter les films d'un acteur\n"
                           "3-Consulter les films d'un realisateur\n");
            int choix2;
            scanf("%d", &choix2);
            switch (choix2){
                case 1:
                    afficherFilm();
                case 2:
                    afficheFilmParActeur();
                case 3:
                    afficheFilmParRealisateur();
                default:
                    break;
            }
        case 2:
            creerFilm();
        case 3:
            supprimeFilm();
        default:
            break;
    }
}


