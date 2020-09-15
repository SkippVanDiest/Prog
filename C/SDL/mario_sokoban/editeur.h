/*
editeur.h
---------

Par mateo21, pour Le Site du Z�r0 (www.siteduzero.com)

R�le : prototypes des fonctions de gestion de l'�diteur de niveaux.
*/

#ifndef DEF_EDITEUR
#define DEF_EDITEUR


#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "constantes.h"
#include "fichiers.h"

    void editeur(SDL_Surface* ecran, SDL_Window* fenetre);

#endif
