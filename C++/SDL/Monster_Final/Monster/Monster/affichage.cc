#include "SDL.h"
#include "affichage.h"
#include "plateau.h"

/****************** Nom de la fonction **********************
* menuPrincipal                                             *
******************** Auteur , Dates *************************
* Bascouzaraix Julien,  Version 1                           *
********************* Description ***************************
* Affiche le menu principale du jeu                         *
*********************** EntrÃ©es *****************************
* Le screen, et l'event du menu                             *
*********************** Sorties *****************************
* Le Screen                                                 *
************************************************************/
void menuPrincipal(SDL_Window *window, SDL_Surface *screen, SDL_Event eventMenu, bool & quit)
{


    bool play = false;
    SDL_Surface *menu = IMG_Load("menu.bmp");


    while(!play && !quit)
    {
        while(SDL_PollEvent(&eventMenu))
        {
            //événement de fermeture d'application, on sort la boucle
            if( eventMenu.type == SDL_QUIT )
            {
                quit = true;
            }
            //les coordonnées de la souris
            int x = eventMenu.button.x;
            int y = eventMenu.button.y;


            if(x >= 90 && x<= 190 && y >= 275 && y<=375 )
            {

                if(eventMenu.button.button == SDL_BUTTON_LEFT)
                {
                    play = true;
                }
            if(x >= 200 && x <= 260 && y >= 350 && y <= 393)
            {

                if(eventMenu.button.button == SDL_BUTTON_LEFT)
                {
                    quit = true;
                }
            }


            }
        }
        applySurface(0, 0, menu, screen, NULL);
        SDL_UpdateWindowSurface(window);


    }
}
