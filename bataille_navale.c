#include "bataille_navale.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// struct for creation of boat
struct Bateau* creationdunbateau(int taille, int indiceX, int indiceY) {
    struct Bateau* bateau = malloc(sizeof(struct Bateau));
    bateau->taille = taille;
    bateau->indiceX = indiceX;
    bateau->indiceY = indiceY;
    bateau->touche = 0;

    return bateau;
}

// to find out if a boat is still alive
int encorevivant(struct Bateau* bateau) {
    return bateau->touche < bateau->taille;
}

// for create the plateau
struct Plateau* creationdunplateau(int taille) {
    struct Plateau* plateau = malloc(sizeof(struct Plateau)); // Dynamically allocates memory for an instance of the Plateau structure
    plateau->taille = taille; // Initializes the size of the tray with the value passed as a parameter
    plateau->endroit = malloc(taille * sizeof(enum Laguerre*)); // allocate memory for table rows
    for (int i = 0; i < taille; i++) {
        plateau->endroit[i] = malloc(taille * sizeof(enum Laguerre));
	for (int i1 = 0; i1 < taille; i1++) {
            plateau->endroit[i][i1] = WATER;
        }
    }

    return plateau;
}

struct Jeu* creerJeu() {  // returns a pointer to a struct structure Game
    struct Jeu* jeu = malloc(sizeof(struct Jeu));
    // Creates the game board for the player using the creationdunplatau function
    jeu->plateauJoueur = creationdunplateau(TAILLE_DU_PLATEAU); // Creates the game board for the computer using the creationdunplateau function
    jeu->plateauOrdinateur = creationdunplateau(TAILLE_DU_PLATEAU);// Dynamically allocate memory for the player's boat array
    jeu->bateauxJoueur = malloc(NOMBRE_DE_BATEAUX * sizeof(struct Bateau));
    // Dynamically allocates memory for the computer's boat array
    jeu->bateauxOrdinateur = malloc(NOMBRE_DE_BATEAUX * sizeof(struct Bateau));
    srand(time(NULL));
    // Loop to create and position boats for player and computer
    for (int i = 0; i < NOMBRE_DE_BATEAUX; i++) {
    // Creates a player boat with increasing size 
        jeu->bateauxJoueur[i] = *creationdunbateau(i + 2, rand() % TAILLE_DU_PLATEAU, rand() % TAILLE_DU_PLATEAU);
        // Creates a boat for the computer with increasing size 
        jeu->bateauxOrdinateur[i] = *creationdunbateau(i + 2, rand() % TAILLE_DU_PLATEAU, rand() % TAILLE_DU_PLATEAU);
    }

    return jeu;
}

//displays the board
void afficherPlateau(struct Plateau* plateau, int a) {
    for (int i = 0; i < plateau->taille; i++) {// Loop to traverse the board lines
        // Loop to go through the columns of the board
        for (int j = 0; j < plateau->taille; j++) {
            char dessin= '+';
	    if (a || plateau->endroit[i][j] == WATER_SHOT ||
		plateau->endroit[i][j] == WRECK) {
            if (plateau->endroit[i][j] 
                == WATER) {
                    dessin = '+';
                } else {
                    dessin = 'T';
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

// free the memory
void libererMemoire(struct Jeu* jeu) {
    for (int i = 0; i < jeu->plateauJoueur->taille; i++) {
        free(jeu->plateauJoueur->endroit[i]);
        free(jeu->plateauOrdinateur->endroit[i]);
    }
free(jeu->plateauJoueur->endroit);
free(jeu->plateauJoueur);
free(jeu->plateauOrdinateur->endroit);
free(jeu->plateauOrdinateur);
free(jeu->bateauxJoueur);    free(jeu->bateauxOrdinateur);
free(jeu);
}

