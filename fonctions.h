
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
    char* titre;
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

void creerFilm();
void afficherFilm();
void afficheFilmParActeur();
void afficheFilmParRealisateur();
void supprimeFilm();
enum Genre choixGenre();
struct Personne* creerActeur();
struct Personne* consulterActeur();
struct Personne* consulterRealisateur();
struct Personne* creerRealisateur();

void loadNbData(int *nbFilms, int *nbPersonnes);
void writeNbData(int nbFilms, int nbPersonnes);