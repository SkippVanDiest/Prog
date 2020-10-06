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

    //Intro texture
    LTexture intro;

	//Laoding texture
    LTexture loading;

	//Menu texture
	LTexture menu;

	//Start up SDL and create gWindow
	if( !init( gWindow, gRenderer ) )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{	
		//Load media
		if( !loadMedia( gRenderer, intro, loading, menu ) )
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
								if(!loadMenu( gRenderer, loading, e))
								{
									gameMenu( gRenderer, menu, e);
								}
							}
						break;
					}
				}

				//Clear screen
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );

				//Render intro texture to screen
				intro.render( gRenderer, 0, 0 );

				//Update screen
				SDL_RenderPresent( gRenderer );
			}
		}
	}

	//Free resources and close SDL
	close( gWindow, gRenderer, intro, loading, menu);

	return 0;
}