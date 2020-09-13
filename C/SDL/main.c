#include <stdio.h>
#include <SDL2/SDL.h>


int main(int argc, char *argv[])
{
    //The window we'll be rendering to
    SDL_Window *gWindow = NULL;
    SDL_Surface *ecran = NULL;
    //The image we will load and show on the screen
    SDL_Surface *gXOut = NULL;
    SDL_Event event; /* La variable contenant l'événement */
    int continuer = 1; /* Notre booléen pour la boucle */

    SDL_Init(SDL_INIT_VIDEO);

    gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN );

    //Get window surface
	ecran = SDL_GetWindowSurface( gWindow );

    gXOut = SDL_LoadBMP( "03_event_driven_programming/x.bmp" );
    
    while (continuer) /* TANT QUE la variable ne vaut pas 0 */
    {
		//Handle events on queue
		while( SDL_PollEvent( &event ) != 0 )
		{
		    //User requests quit
			if( event.type == SDL_QUIT )
			{
				continuer = 0;
			}
        //Apply the image
	    SDL_BlitSurface( gXOut, NULL, ecran, NULL );
			
	    //Update the surface
		SDL_UpdateWindowSurface( gWindow );
		}

    }

    //Deallocate surface
	SDL_FreeSurface( gXOut );
	gXOut = NULL;

    //Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

    SDL_Quit();

    return EXIT_SUCCESS;
}