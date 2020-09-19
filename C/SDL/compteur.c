#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

int main(int argc, char **argv)
{
    SDL_Window *fenetre = NULL;
    SDL_Surface *ecran = NULL, *texte = NULL;
    SDL_Rect position;
    SDL_Event event;
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {0, 0, 0}, couleurBlanche = {255, 255, 255};
    int continuer = 1;
    int tempsPrecedent = 0, tempsActuel = 0, compteur = 0;
    char temps[20] = {0};

    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    fenetre = SDL_CreateWindow("Ptit compteur", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);

    ecran = SDL_GetWindowSurface(fenetre);

    /* Chargement de la police */
    police = TTF_OpenFont("angelina.TTF", 65);

    /* Initialisation du temps et du texte */
    tempsActuel = SDL_GetTicks();
    sprintf(temps, "Temps : %d", compteur);
    texte = TTF_RenderText_Shaded(police, temps, couleurNoire, couleurBlanche);

    while(continuer)
    {
        SDL_PollEvent(&event); /* On utilise PollEvent et non WaitEvent pour ne pas bloquer le programme */
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }

        tempsActuel = SDL_GetTicks();
        if(tempsActuel-tempsPrecedent >= 100)
        {
            compteur += 100;
            sprintf(temps, "Temps : %d", compteur);
            SDL_FreeSurface(texte);
            /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
            texte = TTF_RenderText_Blended(police, temps, couleurNoire);

            tempsPrecedent = tempsActuel;
        }
        
        
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

        position.x = (ecran->w/2)-(texte->w/2);
        position.y = (ecran->h/2)-(texte->h/2);

        SDL_BlitSurface(texte, NULL, ecran, &position);
        
        SDL_UpdateWindowSurface(fenetre);

    }

    TTF_CloseFont(police);
    TTF_Quit();

    SDL_FreeSurface(texte);
    texte = NULL;
    SDL_FreeSurface(ecran);
    ecran = NULL;
    SDL_DestroyWindow(fenetre);
    fenetre = NULL;
    SDL_Quit();

    return EXIT_SUCCESS;
}