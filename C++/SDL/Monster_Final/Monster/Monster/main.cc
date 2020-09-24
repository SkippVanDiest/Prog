#include "SDL2/SDL.h"
#include "monster.h"
#include "plateau.h"
#include "affichage.h"


using namespace std;

int main(int argc, char **argv)
{


    // --------------------------------------------- Début de déclaration de variable --------------------------------------------- //
    bool fin = false;
    bool quit = false;
    bool surMonstre = false;
    bool uneFois = false;
    int reset = 0;

    SDL_Window *window = NULL;

    corresCasePixel pos;

    TGrille tableau;
    TGrille2 tableau2;


    Obstacle o;
    caseTableau caseInitiale;
    caseTableau caseDestination;

    SDL_Surface *screen;

    SDL_Event event;
    SDL_Event eventMenu;

    SDL_Surface *fond = IMG_Load("background.bmp"); // Chargement de l'image de fond.
    SDL_Surface *chargement = IMG_Load("winSprite.bmp");
    SDL_Surface *final = IMG_Load("winEndSprite.bmp");

    Monstre monstre;


// --------------------------------------------- Fin de déclaration de variable --------------------------------------------- //
// --------------------------------------------- Debut Initialisation ------------------------------------------------------- //

    SDL_Init(SDL_INIT_EVERYTHING); // Initialisation de la SDL.

    window = SDL_CreateWindow("Monster", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    screen = SDL_GetWindowSurface(window);

    initMonster(monstre);
    initObstacle(o);


    monstre.source = loadImageWithColorKey(screen, "sprite.bmp", 255,255,255);
    o.source = loadImageWithColorKey(screen, "sprite.bmp", 255,255,255);

    initTableau(tableau);
    iniTabObstacle(tableau2);

    levelUn(tableau, tableau2);

 // --------------------------------------------- Fin Initialisation ------------------------------------------------------- //


    menuPrincipal(window, screen, eventMenu, quit);

    while(!quit)
    {
        bool deplacementDetecte = false;

        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                quit = true;

            if(event.button.button == SDL_BUTTON_LEFT)
            {
                if(uneFois){}

                //les coordonnées de la souris
                pos.x = event.button.x;
                pos.y = event.button.y;

                if(event.type == SDL_MOUSEBUTTONDOWN )
                {

                    convertirPixelEnCase(pos); // On converti une case de pixel en coordonnées de tableau
                    if(tableau[pos.i][pos.j] == MON_MONSTRE)
                    {
                        surMonstre = true;
                        caseInitiale.i = pos.i; // On garde les positions initiales.
                        caseInitiale.j = pos.j; //

                    }






                }

                else if(event.type == SDL_MOUSEBUTTONUP && surMonstre)
                {
                    convertirPixelEnCase(pos);
                    recupererCaseDisponible(tableau, tableau2, caseInitiale, pos, reset);


                    if(reset == -1)
                    {
                       deplacementDetecte = false;
                       initTableau(tableau);
                       initObstacle(o);
                       levelUn(tableau, tableau2);


                    }


                    else
                        deplacementDetecte = true;

                    caseDestination.i = pos.i; // On garde les positions destinations
                    caseDestination.j = pos.j;



                    // Faire la fonction pour voir le monstre se déplacer


                }

            }
        }



        if(deplacementDetecte)
        {
            deplacerMonstre(monstre,caseInitiale,caseDestination,tableau); // On déplace le monstre
         //   changementNiveau(tableau, tableau2, screen,chargement, gagner);
        }

        fin = finDuJeu(tableau,fin); // On regarde si c'est la fin du jeu ...







            SDL_FillRect(screen,&screen->clip_rect, SDL_MapRGB(screen->format,255,255,255));
            applySurface(0,0,fond,screen,NULL);
            afficherPlateau(tableau, tableau2, screen,monstre,o);


            if (fin == true) // ... Si c'est le cas, le booleen quit prend la valeur true
            {
                applySurface(0,0,final,screen,NULL);
                SDL_UpdateWindowSurface(window);
                SDL_Delay(1000);
                quit = true;
            }


            SDL_UpdateWindowSurface(window); // Affichage de l'écran.




        }



        SDL_FreeSurface(fond); // Libération ...
        SDL_FreeSurface(monstre.source);
        SDL_FreeSurface(o.source);
        SDL_FreeSurface(chargement);
        SDL_FreeSurface(final); // ... de la mémoire
        SDL_Quit();

    }



