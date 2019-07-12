
/*

    FILE's NAME : main.c
    ROLE        : contains the menu functions
    AUTHOR      : KARM BAHRI | karim-bahri-18@outlook.fr
    DATE        : 12/07/2019






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


    SDL_bool menu(SDL_Surface *screen , FMOD_SYSTEM *system)
        {

             /*-------------------------DECLARATIONS-------------------------*/

                SDL_Surface *menuBackground = NULL , *buttonOn = NULL , *buttonOff = NULL , *startOn = NULL , *startOff = NULL , *optOn = NULL , *optOff = NULL , *exOn = NULL , *exOff = NULL;
                FMOD_SOUND *openingSound = NULL;
                SDL_Event event;
                SDL_Rect posMenuBackground , posStart , posOpt , posExi;
                SDL_bool running = SDL_TRUE;
                FMOD_RESULT result = FMOD_OK;


             /*-------------------------DECLARATIONS-------------------------*/


             /*-------------------------INITIALISATION-------------------------*/

                    menuBackground = IMG_Load("sprites/menu background.png");

                        if(menuBackground == NULL)
                            SDL_ExitWithError(IMG,"Initialization error of SDL SURFACE");

                    result = FMOD_System_CreateSound(system,"SOUNDS/menuSound.mp3",FMOD_CREATESTREAM |FMOD_2D,0,&openingSound);

                        if(result != FMOD_OK)
                            SDL_ExitWithError(FMOD,"Initialization error of FMOD SOUND");

                    startOn = IMG_Load("sprites/start on.png");

                        if(startOn == NULL)
                            SDL_ExitWithError(IMG,"Initialization error of SDL SURFACE");

                    startOff = IMG_Load("sprites/start off.png");

                        if(startOff == NULL)
                            SDL_ExitWithError(IMG,"Initialization error of SDL SURFACE");

                    optOn = IMG_Load("sprites/options on.png");

                        if(optOn == NULL)
                            SDL_ExitWithError(IMG,"Initialization error of SDL SURFACE");

                    optOff = IMG_Load("sprites/options off.png");

                        if(optOff == NULL)
                            SDL_ExitWithError(IMG,"Initialization error of SDL SURFACE");

                    exOn = IMG_Load("sprites/quit on.png");

                        if(exOn == NULL)
                            SDL_ExitWithError(IMG,"Initialization error of SDL SURFACE");

                    exOff = IMG_Load("sprites/quit off.png");

                        if(exOff == NULL)
                            SDL_ExitWithError(IMG,"Initialization error of SDL SURFACE");

                    buttonOn = IMG_Load("sprites/button on.png");

                        if(buttonOn == NULL)
                            SDL_ExitWithError(IMG,"Initialization error of SDL SURFACE");

                    buttonOff = IMG_Load("sprites/button off.png");

                        if(buttonOff == NULL)
                            SDL_ExitWithError(IMG,"Initialization error of SDL SURFACE");


                        set_position(&posMenuBackground,0,0);
                        set_position(&posStart,658,89);
                        set_position(&posOpt,658,235);
                        set_position(&posExi,658,381);

             /*-------------------------INITIALISATION-------------------------*/

                FMOD_System_PlaySound(system,openingSound,0,0,NULL);

                    while(running)
                            {

                               SDL_PollEvent(&event);
                                switch(event.type)
                                    {
                                        case SDL_QUIT:
                                            running = SDL_FALSE;
                                                break;

                                    }

                                    /*--------------------------------------------*/

                                        if(!check_focus(&event))
                                            breakProcess();

                                    /*--------------------------------------------*/

                                SDL_BlitSurface(menuBackground,NULL,screen,&posMenuBackground);
                                SDL_BlitSurface(buttonOff,NULL,screen,&posStart);
                                SDL_BlitSurface(startOff,NULL,screen,&posStart);
                                SDL_BlitSurface(buttonOff,NULL,screen,&posOpt);
                                SDL_BlitSurface(optOff,NULL,screen,&posOpt);
                                SDL_BlitSurface(buttonOff,NULL,screen,&posExi);
                                SDL_BlitSurface(exOff,NULL,screen,&posExi);
                                SDL_Flip(screen);
                            }

        }
