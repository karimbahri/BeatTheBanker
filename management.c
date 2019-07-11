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
#include "consts.h"
#include "management.h"


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



        }


    /*---------------------------------------------------------------------------------------------------------------*/


    SDL_bool collision_MouseTest(EVENT_TYPE mouse,int width , int height , SDL_Rect pos , SDL_Event event)
                {
                    if(mouse == CLICK)
                                {
                                    if( (event.button.x > pos.x && event.button.x < (pos.x + width) ) && (event.button.y > pos.y && event.button.y < (pos.y + height) ))
                                            return SDL_TRUE;
                                    else
                                            return SDL_FALSE;
                                }
                    if(mouse == MOTION)
                                {
                                    if( (event.motion.x > pos.x && event.motion.x < (pos.x + width) ) && (event.motion.y > pos.y && event.motion.y < (pos.y + height) ))
                                            return SDL_TRUE;

                                    else
                                            return SDL_FALSE;
                                }
                    else
                                      return SDL_FALSE;

                }


    /*---------------------------------------------------------------------------------------------------------------*/

