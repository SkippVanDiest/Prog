//Using SDL, standard IO, and standard lib
#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//Screen dimension constants
#define SCREEN_WIDTH    408
#define SCREEN_HEIGHT   408

//Starts up SDL and creates window
int init( SDL_Window *window, SDL_Surface *screen );

int loadMedia( SDL_Surface *menu );

void closed( SDL_Window *window, SDL_Surface *screen, SDL_Surface *menu );