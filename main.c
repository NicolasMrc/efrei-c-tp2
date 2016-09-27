#include "fonctions.h"
#include <stdio.h>
#include <string.h>

int main() {
    struct Film films[100];
    struct Personne personnes[100];
    int nbFilms, nbPersonnes;

    loadNbData(&nbFilms, &nbPersonnes);
    loadFile(films, personnes, nbFilms, nbPersonnes);

    printf(" ||====================================================================|| \n");
    printf(" ||// \\\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\// \\\\|| \n");
    printf(" ||( o )==================|    FILM DATABASE     |================( o )|| \n");
    printf(" ||\\\\ //                  '------========--------'                \\\\ //|| \n");
    printf(" ||<< /        /o\\              // ____ \\\\           /o\\           \\ >>|| \n");
    printf(" ||>>|        //|\\\\            // ///..) \\\\         //|\\\\           |<<|| \n");
    printf(" ||<<|        \\\\|//           || <||  >\\  ||        \\\\|//           |>>|| \n");
    printf(" ||>>|         \\o/            ||  \\\\ --/  ||         \\o/            |<<|| \n");
    printf(" ||<<|                        *\\\\  |\\_/  //*                        |>>|| \n");
    printf(" ||>>|                         *\\\\/___\\_//*                         |<<|| \n");
    printf(" ||<<\\                    _____/  WELCOME \\________                 />>|| \n");
    printf(" ||// \\                 ~|       ENJOY OUR        |~               / \\\\|| \n");
    printf(" ||( o )===================   AWESOME PROGRAMM   =================( o )|| \n");
    printf(" ||\\\\ //\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\\ //|| \n");
    printf(" ||====================================================================|| \n");

    int choix;
    printf("1-Consulter un film\n"
                   "2-Creer un film\n"
                   "3-Supprimer un film\n"
                   "4-Modifier un film\n");
    scanf("%d",&choix);
    fflush(stdin);
    switch(choix){
        case 1:
            printf("1-Consulter tous les films\n"
                           "2-Consulter les films d'un acteur\n"
                           "3-Consulter les fils d'un realisateur\n");
            int choix2;
            scanf("%d", &choix2);
            switch (choix2){
                case 1:
                    afficherFilms(films,nbFilms);
                    break;
                case 2:
                    afficheFilmParActeur(films,personnes,nbFilms,nbPersonnes);
                    break;
                case 3:
                    afficheFilmParRealisateur(films,personnes,nbFilms,nbPersonnes);
                default:
                    break;
            }
            break;
        case 2:
            creerFilm(personnes,nbPersonnes,films, nbFilms);
            afficherFilms(films, nbFilms);
            break;
        case 3:
            supprimeFilm(films, nbFilms, nbPersonnes);
            break;
        case 4:
            modifierFilm(films, nbFilms, personnes, nbPersonnes);
            break;
        default:
            break;
    }
    int restart;
    printf("\nSouhaitez vous réalisé une autre commande ?\n"
                   "1-Oui\n"
                   "2-Non\n");
    scanf("%d",&restart);
    switch (restart){
        case 1:
            main();
        default:
            break;
    }
}


