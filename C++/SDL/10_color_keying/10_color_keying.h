/*This source code copyrighted by Lazy Foo' Productions (2004-2020)
and may not be redistributed without written permission.*/

#ifndef DEF_10_COLOR_KEYING
#define DEF_10_COLOR_KEYING

//Using SDL, SDL_image, standard IO, and strings
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>

//Screen dimension constants
#define SCREEN_WIDTH    640
#define SCREEN_HEIGHT   480

//Texture wrapper class
class LTexture
{
	public:
		//Initializes variables
		LTexture();

		//Deallocates memory
		~LTexture();

		//Loads image at specified path
		bool loadFromFile( SDL_Renderer* gRenderer, std::string path );

		//Deallocates texture
		void free();

		//Renders texture at given point
		void render( SDL_Renderer* gRenderer, int x, int y );

		//Gets image dimensions
		int getWidth();
		int getHeight();

	private:
		//The actual hardware texture
		SDL_Texture* mTexture;

		//Image dimensions
		int mWidth;
		int mHeight;
};

//Starts up SDL and creates window
bool init( SDL_Window* gWindow, SDL_Renderer* &gRenderer );

//Loads media
bool loadMedia( SDL_Renderer* gRenderer, LTexture &gFooTexture, LTexture &gBackgroundTexture );

//Frees media and shuts down SDL
void close( SDL_Window* gWindow, SDL_Renderer* gRenderer, LTexture gFooTexture, LTexture gBackgroundTexture );

#endif //DEF_10_COLOR_KEYING