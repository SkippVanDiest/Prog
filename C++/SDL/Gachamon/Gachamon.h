/* -----------GACHAMON-----------*
 * 
 * Auteur : Moi
 * 
 * ------------------------------*/

#ifndef DEF_GACHAMON
#define DEF_GACHAMON

//Inluding libraries
#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//Defining screen dimensions
#define SCREEN_WIDTH    1280
#define SCREEN_HEIGHT   720

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
bool loadMedia( SDL_Renderer* gRenderer, LTexture &intro, LTexture &loading, LTexture &menu );

//Frees media and shuts down SDL
void close( SDL_Window* gWindow, SDL_Renderer* gRenderer, LTexture intro, LTexture loading, LTexture menu );

//Loading screen
void loadGame( SDL_Renderer* gRenderer, LTexture &loading, SDL_Event e );

//Game menu
void gameMenu( SDL_Renderer* gRenderer, LTexture &menu, SDL_Event e );

#endif  //DEF_GACHAMON