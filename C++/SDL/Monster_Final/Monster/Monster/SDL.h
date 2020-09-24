#ifndef SDL_H
#define SDL_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <ctime>

using namespace std;
SDL_Surface *load_image(SDL_Surface *screen, string filename );                                                        //
SDL_Surface *loadImageWithColorKey(SDL_Surface *screen, string filename, int r, int g, int b);                         // Différente fonction pour l'affichage d'une image.
void applySurface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip);   //

#endif // SDL_H
