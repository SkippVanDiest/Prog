/* -----------GACHAMON-----------*
 * 
 * Auteur : Moi
 * 
 * ------------------------------*/

#include "Gachamon.h"


LTexture::LTexture()
{
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture()
{
	//Deallocate
	free();
}

bool LTexture::loadFromFile(SDL_Renderer* gRenderer, std::string path )
{
	//Get rid of preexisting texture
	free();

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
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

void LTexture::free()
{
	//Free texture if it exists
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::render( SDL_Renderer* gRenderer, int x, int y )
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };
	SDL_RenderCopy( gRenderer, mTexture, NULL, &renderQuad );
}

int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}

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
		gWindow = SDL_CreateWindow( "Gachamon", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
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

bool loadMedia( SDL_Renderer* gRenderer, LTexture &intro, LTexture &loading, LTexture &menu )
{
	//Loading success flag
	bool success = true;

	//Load intro texture
	if( !intro.loadFromFile( gRenderer, "images/screen1.jpg" ) )
	{
		printf( "Failed to load intro texture image!\n" );
		success = false;
	}

	//Load loading texture
	if( !loading.loadFromFile( gRenderer, "images/loadingScreen1.jpg" ) )
	{
		printf( "Failed to load loading texture image!\n" );
		success = false;
	}

	//Load loading texture
	if( !menu.loadFromFile( gRenderer, "images/evanLiaw_pokecenter_4.jpg" ) )
	{
		printf( "Failed to load menu texture image!\n" );
		success = false;
	}

	return success;
}

void close( SDL_Window* gWindow, SDL_Renderer* gRenderer, LTexture &intro, LTexture &loading, LTexture &menu )
{
	//Free loaded images
	loading.free();
	intro.free();
	menu.free();

	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

bool loadMenu( SDL_Renderer* gRenderer, LTexture &loading, SDL_Event e )
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

		//Clear screen
		SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
		SDL_RenderClear( gRenderer );

		//Render texture to screen
		loading.render( gRenderer, 0, 0 );

		SDL_SetRenderDrawColor( gRenderer, 80, 80, 80, SDL_ALPHA_OPAQUE);

		SDL_RenderFillRect( gRenderer, &loadingBar );

		//Update screen
		SDL_RenderPresent( gRenderer );

		SDL_Delay(200);

		loadingBar.w += 40;
	}

	if (!quitGame)
	{
		SDL_Delay(1000);
	}

	return quitGame;
	
}

void gameMenu(SDL_Renderer* gRenderer, LTexture &menu, SDL_Event e)
{
	bool quitGame = false;

	//While application is running
	while( !quitGame )
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

		//Clear screen
		SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
		SDL_RenderClear( gRenderer );

		//Render texture to screen
		menu.render( gRenderer, -340, -120 );

		//Update screen
		SDL_RenderPresent( gRenderer );
	}
}