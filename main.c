#include "bataille_navale.h"
#include <stdio.h>
#include <stdlib.h> 

int main() {
    struct Jeu* jeu = creerJeu();

     printf("Here we go mario\n");

    // it's for main game loop
    for (;;) {
        // this is for Show the trays
        printf("\n Joueur \n");
        afficherPlateau(jeu->plateauJoueur, 1);
	printf("\n Ordinateur \n");
        afficherPlateau(jeu->plateauOrdinateur, 0);
	printf("\nTour Joueur :\n");
        int x, y;
        printf(" Choisissez un Tir avec un espace entre chaque chiffre: ");
        scanf("%d %d", &x, &y);
        tirer(jeu->plateauOrdinateur, x, y, jeu->bateauxOrdinateur, NOMBRE_DE_BATEAUX);

        // to check if we won
        int joueurGagnant = 1;
        for (int i = 0; i < NOMBRE_DE_BATEAUX && (joueurGagnant = !encorevivant(&jeu->bateauxOrdinateur[i])); i++);
	if (joueurGagnant) {
            printf("Tu as gagné !\n");
            break;
        }
	// Computer Tower 
        printf("\nTour Ordinateur :\n");
        int tirX = rand() % TAILLE_DU_PLATEAU;
        int tirY = rand() % TAILLE_DU_PLATEAU;
        tirer(jeu->plateauJoueur, tirX, tirY, jeu->bateauxJoueur, NOMBRE_DE_BATEAUX);

        // to check if the computer  has won
        int ordinateurGagnant = 1;
        for (int i = 0; i < NOMBRE_DE_BATEAUX && (ordinateurGagnant = !encorevivant(&jeu->bateauxJoueur[i])); i++);

        if (ordinateurGagnant) {
            printf("L'ordinateur a gagné !\n");
            break;
        }
    }


    libererMemoire(jeu);

    return 0;
}



