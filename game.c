/*

    FILE's NAME : game.c
    ROLE        : contains the game function
    AUTHOR      : KARM BAHRI | karim-bahri-18@outlook.fr
    DATE        : 17/07/2019






*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

                    TTF_Font *txtFont = NULL;
                    SDL_Surface *Amounts[24][17] = {NULL};
                    SDL_Surface *peopleOn[24] = {NULL} , *peopleOff[24] = {NULL} , *boxeOff[24] = {NULL} , *boxeOn[24] = {NULL} , *boxesNumberSurface[24] = {NULL};
                    SDL_Surface *background1 = NULL , *background2 = NULL , *table = NULL , *textSurface = NULL;
                    SDL_Event event;
                    SDL_Rect boxesPos[12][2] , peoplePos[12][2] , amountPos[12][2] , posBackground , posTable , posNumber , textPos;
                    SDL_Color color = { 212 , 255 , 0 };
                    SDL_bool running = SDL_TRUE , SHOW_MODE = SDL_FALSE; //LIMITED OR EXTENDED
                    RUN_SITUATION situation = BOX_CHOICE;
                    int *boxNumber = NULL;

                    /*-------------------------DECLARATIONS-------------------------*/


                        /*-------------------------INITIALISATION-------------------------*/


                       // font = TTF_OpenFont("arial.ttf",16);

                     //   if(font == NULL)
                       //     SDL_ExitWithError(TTF,"Initialization error of TTF FONT");

                        peopleSurface_Create(peopleOn,peopleOff,24);

                        createAmountsSurface(Amounts,24,17);


                        background1 = IMG_Load("sprites/gameBackground1.png");

                            if(background1 == NULL)
                                SDL_ExitWithError(IMG,"Initialization error of SDL_Surface");

                        background2 = IMG_Load("sprites/gameBackground2.png");

                            if(background2 == NULL)
                                SDL_ExitWithError(IMG,"Initialization error of SDL_Surface");


                        table = IMG_Load("sprites/table.png");

                            if(table == NULL)
                                SDL_ExitWithError(IMG,"Initialization error of SDL_Surface");

                        txtFont = TTF_OpenFont("calibri.ttf",25);

                            if(txtFont == NULL)
                                SDL_ExitWithError(TTF,"Initialization error of TTF_Font");

                        textSurface = TTF_RenderText_Blended(txtFont,"Press F to hide the amountsBoard .",color);
                        set_position(&textPos,350,655);
                        set_position(&posBackground,0,0);
                        set_position(&posTable,95,555);
                        set_position(&posNumber,5,35);
                        peoplePos_Create(peoplePos,12);
                        amountsPos_Create(amountPos,12);
                        boxesPos_Create(boxesPos,12);
                        boxNumber = generateNumber_Boxes(24);
                        CreateNumberSurface_box(boxesNumberSurface,NULL,boxNumber,24);
                        boxesSurface_Create(boxeOn,boxeOff,boxesNumberSurface,&posNumber,24);


                        /*-------------------------INITIALISATION-------------------------*/


                /*------------------------------------------------------------------------------------*/
                if(!Choose_Your_Box(&event,screen,boxeOn,boxeOff,peopleOn,background1,background2,table,boxesPos,peoplePos,&posBackground,&posTable,&posNumber))
                        running = SDL_FALSE;
                /*------------------------------------------------------------------------------------*/

                    changeEvent(&event);
                        while(running)
                                {
                                        SDL_PollEvent(&event);

                                        switch(event.type)
                                            {
                                                case SDL_QUIT:
                                                    running = SDL_FALSE;
                                                        break;

                                                case SDL_KEYDOWN:
                                                    switch(event.key.keysym.sym)
                                                            {
                                                                    case SDLK_f:
                                                                        situation = SHOW_AMOUNT;
                                                                        SHOW_MODE = SDL_TRUE; // EXTENDED.
                                                                            break;
                                                            }
                                                            break;



                                            }

                                        SDL_BlitSurface(background1,NULL,screen,&posBackground);
                                        SDL_BlitSurface(background2,NULL,screen,&posBackground);
                                        SDL_BlitSurface(table,NULL,screen,&posTable);
                                        blitSurfaces(screen,peopleOff,peoplePos,12,PEOPLE);
                                        blitSurfaces(screen,boxeOff,boxesPos,12,BOX);
                                        boxChoice(screen,boxeOn,peopleOn,boxesPos,peoplePos,&event,situation);
                                        blitAmounts(screen,Amounts,amountPos,textSurface,&textPos,24,&situation,&running,&SHOW_MODE);
                                        SDL_Flip(screen);

                                }

                /*------------------------------------------------------------------------------------*/




                        /*------------------------------MEMORIE RELEASE------------------------------*/

                                free(boxNumber);
                                peopleSurface_Release(peopleOn,peopleOff,24);
                                AmountsSurface_Release(Amounts,24,17);
                                TTF_CloseFont(txtFont);
                                SDL_FreeSurface(boxeOff);
                                SDL_FreeSurface(background1);
                                SDL_FreeSurface(background2);

                        /*------------------------------MEMORIE RELEASE------------------------------*/


                }




    /*-----------------------------------------------------------------------------------*/

        void boxesSurface_Create(SDL_Surface *boxesOnSurface[] , SDL_Surface *boxesOffSurface[] , SDL_Surface *numberSurface[] , SDL_Rect *posNumber , int nb)
                            {
                                for( int i = 0 ; i < nb ; i++)
                                            {
                                                boxesOffSurface[i] = IMG_Load("sprites/boxes/1.png");

                                                    if(boxesOffSurface[i] == NULL)
                                                            SDL_ExitWithError(IMG,"Initialization error of SDL_Surface");

                                                boxesOnSurface[i] =  IMG_Load("sprites/boxes/2.png");

                                                    if(boxesOnSurface[i] == NULL)
                                                            SDL_ExitWithError(IMG,"Initialization error of SDL_Surface");


                                               SDL_BlitSurface(numberSurface[i],NULL,boxesOffSurface[i],posNumber);
                                               SDL_BlitSurface(numberSurface[i],NULL,boxesOnSurface[i],posNumber);

                                            }


                            }

     /*-----------------------------------------------------------------------------------*/

      void peopleSurface_Create(SDL_Surface *peopleOn[] , SDL_Surface *peopleOff[] , int nb)
                                    {
                                        char txt[20] = {NULL};

                                            for( int i = 0 ; i < nb ; i++)
                                                    {
                                                        sprintf(txt,"sprites/people/%dOn.png",i + 1);
                                                        peopleOn[i] = IMG_Load(txt);

                                                            if(peopleOn == NULL)
                                                                    SDL_ExitWithError(IMG,"Initialization error of SDL_Surface");


                                                        sprintf(txt,"sprites/people/%dOff.png",i + 1);
                                                        peopleOff[i] = IMG_Load(txt);

                                                            if(peopleOff == NULL)
                                                                    SDL_ExitWithError(IMG,"Initialization error of SDL_Surface");
                                                    }

                                    }


     /*-----------------------------------------------------------------------------------*/


     void peopleSurface_Release(SDL_Surface *peopleOn[] , SDL_Surface *peopleOff[] , int nb)

            {
                for( int i = 0 ; i < nb ; i++)
                        {
                            SDL_FreeSurface(peopleOn[i]);
                            SDL_FreeSurface(peopleOff[i]);
                        }

            }


     /*-----------------------------------------------------------------------------------*/

   void boxesPos_Create(SDL_Rect boxesPos[][2] , int nb)
                {
                    int X = 34 , Y1 = 119 , Y2 = 447;
                    for(int i = 0 ; i < nb ; i++)
                        {
                            set_position(&boxesPos[i][0],X,Y1);
                            set_position(&boxesPos[i][1],X,Y2);
                            X += 84;
                        }

                }


     /*-----------------------------------------------------------------------------------*/

     void peoplePos_Create(SDL_Rect peoplePos[][2] , int nb)
                {
                   // int X = 66 , Y1 = 53 , Y2 = 380;
                   int X = 100 , Y1 = 53 , Y2 = 380;

                    set_position(&peoplePos[0][0],17,Y1);
                    set_position(&peoplePos[0][1],17,Y2);

                        for( int i = 1 ; i < nb ; i++ )
                                    {
                                        set_position(&peoplePos[i][0],X,Y1);
                                        set_position(&peoplePos[i][1],X,Y2);
                                        X += 83;
                                    }


                }

     /*-----------------------------------------------------------------------------------*/

     void amountsPos_Create(SDL_Rect amountsPos[][2] , int nbX)
                        {
                                    int X1 = 30 , X2 = 795 , Y = 30;

                                    for (int i = 0 ; i < nbX ; i++)
                                                {
                                                    set_position(&amountsPos[i][0],X1,Y);
                                                    set_position(&amountsPos[i][1],X2,Y);
                                                    Y += 50;

                                                }
                        }


     /*-----------------------------------------------------------------------------------*/

   void blitSurfaces(SDL_Surface *screen , SDL_Surface *Surfaces[] , SDL_Rect pos[][2] , int nb , SURFACE_TYPE SURFACE)
                {
                    int k = 0;
                        if(SURFACE == PEOPLE)
                            {
                            for(int j = 0 ; j < 2 ; j++)
                                for(int i = 0 ; i < nb ; i++)
                                    {
                                      if(pos[i][j].x && pos[i][j].y && Surfaces  )
                                        {
                                            SDL_BlitSurface(Surfaces[k],NULL,screen,&pos[i][j]);
                                            k++;
                                        }

                                    }
                            }
                       else
                             {
                            for(int j = 0 ; j < 2 ; j++)
                                for(int i = 0 ; i < nb ; i++)
                                    {
                                      if(pos[i][j].x && pos[i][j].y && Surfaces || (SURFACE == PEOPLE) )
                                        {
                                            SDL_BlitSurface(Surfaces[k],NULL,screen,&pos[i][j]);

                                        }
                                            k++;

                                    }
                            }

                }
    /*-----------------------------------------------------------------------------------*/
                void blitAmounts(SDL_Surface *screen , SDL_Surface *amounts[][17] , SDL_Rect amountPos[][2] ,  SDL_Surface *txtSurface , SDL_Rect *textPos , int nb , RUN_SITUATION *situation , SDL_bool *running , SDL_bool *SHOW_MODE)
                        {

                            if(*situation)
                            {


                                   static unsigned int posX_index = 0 , posY_index = 0 , amountX_index = 0;
                                   static SDL_bool AMOUNT_BLIT = SDL_FALSE;



                                            /*------------------SHOW---AMOUNT------------------*/
                                               ShowAmounts(screen,amounts,amountPos,&posX_index,&posY_index,&amountX_index,nb,&AMOUNT_BLIT);
                                            /*------------------SHOW---AMOUNT------------------*/

                                            /*-----------------------------SHOW--TEXT-----------------------------*/
                                            SDL_BlitSurface(txtSurface,NULL,screen,textPos);
                                            /*-----------------------------SHOW--TEXT-----------------------------*/

                                            if(AMOUNT_BLIT && (amountX_index == 16))
                                               *running = wait(3000,SHOW_MODE);


                                             /*------------------HIDE---AMOUNT------------------*/
                                                HideAmounts(screen,amounts,amountPos,&posX_index,&posY_index,&amountX_index,nb,&AMOUNT_BLIT,situation);
                                             /*------------------HIDE---AMOUNT------------------*/


                            }

                        }

    /*-----------------------------------------------------------------------------------*/

                void ShowAmounts(SDL_Surface *screen , SDL_Surface *amounts[][17] , SDL_Rect amountPos[][2] , int *posX_index , int *posY_index , int *amountX_index , int nb , SDL_bool *AMOUNT_BLIT )
                        {

                            if(!*AMOUNT_BLIT)
                            {
                               int taskProgress = 0;
                                for(int i = 0 ; i < nb ; i++)
                                                {
                                            *posY_index = i / 12;
                                            taskProgress = i;
                                            /*-----------------------------------*/
                                            if(amountPos[*posX_index][*posY_index].x && amountPos[*posX_index][*posY_index].y)
                                                SDL_BlitSurface(amounts[i][*amountX_index],NULL,screen,&amountPos[*posX_index][*posY_index]);
                                            /*-----------------------------------*/
                                            (*posX_index)++ , (*posX_index) %= 12;

                                                }
                                        (*amountX_index)++ , (*amountX_index) %= 17;
                                        *AMOUNT_BLIT = (*amountX_index / 16) && (taskProgress / 23);
                            }

                        }

           /*-----------------------------------------------------------------------------------*/

                void HideAmounts(SDL_Surface *screen , SDL_Surface *amounts[][17] , SDL_Rect amountPos[][2] , int *posX_index , int *posY_index , int *amountX_index , int nb , SDL_bool *AMOUNT_BLIT , SDL_bool *SHOW_MODE)
                        {
                           if(*AMOUNT_BLIT)
                           {
                               int taskProgress = 0;
                                for(int i = 0 ; i < nb ; i++)
                                                {
                                            *posY_index = i / 12;
                                            taskProgress = i;
                                            /*-----------------------------*/
                                            if(amountPos[*posX_index][*posY_index].x && amountPos[*posX_index][*posY_index].y)
                                                    SDL_BlitSurface(amounts[i][*amountX_index],NULL,screen,&amountPos[*posX_index][*posY_index]);
                                            /*-----------------------------*/
                                            (*posX_index)++ , (*posX_index) %= 12;

                                                }
                                        (*amountX_index)-- , (*amountX_index) %= 17;

                                         *AMOUNT_BLIT = *amountX_index  , *SHOW_MODE = *amountX_index;
                           }

                        }

           /*-----------------------------------------------------------------------------------*/

   boxIndex boxChoice(SDL_Surface *screen , SDL_Surface *boxeOn[] , SDL_Surface *peopleOn[] , SDL_Rect boxesPos[][2] , SDL_Rect peoplePos[][2] , SDL_Event *event , RUN_SITUATION situation)
                    {

                        if(!situation)
                            {

                                boxIndex index;
                                int i = 0;

                                /*--------------------------------------------------------------------------*/
                                               //if(Boxes_TestCollision(boxesPos,event,58,60,MOTION,&index))
                                               if(Boxes_TestEvent(event,MOTION,&index))
                                                {
                                                   if(boxesPos[index.X][index.Y].x && boxesPos[index.X][index.Y].y)
                                                   {
                                                    i = ( index.Y * 12 ) + index.X ;
                                                        if(peopleOn != NULL)
                                                            SDL_BlitSurface(peopleOn[i],NULL,screen,&peoplePos[index.X][index.Y]);

                                                        if(boxeOn != NULL)
                                                            SDL_BlitSurface(boxeOn[i],NULL,screen,&boxesPos[index.X][index.Y]);
                                                   }
                                                }

                            }
                    }

     /*-----------------------------------------------------------------------------------*/



     void CreateNumberSurface_box(SDL_Surface *boxesNumber_Surface[] , TTF_Font *font , int boxesNumbers[] , const int nb)

                            {
                                char txt[20] = { 0 };

                                /*-------------------------------------*/

                                  /*  numberBackground = SDL_CreateRGBSurface(SDL_HWSURFACE | SDL_DOUBLEBUF ,25,22,32,0,0,0,0);

                                        if(numberBackground == NULL)
                                            SDL_ExitWithError(SDL,"Initialization error of SDL_Surface");

                                   //SDL_FillRect(numberBackground,NULL,SDL_MapRGB(numberBackground->format,0,255,255));*/

                                /*-------------------------------------*/

                                for(int i = 0 ; i < nb ; i++)
                                    {
                                        sprintf(txt,"sprites/boxes/numbers/%d.png",boxesNumbers[i]);

                                        //numberBackground = TTF_RenderText_Solid(font,txt,color);
                                         //TTF_SetFontStyle(font,TTF_STYLE_BOLD);
                                        boxesNumber_Surface[i] = IMG_Load(txt);


                                                if(boxesNumber_Surface[i] == NULL)
                                                    SDL_ExitWithError(IMG,"Initialization error of SDL_Surface.");
                                    }

                            }


       /*-----------------------------------------------------------------------------------*/

            void createAmountsSurface(SDL_Surface *amounts[][17] , int nbX , int nbY)
                    {
                        char fileName[31] = {NULL};
                        for(int i = 0 ; i < nbX ; i++)
                            for(int j = 0 ; j < nbY ; j++)
                                    {
                                        sprintf(fileName,"sprites/AmountsBoard/%d/%d.png",i+1,j);

                                        amounts[i][j] = IMG_Load(fileName);
                                            if(amounts[i][j] == NULL)
                                                SDL_ExitWithError(IMG,"Initialization error of SDL_Surface.");
                                    }


                    }

          void AmountsSurface_Release(SDL_Surface *amounts[][17] , int nbX , int nbY)
                            {

                                for(int i = 0 ; i < nbX ; i++)
                                    for(int j = 0 ; j < nbY ; j++)
                                        SDL_FreeSurface(amounts[i][j]);

                            }

       /*-----------------------------------------------------------------------------------*/

    int *generateNumber_Boxes( int numb)
                                    {
                                        int tmp = 0 , r = 0;
                                        srand(time(NULL));

                                        int *boxesNumber = malloc(numb * sizeof(int));

                                            if(boxesNumber == NULL)
                                                SDL_ExitWithError(FMOD,"ERROR OF ARRAY ALLOCATION !");

                                          /*--------------INISIALISATION--------------*/
                                            for(int i = 0 ; i < numb ; i++)
                                                    boxesNumber[i] = i + 1;
                                          /*--------------INISIALISATION--------------*/

                                            for(int i = 0 ; i < numb ; i++)
                                                        {
                                                            r = rand() % 23 + 1;
                                                            /*---------PERMUTATION---------*/
                                                            tmp = boxesNumber[i];
                                                            boxesNumber[i] = boxesNumber[r];
                                                            boxesNumber[r] = tmp;
                                                            /*---------PERMUTATION---------*/


                                                        }

                                          return boxesNumber;
                                    }




        /*-----------------------------------------------------------------------------------*/

        SDL_bool Choose_Your_Box(SDL_Event *event , SDL_Surface *screen , SDL_Surface *boxesOn[] , SDL_Surface *boxesOff[]  , SDL_Surface *peopleOn[] , SDL_Surface *background1 , SDL_Surface *background2 , SDL_Surface *table , SDL_Rect BoxesPos[][2] , SDL_Rect peoplePos[][2] , SDL_Rect *posBackground , SDL_Rect *posTable , SDL_Rect *posNumber )
                        {

                           /*---------------------------------------------DECLARATION---------------------------------------------*/

                            SDL_Surface *text_Surface = NULL;
                            TTF_Font *font = NULL;
                            SDL_Rect posTXT;
                            boxIndex index;
                            SDL_Color color = { 0 , 150 , 255};
                            SDL_bool running = SDL_TRUE , keepProcess = SDL_TRUE;




                            /*---------------------------------------------DECLARATION---------------------------------------------*/

                            /*---------------------------------------------INITIALISATION---------------------------------------------*/

                                font = TTF_OpenFont("Nirmala.ttf",50);

                                    if(font == NULL)
                                        SDL_ExitWithError(TTF,"Initialization error of TTF_FONT.");

                               //TTF_SetFontHinting(font,TTF_HINTING_LIGHT);
                               //TTF_SetFontStyle(font,TTF_STYLE_BOLD);
                            /*---------------------------------------------INITIALISATION---------------------------------------------*/
                                set_position(&posTXT,180,325);
                                /*--------------------------------------------------------*/

                                    while(running)
                                            {
                                                SDL_PollEvent(event);

                                                /*------------------------------------------------------------*/
                                                  switch(event->type)
                                                        {
                                                            case SDL_QUIT:
                                                                running = SDL_FALSE;
                                                                keepProcess = SDL_FALSE;
                                                                    break;
                                                        }

                                                  //if(Boxes_TestCollision(BoxesPos,event,58,60,CLICK,&index))
                                                  if(Boxes_TestEvent(event,CLICK,&index))
                                                        {
                                                            int i = ( index.Y * 12 ) + index.X ;
                                                            set_position(&BoxesPos[index.X][index.Y],0,0);
                                                            set_position(&peoplePos[index.X][index.Y],0,0);
                                                            box_shift(peopleOn,i,24);
                                                            running = SDL_FALSE;
                                                        }
                                                /*------------------------------------------------------------*/
                                            mixe_Colors(&color);
                                            text_Surface = TTF_RenderText_Blended(font,"CHOOSE YOUR BOX",color);

                                                /*----------------------------------------------*/
                                                            SDL_BlitSurface(background1,NULL,screen,posBackground);
                                                            SDL_BlitSurface(background2,NULL,screen,posBackground);
                                                            SDL_BlitSurface(table,NULL,screen,posTable);
                                                            blitSurfaces(screen,boxesOff,BoxesPos,12,BOX);
                                                            boxChoice(screen,boxesOn,NULL,BoxesPos,BoxesPos,event,0);
                                                            SDL_BlitSurface(text_Surface,NULL,screen,&posTXT);
                                                            SDL_Flip(screen);

                                                            SDL_FreeSurface(text_Surface);
                                            }

                                /*--------------------------------------------------------*/

                                TTF_CloseFont(font);

                                return keepProcess;
                        }

        /*-----------------------------------------------------------------------------------*/

            void mixe_Colors(SDL_Color *color)
                    {
                      static int colorState[3] = {};

                    /*----------------------------------------------*/
                        if(color->r == 255)
                            colorState[0] = COLOR_DOWN;
                        if(color->r == 0)
                            colorState[0] = COLOR_UP;

                        if(color->g == 255)
                            colorState[1] = COLOR_DOWN;
                        if(color->g == 0)
                            colorState[1] = COLOR_UP;

                        if(color->b == 255)
                            colorState[2] = COLOR_DOWN;
                        if(color->b == 0)
                            colorState[2] = COLOR_UP;

                    /*----------------------------------------------*/


                                    if(colorState[0] == COLOR_DOWN)
                                        color->r--;
                                    else
                                        color->r++;

                                    if(colorState[1] == COLOR_DOWN)
                                        color->g--;
                                    else
                                        color->g++;

                                    if(colorState[2] == COLOR_DOWN)
                                        color->b--;
                                    else
                                        color->b++;


                    }



