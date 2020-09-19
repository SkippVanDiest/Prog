/*-------GACHAMON-----------
 * Auteur : 
*/

//Inluding libraries
#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

//Defining screen dimensions
#define WINDOW_WIDTH    1280
#define WINDOW_HEIGHT   720

int main(int argc, char **argv)
{
    SDL_Window *window = NULL;
    SDL_Surface *screen = NULL, *menu = NULL, *texte = NULL;
    SDL_Rect position;
    TTF_Font *police = NULL;
    SDL_Color couleurJaune = {255, 255, 0};

    /* Chargement de la police */
    police = TTF_OpenFont("Pokemon_Solid.ttf", 106);

    /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
    texte = TTF_RenderText_Blended(police, "Pokéfion", couleurJaune);

    position.x = 0;
    position.y = 0;

    //Initialization flag
    int success = 1;

    //Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
    }
    else
    {
        if(TTF_Init() == -1)
        {
            fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        }
        else
        {
            //Create window
            window = SDL_CreateWindow("Gachamon", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
            if(window == NULL)
            {
                printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            }
            else
            {
                //Get window surface
                screen = SDL_GetWindowSurface(window);
                if (screen == NULL)
                {
                    printf("Get window surface error! SDL Error: %s\n", SDL_GetError());
                }
                else
                {
                    //Load image at specified path
                    menu = IMG_Load("images/menu.jpg");
                    if( menu == NULL )
                    {
                        printf("Unable to load menu image! SDL Error: %s\n", SDL_GetError());
                    }
                    else
                    {	
                        //Main loop flag
                        int quit = 0;

                        //Event handler
                        SDL_Event event;

                        /* Chargement de la police */
                        police = TTF_OpenFont("Pokemon_Solid.ttf", 116);

                        /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
                        texte = TTF_RenderText_Blended(police, "Pokefion", couleurJaune);

                        position.x = (screen->w/2)-(texte->w/2);
                        position.y = 100;

                        //While application is running
                        while(!quit)
                        {
                            //Handle incoming event
                            SDL_WaitEvent(&event);

                            switch(event.type)
                            {
                                //User requests quit
                                case SDL_QUIT:
                                    quit = 1;
                                    break;
                            }

                            //Apply the current image
                            SDL_BlitSurface(menu, NULL, screen, NULL);

                            SDL_BlitSurface(texte, NULL, screen, &position);

                            //Update screen
                            SDL_UpdateWindowSurface(window);
                        }
                    }
                }
            }
        }
    }
    TTF_CloseFont(police);

	//Quit SDL subsystems
    TTF_Quit();
    //Free loaded image
    SDL_FreeSurface(texte);
    texte = NULL;
    
    SDL_FreeSurface(menu);
    menu = NULL;

    SDL_FreeSurface(screen);
    screen = NULL;

	//Destroy window
	SDL_DestroyWindow(window);
	window = NULL;

	SDL_Quit();

    return EXIT_SUCCESS;

}