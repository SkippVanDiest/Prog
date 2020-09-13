#include "Sokoban.h"

int init( SDL_Window *window, SDL_Surface *screen )
{
    //Initialization flag
    int success = 1;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = 0;
    }
    else
    {
        //Create window
        window = SDL_CreateWindow( "Mario Sokoban", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = 0;
        }
        else
        {
            //Initialize JPG loading
            int imgFlags = IMG_INIT_JPG;
            if( !( IMG_Init( imgFlags ) & imgFlags ) )
            {
                printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                success = 0;
            }
            else
            {
                //Get window surface
                screen = SDL_GetWindowSurface( window );
            }
        }
    }

    return success;    
}

int loadMedia( SDL_Surface *menu )
{
    int success = 1;

    menu = IMG_Load( "Sprites/menu.jpg" );
    if( menu == NULL )
    {
        printf( "Failed to load menu image! SDL Error: %s\n", SDL_GetError() );
        success = 0;
    }

    return success;
}