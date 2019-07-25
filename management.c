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

                                    if(event->type == SDL_MOUSEBUTTONDOWN)
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
