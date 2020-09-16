/*-------GACHAMON-----------
 * Auteur : 
*/

//Inluding libraries
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//Defining screen dimensions
#define WINDOW_WIDTH    1280
#define WINDOW_HEIGHT   720

int main(int argc, char **argv)
{
    SDL_Window *window = NULL;
    SDL_Surface *screen = NULL;
    SDL_Surface *menu = NULL;

    //Initialization flag
    int success = 1;

    //Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
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

            //Load menu surface
            menu = IMG_Load("images/menu.jpg");
            if( menu == NULL )
            {
                printf("Failed to load menu image! SDL Error: %s\n", SDL_GetError());
            }
            else
            {	
                //Main loop flag
                int quit = 0;

                //Event handler
                SDL_Event event;

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

                    //Update the surface
                    SDL_UpdateWindowSurface(window);
                }
            }
        }
    }
    //Deallocate surfaces
    SDL_FreeSurface(menu);
    menu = NULL;

    SDL_FreeSurface(screen);
    screen = NULL;

	//Destroy window
	SDL_DestroyWindow( window );
	window = NULL;

	//Quit SDL subsystems
	SDL_Quit();

    return EXIT_SUCCESS;

}