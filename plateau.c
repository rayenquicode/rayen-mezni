// plateau.c
#include <stdio.h>
#include "plateau.h"
#include <stdlib.h>

struct Plateau* creationdunplateau(int taille) {
    struct Plateau* plateau = malloc(sizeof(struct Plateau));
    plateau->taille = taille;
    plateau->endroit = malloc(taille * sizeof(enum Laguerre*));

    for (int i = 0; i < taille; i++) {
        plateau->endroit[i] = malloc(taille * sizeof(enum Laguerre));
        for (int i1 = 0; i1 < taille; i1++) {
            plateau->endroit[i][i1] = WATER;
        }
    }

    return plateau;
}

//displays the board
void afficherPlateau(struct Plateau* plateau, int a) {
    for (int i = 0; i < plateau->taille; i++) {// Loop to traverse the board lines
        // Loop to go through the columns of the board
        for (int j = 0; j < plateau->taille; j++) {
            char dessin= 'e';
	    if (a || plateau->endroit[i][j] == WATER_SHOT ||
		plateau->endroit[i][j] == WRECK) {
            if (plateau->endroit[i][j] 
                == WATER) {
                    dessin = 'e';
                } else {
                    dessin = '#';
                }
            }printf("%c ", dessin);
        }
        printf("\n \n");
}}

//Function to perform a shot on the game board.
void tirer(struct Plateau* plateau, int x, int y, struct Bateau* bateaux, int nbBateaux) {
    //if we use coordinates greater than 9
    if (x < 0 || x >= 9 || y < 0 || y >= 9) {
        printf("Il faut tirer dans la limite du plateau :)\n");
        return;}// Check if the target location has already been shot or contains a wreck
	if (plateau->endroit[x][y] == WATER_SHOT || plateau->endroit[x][y] == WRECK) {
        printf("Tu as déjà tiré ici, tu viens de perdre un tour :(\n");
        return;}
	plateau->endroit[x][y] = WATER_SHOT;
   for (int i = 0; i < nbBateaux; i++) {
        if (x == bateaux[i].indiceX && y == bateaux[i].indiceY) {
            bateaux[i].touche++;
            if (encorevivant(&bateaux[i])) {
                printf("Touché !\n");
            } else {
                printf("Coulé !\n");
                plateau->endroit[x][y] = WRECK;
            }
            return;
        }}
   printf("C'est raté\n");
}
