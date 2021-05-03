#ifndef MENU_H_
#define MENU_H_
#include"COMMON_FUNCTION.h"
#include "BaseObject.h"
static SDL_Surface* g_menu = NULL;
static SDL_Surface* g_end = NULL;
class Menu : public BaseObject
{
public:
int ShowMenu(SDL_Surface* des, TTF_Font* font);
bool CheckFocus(const int& x, const int& y, const SDL_Rect& rect);

private:
};
#endif
