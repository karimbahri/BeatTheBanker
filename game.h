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

    typedef enum
            {
                BOX ,
                PEOPLE

            }SURFACE_TYPE;

    typedef enum
            {
                BOX_CHOICE ,
                SHOW_AMOUNT

            }RUN_SITUATION;


 #define COLOR_UP 0
 #define COLOR_DOWN 1

/*------------------------------------------------------------------------------------*/

void game(SDL_Surface *screen , FMOD_SYSTEM *system , FMOD_CHANNELGROUP *channelgroup );
void boxesPos_Create(SDL_Rect boxesPos[][2] , int nb);
void blitSurfaces(SDL_Surface *screen , SDL_Surface *Surfaces[] , SDL_Rect pos[][2] , int nb , SURFACE_TYPE SURFACE);
boxIndex boxChoice(SDL_Surface *screen , SDL_Surface *boxeOn[] , SDL_Surface *peopleOn[] , SDL_Rect boxesPos[][2] , SDL_Rect peoplePos[][2] , SDL_Event *event , RUN_SITUATION situation , SDL_bool *OPEN_THE_BOX , int *boxRow , boxIndex *index);
int *generateNumber_Boxes( int numb);
void CreateNumberSurface_box(SDL_Surface *boxesNumber_Surface[] , TTF_Font *font , int boxesNumbers[] , const int nb);
void boxesSurface_Create(SDL_Surface *boxesOnSurface[] , SDL_Surface *boxesOffSurface[] , SDL_Surface *numberSurface[] , SDL_Rect *posNumber , int nb);
void peopleSurface_Create(SDL_Surface *peopleOn[] , SDL_Surface *peopleOff[] , int nb);
void boxesOpen_Create(SDL_Surface *boxesOpen[] , int nb);
void boxesOpen_Release(SDL_Surface *boxesOpen[] , int nb);
void boxesOpen_Blit(SDL_Surface *box , SDL_Surface *boxesOpen[] , SDL_Surface *screen , SDL_Rect *boxesOpenPos , SDL_Rect *AmountsPos , SDL_bool *OPEN_THE_BOX , SDL_bool *running , int nb);
void boxes_Create(SDL_Surface *boxes[] , const int boxAmount[] , int nb);
void boxes_Realease(SDL_Surface *boxes[] , int nb);
void peoplePos_Create(SDL_Rect peoplePos[][2] , int nb);
SDL_bool Choose_Your_Box(SDL_Event *event , SDL_Surface *screen , SDL_Surface *boxesOn[] , SDL_Surface *boxesOff[] , SDL_Surface *peopleOn[] , SDL_Surface *background1 , SDL_Surface *background2 , SDL_Surface *table , SDL_Rect BoxesPos[][2] , SDL_Rect peoplePos[][2] , SDL_Rect *posBackground , SDL_Rect *posTable , SDL_Rect *posNumber);
void mixe_Colors(SDL_Color *color);
void createAmountsSurface(SDL_Surface *amounts[][17] , int nbX , int nbY);
void AmountsSurface_Release(SDL_Surface *amounts[][17] , int nbX , int nbY);
void amountsPos_Create(SDL_Rect amountsPos[][2] , int nbX);
void blitAmounts(SDL_Surface *screen , SDL_Surface *amounts[][17] , SDL_Rect amountPos[][2] ,  SDL_Surface *txtSurface , SDL_Rect *textPos , int nb , RUN_SITUATION *situation , SDL_bool *running , SDL_bool *SHOW_MODE);
void ShowAmounts(SDL_Surface *screen , SDL_Surface *amounts[][17] , SDL_Rect amountPos[][2] , int *posX_index , int *posY_index , int *amountX_index , int nb , SDL_bool *AMOUNT_BLIT);
void HideAmounts(SDL_Surface *screen , SDL_Surface *amounts[][17] , SDL_Rect amountPos[][2] , int *posX_index , int *posY_index , int *amountX_index , int nb , SDL_bool *AMOUNT_BLIT , SDL_bool *SHOW_MODE);
void AllBoxesOpen_Blit(SDL_Surface *boxes[] , SDL_Surface *screen , SDL_Rect boxesPos[][2] , int nb);

#endif // __GAM___E
