//Using SDL, standard IO, and standard lib
#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//Screen dimension constants
const int SCREEN_WIDTH = 408;
const int SCREEN_HEIGHT = 408;

//Key press surfaces constants
enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

//Starts up SDL and creates window
int init();

int loadMedia();

void closed();

//The window we'll be rendering to
SDL_Window *window = NULL;

//The surface contained by the window
SDL_Surface *screen = NULL;

SDL_Surface *menu = NULL;

SDL_Surface *plateau = NULL;

//The images that correspond to a keypress
SDL_Surface *marios[ KEY_PRESS_SURFACE_TOTAL ] = {NULL};

SDL_Surface *mario = NULL;


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

	marios[ KEY_PRESS_SURFACE_DOWN ] = IMG_Load( "Sprites/mario_bas.gif");
	if( marios[ KEY_PRESS_SURFACE_DOWN ] == NULL )
    {
        printf( "Failed to load mario_bas image! SDL Error: %s\n", SDL_GetError() );
        success = 0;
    }

	marios[ KEY_PRESS_SURFACE_UP ] = IMG_Load( "Sprites/mario_haut.gif");
	if( marios[ KEY_PRESS_SURFACE_UP ] == NULL )
    {
        printf( "Failed to load mario_haut image! SDL Error: %s\n", SDL_GetError() );
        success = 0;
    }

	marios[ KEY_PRESS_SURFACE_LEFT ] = IMG_Load( "Sprites/mario_gauche.gif");
	if( marios[ KEY_PRESS_SURFACE_LEFT ] == NULL )
    {
        printf( "Failed to load mario_gauche image! SDL Error: %s\n", SDL_GetError() );
        success = 0;
    }

	marios[ KEY_PRESS_SURFACE_RIGHT ] = IMG_Load( "Sprites/mario_droite.gif");
	if( marios[ KEY_PRESS_SURFACE_RIGHT ] == NULL )
    {
        printf( "Failed to load mario_droite image! SDL Error: %s\n", SDL_GetError() );
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
	SDL_FreeSurface( plateau );
	plateau = NULL;

	//Free loaded image
	SDL_FreeSurface( screen );
	screen = NULL;

	//Deallocate surfaces
	for( int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i )
	{
		SDL_FreeSurface( marios[ i ] );
		marios[ i ] = NULL;
	}

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
			int continuer = 0;

			//Event handler
			SDL_Event event;

			SDL_Rect positionMario;

			positionMario.x = 75;
			positionMario.y = 0;

			//Set default current surface
			mario = marios[ KEY_PRESS_SURFACE_DOWN ];

			//While application is running
			while( !continuer )
			{
				SDL_WaitEvent(&event); /* Récupération de l'événement dans event */
				switch(event.type) /* Test du type d'événement */
				{
					case SDL_QUIT: /* Si c'est un événement de type "Quitter" */
						continuer = -1;
						break;
					case SDL_KEYDOWN:
						switch ( event.key.keysym.sym )
						{
						case SDLK_1:
							continuer = 1;
							break;
						case SDLK_2:
							continuer = 2;
							break;
						}
						break;
				}

				//Apply the PNG image
				SDL_BlitSurface( menu, NULL, screen, NULL );
			
				//Update the surface
				SDL_UpdateWindowSurface( window );
			}
			while ( continuer )
			{
				while ( SDL_PollEvent( &event ) != 0)
				{
					switch ( event.type )
					{
					case SDL_QUIT:
						continuer = 0;
						break;
					case SDL_KEYDOWN:
						switch ( event.key.keysym.sym )
						{
						case SDLK_UP:
							mario = marios[ KEY_PRESS_SURFACE_UP ];
							positionMario.y = positionMario.y-2;
							break;
						case SDLK_DOWN:
							mario = marios[ KEY_PRESS_SURFACE_DOWN ];
							positionMario.y = positionMario.y+2;
							break;
						case SDLK_LEFT:
							mario = marios[ KEY_PRESS_SURFACE_LEFT ];
							positionMario.x = positionMario.x-2;
							break;
						case SDLK_RIGHT:
							mario = marios[ KEY_PRESS_SURFACE_RIGHT ];
							positionMario.x = positionMario.x+2;
							break;
						}
						break;
					}
				}

				SDL_FillRect( screen, NULL, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );

				//Apply the current image
				SDL_BlitSurface( mario, NULL, screen, &positionMario );
			
				//Update the surface
				SDL_UpdateWindowSurface( window );
				
			}
			
		}
	}

	//Free resources and close SDL
	closed();

	return 0;
}