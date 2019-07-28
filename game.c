/*

    FILE's NAME : game.c
    ROLE        : contains the game function
    AUTHOR      : KARM BAHRI | karim-bahri-18@outlook.fr
    DATE        : 17/07/2019






*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <fmod.h>
#include "management.h"
#include "consts.h"
#include "menu.h"
#include "game.h"


    /*-----------------------------------------------------------------------------------*/

        void game(SDL_Surface *screen , FMOD_SYSTEM *system , FMOD_CHANNELGROUP *channelgroup )
                {
                    /*-------------------------DECLARATIONS-------------------------*/

                    TTF_Font *font = NULL;
                    SDL_Surface *boxeOff = NULL , *boxeOn = NULL , *boxesNumberSurface[24] = {NULL};
                    SDL_Surface *background1 = NULL , *background2 = NULL , *table = NULL;
                    SDL_Event event;
                    SDL_Rect boxesPos[12][2] , posBackground , posTable;
                    SDL_bool running = SDL_TRUE;

                    /*-------------------------DECLARATIONS-------------------------*/


                        /*-------------------------INITIALISATION-------------------------*/


                        font = TTF_OpenFont("Lato-Black.ttf",16);

                        if(font == NULL)
                            SDL_ExitWithError(TTF,"Initialization error of TTF FONT");


                        background1 = IMG_Load("sprites/gameBackground1.png");

                            if(background1 == NULL)
                                SDL_ExitWithError(IMG,"Initialization error of SDL_Surface");

                        background2 = IMG_Load("sprites/gameBackground2.png");

                            if(background2 == NULL)
                                SDL_ExitWithError(IMG,"Initialization error of SDL_Surface");

                        table = IMG_Load("sprites/table.png");

                            if(table == NULL)
                                SDL_ExitWithError(IMG,"Initialization error of SDL_Surface");

                        boxeOn = IMG_Load("sprites/boxes/2.png");

                            if(boxeOn == NULL)
                                SDL_ExitWithError(IMG,"Initialization error of SDL_Surface");

                        boxeOff = IMG_Load("sprites/boxes/1.png");

                            if(boxeOff == NULL)
                                SDL_ExitWithError(IMG,"Initialization error of SDL_Surface");

                        set_position(&posBackground,0,0);
                        set_position(&posTable,95,555);
                        boxesPos_Create(boxesPos,12);


                        /*-------------------------INITIALISATION-------------------------*/


                /*------------------------------------------------------------------------------------*/


                        while(running)
                                {
                                    SDL_PollEvent(&event);

                                        switch(event.type)
                                            {
                                                case SDL_QUIT:
                                                    running = SDL_FALSE;
                                                        break;


                                            }

                                        SDL_BlitSurface(background1,NULL,screen,&posBackground);
                                        SDL_BlitSurface(background2,NULL,screen,&posBackground);
                                        SDL_BlitSurface(table,NULL,screen,&posTable);
                                        blitBoxe(screen,boxeOff,boxesPos,12);
                                        boxChoice(screen,boxeOn,boxesPos,&event);
                                        SDL_Flip(screen);
                                }

                /*------------------------------------------------------------------------------------*/




                        /*------------------------------MEMORIE RELEASE------------------------------*/

                                TTF_CloseFont(font);
                                SDL_FreeSurface(boxeOff);
                                SDL_FreeSurface(background1);
                                SDL_FreeSurface(background2);

                        /*------------------------------MEMORIE RELEASE------------------------------*/


                }




    /*-----------------------------------------------------------------------------------*/




     /*-----------------------------------------------------------------------------------*/

   void boxesPos_Create(SDL_Rect boxesPos[][2] , int nb)
                {
                    int X = 18 , Y1 = 119 , Y2 = 447;
                    for(int i = 0 ; i < nb ; i++)
                        {
                            set_position(&boxesPos[i][0],X,Y1);
                            set_position(&boxesPos[i][1],X,Y2);
                            X += 84;
                        }

                }

     /*-----------------------------------------------------------------------------------*/

   void blitBoxe(SDL_Surface *screen , SDL_Surface *boxe , SDL_Rect pos[][2] , int nb)
                {

                    for(int i = 0 ; i < nb ; i++)
                        for(int j = 0 ; j < 2 ; j++)
                            SDL_BlitSurface(boxe,NULL,screen,&pos[i][j]);

                }


   boxIndex boxChoice(SDL_Surface *screen , SDL_Surface *boxeOn , SDL_Rect boxesPos[][2] , SDL_Event *event)
                    {

                        boxIndex index;

                        /*--------------------------------------------------------------------------*/
                                       //if(Boxes_TestCollision(boxesPos,event,58,60,MOTION,&index))
                                       if(Boxes_TestEvent(event,MOTION,&index))
                                            SDL_BlitSurface(boxeOn,NULL,screen,&boxesPos[index.X][index.Y]);



                    }

     /*-----------------------------------------------------------------------------------*/

/*
     SDL_Surface **resizeSurface_box(SDL_Surface *boxes[] , int width , int height , const int nb)
                            {
                               for(int i = 0 ; i < nb ; i++)
                                     boxe[i]->w = width , boxe[i]->h = height;

                                    return boxe;

                            }

     /*-----------------------------------------------------------------------------------*/

  /*   void CreateNumberSurface_box(SDL_Surface *boxesNumber_Surface[] , TTF_Font *font , SDL_Color color , int tab[] , const int nb)

                            {
                                char txt[3] = { 0 };

                                for(int i = 0 ; i < nb ; i++)
                                    {
                                        sprintf(txt,"%d",tab[i]);

                                        boxesNumber_Surface[i] = TTF_RenderText_Solid(font,txt,color);

                                                if(boxesNumber_Surface[i] == NULL)
                                                    SDL_ExitWithError(TTF,"error of rendering SDL Surface .");
                                    }

                            }
*/

       /*-----------------------------------------------------------------------------------*/

  /*  int *generateNumber_Boxes(void)
                                    {
                                        srand(time(NULL));

                                        int boxesNumber[24] = {0};

                                            for(int i = 0 ; i < 24 ; i++)
                                                    {

                                                    }

                                    }


*/
