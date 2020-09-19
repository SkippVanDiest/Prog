#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

int main(int argc, char *argv[])
{
    SDL_Window *fenetre = NULL;
    SDL_Surface *ecran = NULL, *texte = NULL, *fond = NULL;
    SDL_Rect position;
    SDL_Event event;
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {0, 0, 0};
    int continuer = 1;

    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    fenetre = SDL_CreateWindow("Gestion du texte avec SDL_ttf", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);

    ecran = SDL_GetWindowSurface(fenetre);

    fond = IMG_Load("menu.jpg");

    /* Chargement de la police */
    police = TTF_OpenFont("angelina.TTF", 65);
    /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
    texte = TTF_RenderText_Blended(police, "Salut les Zér0s !", couleurNoire);

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

        position.x = 0;
        position.y = 0;
        SDL_BlitSurface(fond, NULL, ecran, &position); /* Blit du fond */

        position.x = 60;
        position.y = 370;
        SDL_BlitSurface(texte, NULL, ecran, &position); /* Blit du texte */
        SDL_UpdateWindowSurface(fenetre);
    }

    TTF_CloseFont(police);
    TTF_Quit();

    SDL_FreeSurface(texte);
    texte = NULL;
    SDL_FreeSurface(fond);
    fond = NULL;
    SDL_FreeSurface(ecran);
    ecran = NULL;
    SDL_DestroyWindow(fenetre);
    fenetre = NULL;
    SDL_Quit();

    return EXIT_SUCCESS;
}