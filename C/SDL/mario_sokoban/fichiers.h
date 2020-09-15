/*
fichiers.h
----------

Par mateo21, pour Le Site du Z�r0 (www.siteduzero.com)

Rôle : prototypes des fonctions de lecture / �criture de fichiers de niveau.
*/

#ifndef DEF_FICHIERS
#define DEF_FICHIERS

#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "constantes.h"

    int chargerNiveau(int niveau[][NB_BLOCS_HAUTEUR]);
    int sauvegarderNiveau(int niveau[][NB_BLOCS_HAUTEUR]);

#endif

