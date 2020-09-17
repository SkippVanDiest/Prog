#ifndef TABLEAU_H
#define TABLEAU_H


// Inclusion

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <array>
#include <ctime>
using namespace std;

// Structures

struct Monstre; //
struct Obstacle; //


struct caseTableau
{
    int i;
    int j;

};

struct corresCasePixel
{
    int j;
    int i;
    int x;
    int y;
};


// Enum

enum EtatMonstre
{
    INVISIBLE,
    MON_MONSTRE,
    ENDORMI,
    NORMAL


};

enum EtatObstacle
{
    NUL,
    GLACE,
    LIVRE,


};


// Constantes

const int SCREEN_WIDTH=320;
const int SCREEN_HEIGHT=568;
const int SCREEN_BPP=32;
const int TAILLE_X = 5;
const int TAILLE_Y = 9;
const int MARGE_X = 18;
const int MARGE_Y = 30;
const int CASE_X = 58;
const int CASE_Y = 52;

// Déclaration des deux tableaux

using TGrille = array<array<EtatMonstre,TAILLE_Y>,TAILLE_X>;
using TGrille2 = array<array<EtatObstacle,TAILLE_Y>,TAILLE_X>;




// Fonctions


void initTableau(TGrille &tableau);
void iniTabObstacle(TGrille2 &tableau2);
void levelUn(TGrille &tableau, TGrille2 & tableau2);
void levelDeux(TGrille &tableau, TGrille2 &tableau2);
void convertirPixelEnCase(corresCasePixel & souris);
void afficherPlateau(TGrille tableau, TGrille2 tableau2, SDL_Surface *screen, Monstre monstre, Obstacle o);
void recupererCaseDisponible(TGrille & tableau, TGrille2 & obstacles, caseTableau & caseInitiale, corresCasePixel & pos, int & reset);
void changementNiveau(TGrille & tableau, TGrille2 & tableau2, SDL_Surface *screen, SDL_Surface *chargement, bool boolGagner);
bool finDuJeu(TGrille tableau, bool fin);





#endif // TABLEAU_H
