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
void blitSurfaces(SDL_Surface *screen , SDL_Surface *Surfaces[] , SDL_Rect pos[][2] , int nb);
boxIndex boxChoice(SDL_Surface *screen , SDL_Surface *boxeOn[] , SDL_Rect boxesPos[][2] , SDL_Event *event);
SDL_Surface **resizeSurface_boxe(SDL_Surface *boxe[] , int width , int height , const int nb);
int *generateNumber_Boxes( int numb);
void CreateNumberSurface_box(SDL_Surface *boxesNumber_Surface[] , TTF_Font *font , SDL_Color color , int boxesNumbers[] , const int nb);
void boxesSurface_Create(SDL_Surface *boxesOnSurface[] , SDL_Surface *boxesOffSurface[] , SDL_Surface *numberSurface[] , SDL_Rect *posNumber , int nb);
void peopleSurface_Create(SDL_Surface *peopleOn[] , SDL_Surface *peopleOff[] , int nb);
void peoplePos_Create(SDL_Rect peoplePos[][2] , int nb);

#endif // __GAM___E
