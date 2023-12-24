// jeu.h

#ifndef JEU_H
#define JEU_H

#include "bateau.h"
#include "plateau.h"

struct Jeu {
    struct Plateau* plateauJoueur;
    struct Plateau* plateauOrdinateur;
    struct Bateau* bateauxJoueur;
    struct Bateau* bateauxOrdinateur;
};

#define NOMBRE_DE_BATEAUX 5
#define TAILLE_DU_PLATEAU 10

struct Jeu* creerJeu();
void libererMemoire(struct Jeu* jeu);

#endif // JEU_H

