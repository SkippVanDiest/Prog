/* -----------GACHAMON-----------*
 * 
 * Auteur : Moi
 * 
 * ------------------------------*/

#include "Gachamon.h"

bool init( SDL_Window* gWindow, SDL_Renderer* &gRenderer )
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_JPG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia( SDL_Renderer* gRenderer, SDL_Texture* &menu, SDL_Texture* &loading )
{
	//Loading success flag
	bool success = true;

	//Load menu texture
	menu = loadTexture( gRenderer, "images/screen1.jpg" );
	if( menu == NULL )
	{
		printf( "Failed to load menu image!\n" );
		success = false;
	}

	//Load loading texture
	loading = loadTexture( gRenderer, "images/loadingScreen1.jpg" );
	if( loading == NULL )
	{
		printf( "Failed to load loading image!\n" );
		success = false;
	}


	return success;
}

void close( SDL_Window* gWindow, SDL_Renderer* gRenderer, SDL_Texture* menu, SDL_Texture* loading )
{
	//Free loaded image
	SDL_DestroyTexture( loading );
	loading = NULL;

	//Free loaded image
	SDL_DestroyTexture( menu );
	menu = NULL;

	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* loadTexture( SDL_Renderer* gRenderer, std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

void loadGame( SDL_Renderer* gRenderer, SDL_Texture* loading, SDL_Event e )
{
	SDL_Rect loadingBar = {240, 650, 0, 30};

	bool quitGame = false;

	//While application is running
	while( !quitGame && loadingBar.w <= 800)
	{
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			switch (e.type)
			{
				//User requests quit
				case SDL_QUIT:
					quitGame = true;
					break;
			}
		}

		SDL_SetRenderDrawColor( gRenderer, 80, 80, 80, SDL_ALPHA_OPAQUE);

		//Clear screen
		SDL_RenderClear( gRenderer );

		//Render texture to screen
		SDL_RenderCopy( gRenderer, loading, NULL, NULL );

		SDL_RenderFillRect( gRenderer, &loadingBar );

		//Update screen
		SDL_RenderPresent( gRenderer );

		SDL_Delay(200);

		loadingBar.w += 40;
	}

	SDL_Delay(1000);
}