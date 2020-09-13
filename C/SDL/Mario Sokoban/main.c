#include "Sokoban.h"

int main(int argc, char *argv[])
{
    //The window we'll be rendering to
    SDL_Window *window = NULL;

    //The surface contained by the window
    SDL_Surface *screen = NULL;

    SDL_Surface *menu = NULL;

    //Start up SDL and create window
	if( !init( window, screen ) )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia( menu ) )
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
	closed( window, screen, menu );

	return 0;
}