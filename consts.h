/*

    FILE's NAME : main.c
    ROLE        : contains consts , macros and enumerations
    AUTHOR      : KARM BAHRI | karim-bahri-18@outlook.fr
    DATE        : 11/07/2019






*/

#ifndef _CONS_T

#define _CONS_T

/*-----------------------------------------*/

#define HEIGHT 768
#define WIDTH 1024

/*-----------------------------------------*/

#define BOX_HEIGHT 31
#define BOX_WIDTH 55

#define LENGTH 84
#define POS_START 22
#define DISTANCE_BOX_BOX 29

#define BOX_Y_1 150
#define BOX_Y_2 479

/*-----------------------------------------*/

    typedef enum
        {
          SDL ,
          TTF ,
          IMG ,
          FMOD

        }ERROR_TYPE;

#endif // _CONS_T
