#ifndef MONSTER_H
#define MONSTER_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "plateau.h"


// Structures
struct Monstre
{
    int x = 0;     // abscisse
    int y = 0;     // ordonnée
    EtatMonstre typeMonstre;
    SDL_Surface *source;
    SDL_Rect lectureMonstreRouge;
    SDL_Rect lectureMonstreBleu;
};



struct Obstacle
{
    SDL_Surface *source;
    SDL_Rect lectureGlace;
    SDL_Rect lectureLivres;
    SDL_Rect lectureFlecheHaut;
    SDL_Rect lectureFlecheBas;
    SDL_Rect lectureFlecheGauche;
    SDL_Rect lectureFlecheDroite;

};


// Fonctions


void initMonster(Monstre &m);
void initObstacle(Obstacle & o);
bool collision(SDL_Rect a, SDL_Rect b);
void deplacerMonstre (Monstre &m, caseTableau caseInitiale, caseTableau caseDestination, TGrille & tableau);






#endif // MONSTER_H
