/*

    FILE's NAME : main.h
    ROLE        : contains the prototype of the game function
    AUTHOR      : KARM BAHRI | karim-bahri-18@outlook.fr
    DATE        : 11/07/2019






*/

#ifndef __GAM___E

#define __GAM___E

    typedef struct
        {
            int X , Y;

        }boxIndex;

/*------------------------------------------------------------------------------------*/

void game(SDL_Surface *screen , FMOD_SYSTEM *system , FMOD_CHANNELGROUP *channelgroup );
void boxesPos_Create(SDL_Rect boxesPos[][2] , int nb);
void blitBoxe(SDL_Surface *screen , SDL_Surface *boxe , SDL_Rect pos[][2] , int nb);
boxIndex boxChoice(SDL_Surface *screen , SDL_Surface *boxeOn , SDL_Rect boxesPos[][2] , SDL_Event *event);
SDL_Surface **resizeSurface_boxe(SDL_Surface *boxe[] , int width , int height , const int nb);



#endif // __GAM___E
