#include "plateau.h"
#include "SDL.h"
#include "monster.h"


/****************** Nom de la fonction **********************
* initTableau                                               *
******************** Auteur , Dates *************************
* Bascouzaraix Julien/Hourquet Jordan  Version 1            *
********************* Description ***************************
* Initialise toute les cases du tableau en Invisible        *
*  c'est à dire des cases vides                             *
*********************** EntrÃ©es *****************************
* Le tableau de monstre                                     *
*********************** Sorties *****************************
* Le tableau de monstre                                     *
************************************************************/
void initTableau(TGrille &tableau)
{
    for(int i = 0; i<TAILLE_X; i++)
    {
        for(int j = 0; j<TAILLE_Y;j++)
        {
            tableau[i][j] = INVISIBLE;
        }
    }

}
/****************** Nom de la fonction **********************
* initTabObstacle                                           *
******************** Auteur , Dates *************************
* Bascouzaraix Julien/Hourquet Jordan,  Version 1           *
********************* Description ***************************
* Initialise toutes les cases du tableau d'obstacle en      *
*  NUL c'est à dire des cases vides                         *
*********************** EntrÃ©es *****************************
* Le tableau d'obstacle                                     *
*********************** Sorties *****************************
* Le tableau d'obstacle                                     *
************************************************************/
void iniTabObstacle(TGrille2 &tableau2)
{
    for(int i = 0; i<TAILLE_X; i++)
    {
        for(int j = 0; j<TAILLE_Y;j++)
        {
            tableau2[i][j] = NUL;
        }
    }

}

/****************** Nom de la fonction **********************
* levelUn                                                   *
******************** Auteur , Dates *************************
* Bascouzaraix Julien/Hourquet Jordan,  Version 1           *
********************* Description ***************************
* Initialise le premier level du jeu                        *
*********************** EntrÃ©es *****************************
* tableau de monstre et d'obstacle                          *
*********************** Sorties *****************************
* tableau de monstre et d'obstacle                          *
************************************************************/
void levelUn(TGrille &tableau, TGrille2 &tableau2)
{
    tableau[0][5] = MON_MONSTRE;
    tableau[2][0] = ENDORMI;
    tableau[0][7] = ENDORMI;
    tableau[4][7] = MON_MONSTRE;
    tableau2[3][5] = LIVRE;
    tableau2[0][8] = GLACE;


}
/****************** Nom de la fonction **********************
* levelDeux                                                 *
******************** Auteur , Dates *************************
* Bascouzaraix Julien/Hourquet Jordan,  Version 1           *
********************* Description ***************************
* Initialise le deuxième level du jeu level du jeu          *
*********************** EntrÃ©es *****************************
* tableau de monstre et d'obstacle                          *
*********************** Sorties *****************************
* tableau de monstre et d'obstacle                          *
************************************************************/
void levelDeux(TGrille &tableau, TGrille2 &tableau2)
{
    tableau[0][4] = MON_MONSTRE;
    tableau[2][0] = ENDORMI;
    tableau2[2][5] = LIVRE;
    tableau2[0][3] = GLACE;

}


/****************** Nom de la fonction **********************
* finDuJeu                                                  *
******************** Auteur , Dates *************************
* Bascouzaraix Julien, version 1                            *
********************* Description ***************************
* Regarde si le niveau est terminé, si c'est le cas,        *
*          c'est la fin du jeu                              *
*********************** EntrÃ©es *****************************
* Le tableau de monstre, plus un booleen                    *
*********************** Sorties *****************************
* //                                                        *
************************************************************/
bool finDuJeu(TGrille tableau, bool fin)
{
    for(int i = 0; i<TAILLE_X; i++)
    {
        for(int j = 0; j<TAILLE_Y;j++)
        {
            if(tableau[i][j] == ENDORMI)
            {
                fin = false;
                return fin;

            }



            }
        }
    return fin = true;
    }



