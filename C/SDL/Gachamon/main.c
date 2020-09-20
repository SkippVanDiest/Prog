/*-------GACHAMON-----------
 * Auteur : 
*/

//Inluding libraries
#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

//Defining screen dimensions
#define WINDOW_WIDTH    1280
#define WINDOW_HEIGHT   720

int main(int argc, char **argv)
{
    SDL_Window *window = NULL;
    SDL_Surface *screen = NULL, *menu = NULL, *loadingScreen = NULL, *texte = NULL, *loadingBar = NULL;
    SDL_Rect position;
    SDL_Rect loadingBarRect;
    TTF_Font *police = NULL;
    SDL_Color couleurJaune = {255, 255, 0};

    /* Chargement de la police */
    police = TTF_OpenFont("Pokemon_Solid.ttf", 106);

    /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
    texte = TTF_RenderText_Blended(police, "Pokéfion", couleurJaune);

    position.x = 0;
    position.y = 0;

    //Initialization flag
    int success = 1;

    //Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        return EXIT_FAILURE;
    }

    if(TTF_Init() == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }
            
    //Create window
    window = SDL_CreateWindow("Gachamon", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if(window == NULL)
    {
        printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return EXIT_FAILURE;
    }
    
    //Get window surface
    screen = SDL_GetWindowSurface(window);
    if (screen == NULL)
    {
        printf("Get window surface error! SDL Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        window = NULL;
        TTF_Quit();
        SDL_Quit();
        return EXIT_FAILURE;
    }

    loadingBar = SDL_CreateRGBSurface(0, 800, 30, 32, 0, 0, 0, 0);
    
    //Load image at specified path
    menu = IMG_Load("images/screen1.jpg");
    loadingScreen = IMG_Load("images/loadingScreen1.jpg");
    if( menu == NULL || loadingScreen == NULL)
    {
        printf("Unable to load image! SDL Error: %s\n", SDL_GetError());
        SDL_FreeSurface(screen);
        screen = NULL;
        SDL_DestroyWindow(window);
        window = NULL;
        TTF_Quit();
        SDL_Quit();
        return EXIT_FAILURE;
    }
    
    //Main loop flag
    int quit = 0;

    //Event handler
    SDL_Event event;

    /* Chargement de la police */
    police = TTF_OpenFont("Pokemon_Solid.ttf", 116);

    /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
    texte = TTF_RenderText_Blended(police, "Pokefion", couleurJaune);

    position.x = (screen->w/2)-(texte->w/2);
    position.y = 250;

    //While application is running
    while(!quit)
    {
        //Handle incoming event
        SDL_WaitEvent(&event);

        switch(event.type)
        {
            //User requests quit
            case SDL_QUIT:
                quit = 1;
                break;
            case SDL_MOUSEBUTTONDOWN:
                switch(event.button.button)
                {
                case SDL_BUTTON_LEFT:
                    loadingBarRect.x = (screen->w/2)-(loadingBar->w/2);
                    loadingBarRect.y = 650;
                    while(!quit || loadingBar->w > 0)
                    {
                        SDL_PollEvent(&event);
                        switch(event.type)
                        {
                        case SDL_QUIT:
                            quit = 1;
                            break;
                        }
                        loadingBar->w -= 20;
                        SDL_Delay(200);
                        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
                        SDL_FillRect(loadingBar, NULL, SDL_MapRGB(screen->format, 80, 80, 80));
                        SDL_BlitSurface(loadingScreen, NULL, screen, NULL);
                        SDL_BlitSurface(loadingBar, NULL, screen, &loadingBarRect);
                        SDL_UpdateWindowSurface(window);
                    }
                    break;
                }
                break;
        }
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

        //Apply the current image
        SDL_BlitSurface(menu, NULL, screen, NULL);

        SDL_BlitSurface(texte, NULL, screen, &position);

        //Update screen
        SDL_UpdateWindowSurface(window);
    }
                    
    TTF_CloseFont(police);

	//Quit SDL subsystems
    TTF_Quit();
    //Free loaded image
    SDL_FreeSurface(texte);
    texte = NULL;

    SDL_FreeSurface(loadingBar);
    loadingBar = NULL;

    SDL_FreeSurface(loadingScreen);
    loadingScreen = NULL;
    
    SDL_FreeSurface(menu);
    menu = NULL;

    SDL_FreeSurface(screen);
    screen = NULL;

	//Destroy window
	SDL_DestroyWindow(window);
	window = NULL;

	SDL_Quit();

    return EXIT_SUCCESS;

}