#include "SDL.h"
#include "monster.h"
#include "plateau.h"

/****************** Nom de la fonction **********************
* initMonster                                               *
******************** Auteur , Dates *************************
* Bascouzaraix Julien, 16/11/16, Version 1                  *
********************* Description ***************************
* Initialise les carrés de lectures des sprites des monstres*
*********************** EntrÃ©es *****************************
* Une structure Monstre                                     *
*********************** Sorties *****************************
* Une structure Monstre                                     *
************************************************************/
void initMonster(Monstre &m)
{
    // Carré de lecture des sprites des monstres.

    m.lectureMonstreRouge.x = 10;
    m.lectureMonstreRouge.y = 140;
    m.lectureMonstreRouge.w = 60;
    m.lectureMonstreRouge.h = 60;

    m.lectureMonstreBleu.x = 5;
    m.lectureMonstreBleu.y = 0;
    m.lectureMonstreBleu.w = 70;
    m.lectureMonstreBleu.h = 70;


}

/****************** Nom de la fonction **********************
* initObstacle                                              *
******************** Auteur , Dates *************************
* Bascouzaraix Julien, 16/11/16, Version 1                  *
********************* Description ***************************
* Initialise les carrés de lectures des obstacles           *
*********************** EntrÃ©es *****************************
* Une structure Obstacle                                    *
*********************** Sorties *****************************
* Une structure Obstacle                                    *
************************************************************/
void initObstacle(Obstacle & o)
{
    o.lectureGlace.x = 10;
    o.lectureGlace.y = 70;
    o.lectureGlace.w = 60;
    o.lectureGlace.h = 60;

    o.lectureLivres.x = 70;
    o.lectureLivres.y = 65;
    o.lectureLivres.w = 60;
    o.lectureLivres.h = 65;

    o.lectureFlecheBas.x = 15;
    o.lectureFlecheBas.y = 220;
    o.lectureFlecheBas.w = 45;
    o.lectureFlecheBas.h = 45;

    o.lectureFlecheHaut.x = 60;
    o.lectureFlecheHaut.y = 220;
    o.lectureFlecheHaut.w = 45;
    o.lectureFlecheHaut.h = 45;

    o.lectureFlecheDroite.x = 110;
    o.lectureFlecheDroite.y = 220;
    o.lectureFlecheDroite.w = 45;
    o.lectureFlecheDroite.h = 45;

    o.lectureFlecheGauche.x = 155;
    o.lectureFlecheGauche.y = 220;
    o.lectureFlecheGauche.w = 45;
    o.lectureFlecheGauche.h = 45;

}




/****************** Nom de la fonction **********************
* deplacerMonstre                                           *
******************** Auteur , Dates *************************
* Bascouzaraix Julien,  Version 5                           *
********************* Description ***************************
* Déplace le monstre sur le tableau et gère les différentes *
*          condition du jeu                                 *
*********************** EntrÃ©es *****************************
* une structure Monstre, les coordonnées de la case         *
*  Initiale et destination et le tableau de monstre         *
*********************** Sorties *****************************
* La structure Monstre et le tableau de monstre             *
************************************************************/
void deplacerMonstre (Monstre &m, caseTableau caseInitiale, caseTableau caseDestination, TGrille & tableau)
{


    const int velocity_x = 3, velocity_y = 3;


    // bas
    if(caseInitiale.i == caseDestination.i && caseInitiale.j < caseDestination.j)
    {

        if(tableau[caseDestination.i][caseDestination.j] == tableau[caseInitiale.i][caseInitiale.j])
        {

        }
        else
        {
            m.y += velocity_y;
            SDL_Delay(100);
        tableau[caseDestination.i][caseDestination.j] = MON_MONSTRE;
        tableau[caseInitiale.i][caseInitiale.j] = INVISIBLE;
        }
        if(tableau[caseDestination.i][caseDestination.j+1] == ENDORMI)
            tableau[caseDestination.i][caseDestination.j+1] = MON_MONSTRE;


    }

    // haut
    else if(caseInitiale.i == caseDestination.i && caseInitiale.j > caseDestination.j)
    {
        m.y -= velocity_y;
        SDL_Delay(100);
        if(tableau[caseDestination.i][caseDestination.j] == tableau[caseInitiale.i][caseInitiale.j])
        {

        }
        else
        {
        m.y -= velocity_y;
        SDL_Delay(100);
        tableau[caseDestination.i][caseDestination.j] = MON_MONSTRE;
        tableau[caseInitiale.i][caseInitiale.j] = INVISIBLE;
        }
        if(tableau[caseDestination.i][caseDestination.j-1] == ENDORMI)
            tableau[caseDestination.i][caseDestination.j-1] = MON_MONSTRE;


    }
    // droite
    else if(caseInitiale.i < caseDestination.i && caseInitiale.j == caseDestination.j)
    {

        if(tableau[caseDestination.i][caseDestination.j] == tableau[caseInitiale.i][caseInitiale.j])
        {

        }
        else
        {
        m.x += velocity_x;
        SDL_Delay(100);
        tableau[caseDestination.i][caseDestination.j] = MON_MONSTRE;
        tableau[caseInitiale.i][caseInitiale.j] = INVISIBLE;
        }
        if(tableau[caseDestination.i+1][caseDestination.j] == ENDORMI)
            tableau[caseDestination.i+1][caseDestination.j] = MON_MONSTRE;
    }
    // gauche
    else if(caseInitiale.i > caseDestination.i && caseInitiale.j == caseDestination.j)
    {
        if(tableau[caseDestination.i][caseDestination.j] == tableau[caseInitiale.i][caseInitiale.j])
        {

        }
        else
        {
        m.x -= velocity_y;
        SDL_Delay(100);
        tableau[caseDestination.i][caseDestination.j] = MON_MONSTRE;
        tableau[caseInitiale.i][caseInitiale.j] = INVISIBLE;
        }
        if(tableau[caseDestination.i-1][caseDestination.j] == ENDORMI)
            tableau[caseDestination.i-1][caseDestination.j] = MON_MONSTRE;

    }


}