/****************** Nom de la fonction **********************
* afficherPlateau                                           *
******************** Auteur , Dates *************************
* Bascouzaraix Julien/Hourquet Jordan,  Version 1           *
********************* Description ***************************
* Affiche les sprites sur le tableau                        *
*********************** EntrÃ©es *****************************
* Le tableau d'obstacle et de monstre, le screen et         *
*  les deux structures : Monstre et Obstacle                *
*********************** Sorties *****************************
* Le screen                                                 *
************************************************************/
void afficherPlateau(TGrille tableau, TGrille2 tableau2, SDL_Surface *screen, Monstre monstre, Obstacle o)
{

    for(int i = 0; i<TAILLE_X; i++)
    {
        for(int j = 0; j<TAILLE_Y;j++)
        {

            monstre.x=MARGE_X + i * CASE_X;
            monstre.y=MARGE_Y + j * CASE_Y;

            switch(tableau[i][j])
            {
            case MON_MONSTRE:
                applySurface(monstre.x, monstre.y, monstre.source,screen,&monstre.lectureMonstreRouge);
                break;
            case ENDORMI:
                applySurface(monstre.x, monstre.y, monstre.source,screen,&monstre.lectureMonstreBleu);
                break;

            }
            switch(tableau2[i][j])
            {
            case GLACE:
                applySurface(MARGE_X + i * CASE_X, MARGE_Y + j * CASE_Y,o.source,screen,&o.lectureGlace);
                break;
            case LIVRE:
                applySurface(MARGE_X + i * CASE_X, MARGE_Y + j * CASE_Y,o.source,screen,&o.lectureLivres);
                break;

            }
        }
    }
}






/****************** Nom de la fonction **********************
* convertirPixelEnCase                                      *
******************** Auteur , Dates *************************
* Bascouzaraix Julien Version 1                             *
********************* Description ***************************
* Convertir une case de tableau en pixel, en                *
*  coordonnées de tableau(i,j)                              *
*********************** EntrÃ©es *****************************
* Une structure corresCasePixel                             *
*********************** Sorties *****************************
* Une structure corresCasePixel                             *
************************************************************/
void convertirPixelEnCase(corresCasePixel & souris){

    souris.i=(souris.x-MARGE_X)/CASE_X; // calcul de la ligne à partir des coordonnées x,y
    souris.j=(souris.y-MARGE_Y)/CASE_Y; // calcul de la colonne à partir des coordonnées x,y



}


/****************** Nom de la fonction **********************
* recupererCaseDisponible                                   *
******************** Auteur , Dates *************************
* Bascouzaraix Julien Version 1                             *
********************* Description ***************************
* Algorithme qui permet de trouver la case                  *
  ou le monstre doit s'arrêter dans son élan                *
*********************** EntrÃ©es *****************************
* Le tableau de monstre et d'obstacle, la case Initiale     *
  La structure corresCasePixel et un entier : reset         *
*********************** Sorties *****************************
* Toutes les entrées                                        *
************************************************************/
void recupererCaseDisponible(TGrille & tableau , TGrille2 & obstacles, caseTableau & caseInitiale, corresCasePixel & pos, int & reset)
{


    /** Avant de lire cette fonction, il faut savoir que dans notre cas, les colonnes sont les i et
     * les lignes sont les i, la confusion peut-être faite **/



    //retourne la derniere case disponible
    reset = 0;
    int lEnd=caseInitiale.j;
    int cEnd=caseInitiale.i;

    //bas
    if(caseInitiale.i == pos.i && caseInitiale.j < pos.j)
    {
        while(tableau[cEnd][lEnd+1] == INVISIBLE && obstacles[cEnd][lEnd+1] == NUL && lEnd <= TAILLE_Y)
            lEnd++;
        if(lEnd >= 8)
        {

            reset = -1;
        }


    }

    //haut
    else if(caseInitiale.i == pos.i && caseInitiale.j > pos.j)
    {
        std::cout << pos.i << ";" << pos.j << std::endl;

        while(tableau[cEnd][lEnd-1] == INVISIBLE && obstacles[cEnd][lEnd-1] == NUL && lEnd >= 0 )
            lEnd--;
        if(lEnd <= 0)
        {

            reset = -1;
        }



    }

    //droite
    else if(caseInitiale.i < pos.i && caseInitiale.j == pos.j)
    {
        while(tableau[cEnd+1][lEnd] == INVISIBLE && obstacles[cEnd+1][lEnd] == NUL)
            cEnd++;
        if(cEnd >= 4)
        {

            reset = -1;
        }




    }

    //gauche
    else if(caseInitiale.i > pos.i && caseInitiale.j == pos.j)
    {
        while(tableau[cEnd-1][lEnd] == INVISIBLE && obstacles[cEnd-1][lEnd] == NUL)
            cEnd--;
        if(cEnd == 0)
        {
            reset = -1;
        }

    }

    pos.i=cEnd;
    pos.j=lEnd;


}


