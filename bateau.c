// bateau.c

#include "bateau.h"
#include <stdlib.h>

struct Bateau* creationdunbateau(int taille, int indiceX, int indiceY) {
    struct Bateau* bateau = malloc(sizeof(struct Bateau));
    bateau->taille = taille;
    bateau->indiceX = indiceX;
    bateau->indiceY = indiceY;
    bateau->touche = 0;

    return bateau;
}

int encorevivant(struct Bateau* bateau) {
    return bateau->touche < bateau->taille;
}

