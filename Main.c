#include "fonctions.c"

int main() {
    struct Film films[100];
    struct Personne personnes[100];
    loadFile(films, personnes);
    int nbFilms = 100, nbPersonnes = 100;

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

    save(films, personnes, nbFilms, nbPersonnes);
}


