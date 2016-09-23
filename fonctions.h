
typedef enum Genre {
    Horreur,
    Comedie,
    Action,
    Documentaire,
    Policier,
    Drame,
    Animation,
    SF
} Genre;

typedef struct Film{
    char titre[25];
    int anneeDeSortie;
    struct Personne *realisateur;
    struct Personne *acteur[3];
    int duree;
    enum Genre genre;
} Film;

typedef struct Personne{
    char nom[10];
    char prenom[10];
    int dateDeNaissance;
    char nationalite[10];
} Personne;


void writeFilms(struct Film *films, int nbFilms);
void writePersonnes(struct Personne *personnes, int nbPersonnes);
void loadFilms(struct Film *films, int nbFilms);
void loadPersonnes(struct Personne *personnes, int nbPersonnes);
void save(struct Film *films, struct Personne *personnes, int nbFilms, int nbPersonnes);
void loadFile(struct Film *films, struct Personne *personnes, int nbFilms, int nbPersonnes);
void afficherFilm(struct Film);
void creerFilm();
void afficherFilms(struct Film*,int);
void afficherActeurs(struct Personne*, int);
void afficheFilmParActeur(struct Film*,struct Personne*, int,int );
void supprimeFilm();
enum Genre choixGenre();
struct Personne* creerActeur();
struct Personne* consulterActeur();
struct Personne* consulterRealisateur();
struct Personne* creerRealisateur();

void loadNbData(int *nbFilms, int *nbPersonnes);
void writeNbData(int nbFilms, int nbPersonnes);