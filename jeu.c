// jeu.c

#include "jeu.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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


