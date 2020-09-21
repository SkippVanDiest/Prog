#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


int main(int argc, char *argv[])
{
    SDL_Window *fenetre = NULL;
    SDL_Surface *ecran = NULL, *zozor = NULL;
    SDL_Rect positionZozor;
    SDL_Event event;
    int continuer = 1;
    int versLaDroite = 1;
    int arret = 0;
    int tempsPrecedent = 0, tempsActuel = 0;

    SDL_Init(SDL_INIT_VIDEO);

    fenetre = SDL_CreateWindow("Gestion du temps en SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);

    zozor = SDL_LoadBMP("zozor.bmp");
    SDL_SetColorKey(zozor, SDL_TRUE, SDL_MapRGB(zozor->format, 0, 0, 255));

    ecran = SDL_GetWindowSurface(fenetre);

    positionZozor.x = ecran->w / 2 - zozor->w / 2;
    positionZozor.y = ecran->h / 2 - zozor->h / 2;

    while (continuer)
    {
        SDL_PollEvent(&event); /* On utilise PollEvent et non WaitEvent pour ne pas bloquer le programme */
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_p)
                {
                    if(arret == 0)
                        arret = 1;
                    else
                    {
                        arret = 0;
                    }                    
                }
                break;
        }

        tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent > 20 && arret == 0) /* Si 30 ms se sont écoulées depuis le dernier tour de boucle */
        {
            if(versLaDroite)
            {
                positionZozor.x = positionZozor.x + 3; /* On bouge Zozor */
                tempsPrecedent = tempsActuel; /* Le temps "actuel" devient le temps "precedent" pour nos futurs calculs */
                if(positionZozor.x >= ecran->w - zozor->w)
                    versLaDroite = 0;
            }
            else
            {
                positionZozor.x = positionZozor.x - 3; /* On bouge Zozor */
                tempsPrecedent = tempsActuel; /* Le temps "actuel" devient le temps "precedent" pour nos futurs calculs */
                if(positionZozor.x <= 0)
                    versLaDroite = 1;
            }
        }
        else /* Si ça fait moins de 30 ms depuis le dernier tour de boucle, on endort le programme le temps qu'il faut */
        {
            SDL_Delay(20 - (tempsActuel - tempsPrecedent));
        }

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        SDL_BlitSurface(zozor, NULL, ecran, &positionZozor);
        SDL_UpdateWindowSurface(fenetre);
    }

    SDL_FreeSurface(zozor);
    zozor = NULL;
    SDL_FreeSurface(ecran);
    ecran = NULL;
    SDL_DestroyWindow(fenetre);
    fenetre = NULL;
    SDL_Quit();

    return EXIT_SUCCESS;
}