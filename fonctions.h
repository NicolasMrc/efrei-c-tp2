#include <wtypes.h>

typedef struct Film{
    char* titre;
    int anneeDeSortie;
    struct Personne realisateur;
    struct Personne acteur[3];
    int duree;
    enum Genre genre;
};

typedef struct Personne{
    char nom[10];
    char prenom[10];
    DATE dateDeNaissance;
    char nationalite[10];
};

enum Genre{Horreur, Comedie, Action, Documentaire, Policier, Drame, Animation, SF};