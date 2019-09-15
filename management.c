/*

    FILE's NAME : main.c
    ROLE        : contains the management functions
    AUTHOR      : KARM BAHRI | karim-bahri-18@outlook.fr
    DATE        : 11/07/2019






*/


#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <fmod.h>
#include "management.h"
#include "consts.h"
#include "menu.h"
#include "game.h"


/*-----------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------*/



    void SDL_ExitWithError(ERROR_TYPE error , char *txt)
        {
            if(error == SDL)
                        fprintf(stderr,"%s : '%s' .",txt,SDL_GetError());

             else if (error == TTF)
                        fprintf(stderr,"%s : '%s' .",txt,TTF_GetError());

             else if (error == IMG)
                        fprintf(stderr,"%s : '%s' .",txt,IMG_GetError());
             else if (error == FMOD)
                        fprintf(stderr,"%s .",txt);


                    exit(EXIT_FAILURE);
        }


    /*---------------------------------------------------------------------------------------------------------------*/


    SDL_bool collision_MouseTest(EVENT_TYPE mouse,int width , int height , SDL_Rect *pos , SDL_Event *event)
                {
                    if(mouse == CLICK)
                                {

                                    if(event->type == SDL_MOUSEBUTTONUP)
                                        {
                                            if(event->button.button == SDL_BUTTON_LEFT)
                                                {
                                                    if( (event->button.x > pos->x && event->button.x < (pos->x + width) ) && (event->button.y > pos->y && event->button.y < (pos->y + height) ))
                                                            return SDL_TRUE;
                                                    else
                                                            return SDL_FALSE;
                                                }
                                            else
                                                    return SDL_FALSE;
                                        }
                                   else
                                            return SDL_FALSE;
                                }

                    else if(mouse == MOTION)
                                {

                                            if( (event->motion.x > pos->x && event->motion.x < (pos->x + width) ) && (event->motion.y > pos->y && event->motion.y < (pos->y + height) ))
                                                    return SDL_TRUE;
                                            else
                                                    return SDL_FALSE;

                                }



                }





    /*---------------------------------------------------------------------------------------------------------------*/


            SDL_bool Box_TestCollision(SDL_Rect *boxPos , SDL_Event *event , int width , int height , EVENT_TYPE mouse)
                    {
                        int X = 3 , Y = 29;

                            if(mouse == CLICK)
                                    {
                                        if(event->type == SDL_MOUSEBUTTONUP)
                                           {
                                            if( ((event->button.x > (boxPos->x + X) ) && (event->button.x < (boxPos->x + width) )) && ( (event->button.y > (boxPos->y + Y) ) && (event->button.y < (boxPos->y + height) ) ) )
                                                    return SDL_TRUE;
                                            else
                                                    return SDL_FALSE;
                                           }
                                        else
                                            return SDL_FALSE;

                                    }

                            else if(mouse == MOTION)
                                    {
                                        if( ((event->motion.x > (boxPos->x + X) ) && (event->motion.x < (boxPos->x + width) )) && ( (event->motion.y > (boxPos->y + Y) ) && (event->motion.y < (boxPos->y + height) ) ) )
                                                    return SDL_TRUE;
                                            else
                                                    return SDL_FALSE;

                                    }
                    }


    /*---------------------------------------------------------------------------------------------------------------*/

            SDL_bool Boxes_TestCollision(SDL_Rect boxesPos[][2] , SDL_Event *event , int width , int height , EVENT_TYPE mouse , boxIndex *index)
                            {
                                SDL_bool result = SDL_FALSE;
                                    for(int i = 0 ; i < 12 ; i++)
                                        for(int j = 0 ; j < 2 ; j++)
                                                if(Box_TestCollision(&boxesPos[i][j],event,width,height,mouse))
                                                    {
                                                        result = SDL_TRUE;
                                                            index->X = i , index->Y = j;
                                                    }


                                    return result;

                            }



    /*---------------------------------------------------------------------------------------------------------------*/

           SDL_bool  Boxes_TestEvent(SDL_Event *event , EVENT_TYPE mouse , boxIndex *index)
                        {
                            int p = 0;

                            p = (event->motion.x - POS_START) / LENGTH;
                               if(mouse == MOTION)
                                        {
                                            if( ( (event->motion.x > (LENGTH * p ) + POS_START ) && (event->motion.x < (  LENGTH * (p + 1) - DISTANCE_BOX_BOX + POS_START) ) ) && ( ( ( event->motion.y > BOX_Y_1 ) && ( event->motion.y < (BOX_Y_1 + BOX_HEIGHT) ) ) || ( ( event->motion.y > BOX_Y_2 ) && ( event->motion.y < (BOX_Y_2 + BOX_HEIGHT) ) ) ) )
                                                            {
                                                                index->X = p ;
                                                                index->Y = ( event->motion.y / (HEIGHT / 2 ) );
                                                                    return SDL_TRUE;

                                                            }
                                            else
                                                return SDL_FALSE;
                                        }

                                else if(mouse == CLICK)
                                        {
                                        if(event->type == SDL_MOUSEBUTTONUP)
                                            {

                                            if( ( (event->button.x > (LENGTH * p ) + POS_START ) && (event->button.x < ( LENGTH * (p + 1) - DISTANCE_BOX_BOX + POS_START) ) ) && ( ( ( event->button.y > BOX_Y_1 ) && ( event->button.y < (BOX_Y_1 + BOX_HEIGHT) ) ) || ( ( event->button.y > BOX_Y_2 ) && ( event->button.y < (BOX_Y_2 + BOX_HEIGHT) ) ) ) )
                                                            {
                                                                index->X = p ;
                                                                index->Y = ( event->button.y / (HEIGHT / 2 ) );
                                                                    return SDL_TRUE;

                                                            }
                                            else
                                                    return SDL_FALSE;

                                            }
                                        else
                                            return SDL_FALSE;

                                        }


                        }

    /*---------------------------------------------------------------------------------------------------------------*/



    void breakProcess(void)
        {
            SDL_WaitEvent(NULL);
        }

    /*---------------------------------------------------------------------------------------------------------------*/

    SDL_bool check_focus(SDL_Event *event)
                {
                    SDL_Rect pos;
                    set_position(&pos,0,0);

                                    if( ( ( (event->active.state & SDL_APPMOUSEFOCUS) == SDL_APPMOUSEFOCUS)  && (!collision_MouseTest(CLICK,WIDTH,HEIGHT,&pos,event))) || (  (event->active.state & SDL_APPINPUTFOCUS) == SDL_APPINPUTFOCUS) || ((event->active.state & SDL_APPACTIVE) == SDL_APPACTIVE ) )
                                            {

                                                    if(!event->active.gain)
                                                        return SDL_FALSE;
                                                    else
                                                        return SDL_TRUE;

                                            }
                                   else
                                       return SDL_TRUE;

                                }


    /*---------------------------------------------------------------------------------------------------------------*/


    SDL_Rect set_position(SDL_Rect *position , int x , int y)
                    {
                        position->x = x;
                        position->y = y;

                        return *position;
                    }


     /*--------------------------------------------------------------------------------------------------------------*/


     void box_shift(SDL_Surface *box[] , int beginning , int nb)

            {
                for(int i = nb-1 ; i > beginning ; i--)
                                   box[i] = box[i - 1];


            }


    void changeEvent(SDL_Event *event)
                {
                    event->type = SDL_MOUSEMOTION;
                    event->button.x = WIDTH / 2;
                    event->button.y = HEIGHT /2;

                }


   SDL_bool wait(Uint32 time, SDL_bool *run )
                    {
                        Uint32 previousTime = SDL_GetTicks();
                        SDL_Event event;
                        SDL_bool running = SDL_TRUE;

                        while( (SDL_GetTicks() - previousTime) < time || *run)
                                    {
                                        SDL_PollEvent(&event);

                                            switch(event.type)
                                                    {
                                                        case SDL_QUIT:
                                                            running = SDL_FALSE;
                                                                return running;
                                                                    break;

                                                        case SDL_KEYDOWN:
                                                            switch(event.key.keysym.sym)
                                                                    {
                                                                        case SDLK_f:
                                                                                return SDL_TRUE;
                                                                                    break;
                                                                    }
                                                                    break;
                                                    }

                                    }
                                    *run = SDL_FALSE;
                                        return running;
                    }
