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

//Starts up SDL and creates window
bool init( SDL_Window* gWindow, SDL_Renderer* &gRenderer );

//Loads media
bool loadMedia( SDL_Renderer* gRenderer, SDL_Texture* &menu, SDL_Texture* &loading );

//Frees media and shuts down SDL
void close( SDL_Window* gWindow, SDL_Renderer* gRenderer, SDL_Texture* menu, SDL_Texture* loading );

//Loads individual image as texture
SDL_Texture* loadTexture( SDL_Renderer* gRenderer, std::string path );

void loadGame( SDL_Renderer* gRenderer, SDL_Texture* loading, SDL_Event e );

#endif  //DEF_GACHAMON