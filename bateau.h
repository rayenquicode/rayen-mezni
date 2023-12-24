// bateau.h

#ifndef BATEAU_H
#define BATEAU_H

struct Bateau {
    int taille, indiceX, indiceY, touche, coule, touchecoule;
};

struct Bateau* creationdunbateau(int taille, int indiceX, int indiceY);
int encorevivant(struct Bateau* bateau);

#endif // BATEAU_H

