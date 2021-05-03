

#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include<Windows.h>
#include<SDL.h>
#include<SDL_image.h>
#include<string>
#include<SDL_mixer.h>
#include<SDL_ttf.h>

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;
const int NUM_CHICKEN = 3;
const int START_X_POS_PLANE = SCREEN_WIDTH/2;
const int START_Y_POS_PLANE = SCREEN_HEIGHT-100 ;
const int MENU_NUM_ITEM = 2;
const int COIN_WIDTH = 41;
const int COIN_HEIGHT =37;
static SDL_Surface* g_screen = NULL;
static SDL_Surface* g_bkground = NULL;
static SDL_Surface* g_object;   
static SDL_Event g_even;
static Mix_Chunk* g_sound_bullet[2];  // bullet's sound
static Mix_Chunk* g_sound_exp[2];     //exp's sound
static Mix_Chunk* g_soundtrack; //sound track
static Mix_Chunk* g_gift;
static Mix_Chunk* g_keyboard;
static Mix_Chunk* g_key2;


  
namespace SDL_CF
{

SDL_Surface* LoadImage(std::string file_path);
void ApplySurfaceClip(SDL_Surface* src, SDL_Surface* des, SDL_Rect* clip, int x, int y);
SDL_Rect ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);
void CleanUp();
bool checkcollision(const SDL_Rect& object1,const SDL_Rect& object2);

}
#endif COMMON_FUNCTION_H_