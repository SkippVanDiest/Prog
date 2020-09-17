#ifndef SDL_H
#define SDL_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <ctime>

using namespace std;
SDL_Surface *load_image(string filename );                                                        //
SDL_Surface *loadImageWithColorKey(string filename, int r, int g, int b);                         // Différente fonction pour l'affichage d'une image.
void applySurface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip);   //

#endif // SDL_H
