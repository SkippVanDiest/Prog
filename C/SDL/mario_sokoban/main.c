/*
main.c
------

Par mateo21, pour Le Site du Zér0 (www.siteduzero.com)

Rôle : menu du jeu. Permet de choisir entre l'éditeur et le jeu lui-même.
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "constantes.h"
#include "jeu.h"
#include "editeur.h"



int main(int argc, char *argv[])
{
    SDL_Window *fenetre = NULL;
    SDL_Surface *ecran = NULL, *menu = NULL, *icone = NULL;
    SDL_Rect positionMenu;
    SDL_Event event;

    int continuer = 1;

    SDL_Init(SDL_INIT_VIDEO);

    fenetre = SDL_CreateWindow( "Mario Sokoban", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, LARGEUR_FENETRE, HAUTEUR_FENETRE, SDL_WINDOW_SHOWN );

    menu = IMG_Load("menu.jpg");
    icone = IMG_Load("caisse.jpg");
    positionMenu.x = 0;
    positionMenu.y = 0;

    SDL_SetWindowIcon(fenetre, icone);

    ecran = SDL_GetWindowSurface(fenetre);

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE: // Veut arrêter le jeu
                        continuer = 0;
                        break;
                    case SDLK_KP_1: // Demande à jouer
                        jouer(ecran, fenetre);
                        break;
                    case SDLK_KP_2: // Demande l'éditeur de niveaux
                        editeur(ecran, fenetre);
                        break;
                }
                break;
        }

        // Effacement de l'�cran
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(menu, NULL, ecran, &positionMenu);
        SDL_UpdateWindowSurface(fenetre);
    }

    SDL_FreeSurface(icone);
    SDL_FreeSurface(menu);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();

    return EXIT_SUCCESS;
}
