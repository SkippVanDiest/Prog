//Using SDL, standard IO, and standard lib
#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//Screen dimension constants
const int SCREEN_WIDTH = 408;
const int SCREEN_HEIGHT = 408;

//Starts up SDL and creates window
int init();

int loadMedia();

void closed();

//The window we'll be rendering to
SDL_Window *window = NULL;

//The surface contained by the window
SDL_Surface *screen = NULL;

SDL_Surface *menu = NULL;


int init()
{
    //Initialization flag
    int success = 1;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = 0;
    }
    else
    {
        //Create window
        window = SDL_CreateWindow( "Mario Sokoban", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = 0;
        }
        else
        {
            //Get window surface
            screen = SDL_GetWindowSurface( window );
        }
    }

    return success;    
}

int loadMedia()
{
    int success = 1;

    menu = IMG_Load( "Sprites/menu.jpg" );
    if( menu == NULL )
    {
        printf( "Failed to load menu image! SDL Error: %s\n", SDL_GetError() );
        success = 0;
    }

    return success;
}

void closed()
{
    //Free loaded image
	SDL_FreeSurface( menu );
	menu = NULL;

	//Free loaded image
	SDL_FreeSurface( screen );
	screen = NULL;

	//Destroy window
	SDL_DestroyWindow( window );
	window = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

int main(int argc, char *argv[])
{
    //Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{	
			//Main loop flag
			int quit = 0;

			//Event handler
			SDL_Event e;

			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = 1;
					}
				}

				//Apply the PNG image
				SDL_BlitSurface( menu, NULL, screen, NULL );
			
				//Update the surface
				SDL_UpdateWindowSurface( window );
			}
		}
	}

	//Free resources and close SDL
	closed();

	return 0;
}