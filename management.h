/*

    FILE's NAME : main.c
    ROLE        : contains prototypes of management.c
    AUTHOR      : KARM BAHRI | karim-bahri-18@outlook.fr
    DATE        : 11/07/2019






*/

#ifndef MANA_GEM_ENT

#define MANA_GEM_ENT

#include "consts.h"


    typedef enum
        {
           CLICK ,
           MOTION

        }EVENT_TYPE;

    /*-------------------------------------------------------------------*/

    void SDL_ExitWithError(ERROR_TYPE error , char *txt);
    SDL_bool collision_MouseTest(EVENT_TYPE mouse,int width , int height , SDL_Rect pos , SDL_Event event);
    void breakProcess(void);
    SDL_bool check_focus(SDL_Event *event);
    SDL_Rect set_position(SDL_Rect *position , int x , int y);

    /*-------------------------------------------------------------------*/

#endif // MANA_GEM_ENT
