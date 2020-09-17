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
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Texture* screen = NULL;
    SDL_Surface* menu = NULL;

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
            //Create renderer for window
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (renderer == NULL)
            {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
            }
            else
            {
                //Load image at specified path
                SDL_Surface* loadedSurface = IMG_Load("images/menu.jpg");
                if( loadedSurface == NULL )
                {
                    printf("Unable to load image %s! SDL Error: %s\n", "images/menu.jpg", SDL_GetError());
                }
                else
                {	
                    //Create texture from surface pixels
                    screen = SDL_CreateTextureFromSurface(renderer, loadedSurface);
                    if (screen == NULL)
                    {
                        printf("Unable to create texture from %s! SDL Error: %s\n", "images/menu.jpg", SDL_GetError());

                        //Get rid of old loaded surface
                        SDL_FreeSurface(loadedSurface);
                    }
                    else
                    {   
                        //Get rid of old loaded surface
                        SDL_FreeSurface(loadedSurface);

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

                            //Clear screen
                            SDL_RenderClear(renderer);

                            //Render texture to screen
                            SDL_RenderCopy(renderer, screen, NULL, NULL);

                            //Update screen
                            SDL_RenderPresent(renderer);
                        }
                    }
                }
            }
        }
    }
    //Free loaded image
    SDL_DestroyTexture(screen);
    screen = NULL;

	//Destroy window
    SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow( window );
    renderer = NULL;
	window = NULL;

	//Quit SDL subsystems
	SDL_Quit();

    return EXIT_SUCCESS;

}