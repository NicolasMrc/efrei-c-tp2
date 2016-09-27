//---------------------------Variable à modifier pour lire le fichier-------------------///
//Linux
/*
static char fileFilm[] ="/Users/Nico/Desktop/EFREI/C C++/TP2/films.txt";
static char filePersonne[]="/Users/Nico/Desktop/EFREI/C C++/TP2/personnes.txt";
static char fileData[]="/Users/Nico/Desktop/EFREI/C C++/TP2/nbData.txt";
 */
//Windows
static char fileFilm[] ="C:\\Users\\ben_s\\ClionProjects\\efrei-c-tp2\\films.txt";
static char filePersonne[]="C:\\Users\\ben_s\\ClionProjects\\efrei-c-tp2\\personnes.txt";
static char fileData[]="C:\\Users\\ben_s\\ClionProjects\\efrei-c-tp2\\nbData.txt";
//-------------------------------------------------------------------------------------///

static char *listGenre[] = {
        "Horreur",
        "Comedie",
        "Action",
        "Documentaire",
        "policier",
        "Drame",
        "SF",
        "0"
};
typedef struct Personne{
    char nom[10];
    char prenom[10];
    int dateDeNaissance;
    char nationalite[10];
} Personne;
typedef struct Film{
    char titre[25];
    int anneeDeSortie;
    struct Personne realisateur;
    int nbActeur;
    struct Personne acteur[3];
    int duree;
    char *genre;
} Film;




void writeFilms(struct Film *films, int nbFilms);
void writePersonnes(struct Personne *personnes, int nbPersonnes );
void loadFilms(struct Film *films, int nbFilms);
void loadPersonnes(struct Personne *personnes, int nbPersonnes);
void save(struct Film *films, struct Personne *personnes, int nbFilms, int nbPersonnes);
void loadFile(struct Film *films, struct Personne *personnes, int nbFilms, int nbPersonnes);
void afficherFilm(struct Film);
void creerFilm(struct Personne*, int, struct Film*, int);
void afficherFilms(struct Film*,int);
void afficherActeurs(struct Personne*, int);
void afficheFilmParActeur(struct Film*,struct Personne*, int,int );
void afficheFilmParRealisateur(struct Film*,struct Personne*, int,int );
void supprimeFilm(struct Film *films, int nbFilms, int);
void afficherTitres(struct Film*, int);
void modifierFilm(struct Film*, int, struct Personne*, int);
char* choixGenre();
struct Personne creerActeur();
struct Personne consulterActeur(struct Personne*, int);
struct Personne consulterRealisateur(struct Personne*, int);
struct Personne creerRealisateur();

void loadNbData(int *nbFilms, int *nbPersonnes);
void writeNbData(int nbFilms, int nbPersonnes);