// plateau.h

#ifndef PLATEAU_H
#define PLATEAU_H

#include "jeu.h"

enum Laguerre {
    WATER,
    WATER_SHOT,
    BOAT,
    WRECK
};

struct Plateau {
    enum Laguerre** endroit;
    int taille;
};

struct Plateau* creationdunplateau(int taille);
void afficherPlateau(struct Plateau* plateau, int a);
void tirer(struct Plateau* plateau, int x, int y, struct Bateau* bateaux, int nbBateaux);

#endif // PLATEAU_H

