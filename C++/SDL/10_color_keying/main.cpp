/*This source code copyrighted by Lazy Foo' Productions (2004-2020)
and may not be redistributed without written permission.*/

//Using local .h
#include "10_color_keying.h"


int main( int argc, char* args[] )
{
    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //The window renderer
    SDL_Renderer* gRenderer = NULL;

    //Scene textures
    LTexture gFooTexture;
    LTexture gBackgroundTexture;

	//Start up SDL and create window
	if( !init(gWindow, gRenderer) )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia( gRenderer, gFooTexture, gBackgroundTexture ) )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{	
			//Main loop flag
			bool quit = false;

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
						quit = true;
					}
				}

				//Clear screen
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );

				//Render background texture to screen
				gBackgroundTexture.render( gRenderer, 0, 0 );

				//Render Foo' to the screen
				gFooTexture.render( gRenderer, 240, 190 );

				//Update screen
				SDL_RenderPresent( gRenderer );
			}
		}
	}

	//Free resources and close SDL
	close( gWindow, gRenderer, gFooTexture, gBackgroundTexture );

	return 0;
}