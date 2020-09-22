/* -----------GACHAMON-----------*
 * 
 * Auteur : Moi
 * 
 * ------------------------------*/

//Inluding libraries
#include "Gachamon.h"

int main(int argc, char** argv)
{
    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //The window renderer
    SDL_Renderer* gRenderer = NULL;

    //Menu texture
    LTexture menu;

	//Laoding texture
    LTexture loading;

	//Start up SDL and create gWindow
	if( !init( gWindow, gRenderer ) )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{	
		//Load media
		if( !loadMedia( gRenderer, menu, loading ) )
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
					switch (e.type)
					{
						//User requests quit
						case SDL_QUIT:
							quit = true;
							break;
						case SDL_MOUSEBUTTONDOWN:
							if (e.button.button == SDL_BUTTON_LEFT)
							{
								loadGame( gRenderer, loading, e);
							}
						break;
					}
				}

				//Clear screen
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );

				//Render menu texture to screen
				menu.render( gRenderer, 0, 0 );

				//Update screen
				SDL_RenderPresent( gRenderer );
			}
		}
	}

	//Free resources and close SDL
	close( gWindow, gRenderer, menu, loading);

	return 0;
}