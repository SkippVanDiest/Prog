#include "SDL.h"


/****************** Nom de la fonction **********************
* load_image                                                *
******************** Auteur , Dates *************************
* //, 16/11/16, Version 1.0                                 *
********************* Description ***************************
* Cette fonction permet de charger une image sur une        *
* surface                                                   *
*********************** Entrées *****************************
* Nom de l'image.                                           *
*********************** Sorties *****************************
* Retourne l'image de façon optimisée                       *
************************************************************/
SDL_Surface *load_image( SDL_Surface *screen, string filename )
{
    //Temporary storage for the image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;
    //Load the image
    loadedImage = IMG_Load( filename.c_str() );
    //If nothing went wrong in loading the image
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_ConvertSurface( loadedImage, screen->format, 0);

        //Free the old image
        SDL_FreeSurface( loadedImage );
    }
    //Return the optimized image
    return optimizedImage;
}


/****************** Nom de la fonction **********************
* loadImageWithColorKey                                     *
******************** Auteur , Dates *************************
* //, 16/11/16, Version 1.0                                 *
********************* Description ***************************
* Cette fonction permet de charger une image sur une        *
* surface                                                   *
*********************** Entrées *****************************
*                         //                                *
*********************** Sorties *****************************
*                         //                                *
************************************************************/
SDL_Surface *loadImageWithColorKey(SDL_Surface *screen, string filename, int r, int g, int b)
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_ConvertSurface( loadedImage, screen->format, 0 );

        //Free the old image
        SDL_FreeSurface( loadedImage );

        //If the image was optimized just fine
        if( optimizedImage != NULL )
        {
            //Map the color key
            Uint32 colorkey = SDL_MapRGB( optimizedImage->format, r, g, b );

            //Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent
            SDL_SetColorKey( optimizedImage, SDL_TRUE, colorkey );
        }


    }
    //Return the optimized image
    return optimizedImage;
}



/****************** Nom de la fonction **********************
* applySurface                                              *
******************** Auteur , Dates *************************
* //, 16/11/16, Version 1.0                                 *
********************* Description ***************************
* Cette fonction permet d'appliquer une image sur une       *
* surface                                                   *
*********************** Entrées *****************************
*                         //                                *
*********************** Sorties *****************************
*                         //                                *
************************************************************/

void applySurface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip)
    {
        SDL_Rect offset;
        offset.x = x;
        offset.y = y;
        SDL_BlitSurface( source, clip, destination, &offset );
    }


