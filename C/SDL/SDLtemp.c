#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> /* Inclusion du header de SDL_image (adapter le dossier au besoin) */
 
void pause();
 
int main(int argc, char *argv[])
{
    SDL_Window* gWindow = NULL;
    SDL_Surface *ecran = NULL, *imageDeFond = NULL, *sapin = NULL;
    SDL_Rect positionFond, positionSapin;
 
    positionFond.x = 0;
    positionFond.y = 0;
    positionSapin.x = 500;
    positionSapin.y = 260;
 
    SDL_Init(SDL_INIT_VIDEO);
 
    gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN );

    ecran = SDL_GetWindowSurface( gWindow );
 
    imageDeFond = IMG_Load("lac_en_montagne.bmp");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
 
    /* Chargement d'un PNG avec IMG_Load
    Celui-ci est automatiquement rendu transparent car les informations de
    transparence sont codées à l'intérieur du fichier PNG */
    sapin = IMG_Load("sapin.png");
    SDL_BlitSurface(sapin, NULL, ecran, &positionSapin);
 
    SDL_UpdateWindowSurface( gWindow );
    pause();
 
    SDL_FreeSurface(imageDeFond);
    SDL_FreeSurface(sapin);
    SDL_DestroyWindow( gWindow );
    SDL_Quit();
 
    return EXIT_SUCCESS;
}
 
void pause()
{
    int continuer = 1;
    SDL_Event event;
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}