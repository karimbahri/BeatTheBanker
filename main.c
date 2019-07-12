
/*

    FILE's NAME : main.c
    ROLE        : contains the main function
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

/*-----------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------*/

            int main( int argc , char *argv[])
                    {

                    /*-------------------------DECLARATIONS-------------------------*/
                        SDL_Surface *screen = NULL;
                        FMOD_SYSTEM *system = NULL;
                        SDL_bool running = SDL_TRUE;
                        FMOD_RESULT result = FMOD_OK;

                    /*-------------------------DECLARATIONS-------------------------*/


                    /*-------------------------INITIALISATION-------------------------*/

                            if(SDL_Init(SDL_INIT_VIDEO) == -1)
                                SDL_ExitWithError(SDL,"Initialization error of SDL");

                        result = FMOD_System_Create(&system);

                            if(result != FMOD_OK)
                                SDL_ExitWithError(FMOD,"Initialization error of FMOD SYSTEM OBJECT");

                        result = FMOD_System_Init(system,32,FMOD_INIT_NORMAL,NULL);

                            if(result != FMOD_OK)
                                SDL_ExitWithError(FMOD,"Initialization error of FMOD");


                        SDL_WM_SetCaption("BEAT THE BANKER",NULL);

                        screen = SDL_SetVideoMode(WIDTH,HEIGHT,32,SDL_HWSURFACE | SDL_DOUBLEBUF);

                            if(screen == NULL)
                                SDL_ExitWithError(SDL,"Initialization error of SDL_Surface");


                    /*-------------------------DECLARATIONS-------------------------*/


                            /*-----------------main-----------------*/



                                    menu(screen,system);


                            /*-----------------main-----------------*/


                    /*-------------------------RELEASE-------------------------*/





                        FMOD_System_Close(system);

                        FMOD_System_Release(system);

                        SDL_FreeSurface(screen);

                        SDL_Quit();

                    /*-------------------------RELEASE-------------------------*/

                        return EXIT_SUCCESS;
                    }
