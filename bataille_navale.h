#ifndef BATAILLE_NAVALE_H
#define BATAILLE_NAVALE_H

enum Laguerre {
    WATER,
    WATER_SHOT,
    BOAT,
    WRECK
};

struct Bateau {
    int taille, indiceX, indiceY, touche, coule, touchecoule;
};

struct Plateau {
    enum Laguerre** endroit;
    int taille;
};

struct Jeu {
    struct Plateau* plateauJoueur;
    struct Plateau* plateauOrdinateur;
    struct Bateau* bateauxJoueur;
    struct Bateau* bateauxOrdinateur;
};

#define NOMBRE_DE_BATEAUX 5
#define TAILLE_DU_PLATEAU 10

struct Bateau* creationdunbateau(int taille, int indiceX, int indiceY);
int encorevivant(struct Bateau* bateau);
struct Plateau* creationdunplateau(int taille);
struct Jeu* creerJeu();
void afficherPlateau(struct Plateau* plateau, int vueJoueur);
void tirer(struct Plateau* plateau, int x, int y, struct Bateau* bateaux, int nbBateaux);
void libererMemoire(struct Jeu* jeu);

#endif /* BATAILLE_NAVALE_H */


