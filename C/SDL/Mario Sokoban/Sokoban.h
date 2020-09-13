//Using SDL, standard IO, and standard lib
#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
int init( SDL_Window *window, SDL_Surface *screen );

int loadMedia( SDL_Surface *menu );