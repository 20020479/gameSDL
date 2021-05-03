#include"Menu.h"
#include"Text.h"
bool Menu::CheckFocus(const int& x, const int& y, const SDL_Rect& rect)
 {
	 if(x >= rect.x && x < rect.x + rect.w && y >= rect.y && y < rect.y + rect.h)
		 {
			 return true;
		 }
	 return false;

 }

int Menu:: ShowMenu(SDL_Surface* des, TTF_Font* font)
 {
	 g_keyboard = Mix_LoadWAV("sound/keyboard.wav");
	 g_key2 = Mix_LoadWAV("sound/key2.wav");
	 g_menu = SDL_CF:: LoadImage("img/menu1.png");
	 if(g_menu == NULL)
		 {
			 return 1;
		 }
	 
	 

	 TextObject text_menu[MENU_NUM_ITEM];
	 text_menu[0].SetText("PLAY GAME");
	 text_menu[0].Changecolor();
	 text_menu[0].SetRect(200, 400);
	 text_menu[1].SetText("EXIT");
	 text_menu[1].Changecolor();
	 text_menu[1].SetRect( 200,  500);

	 bool selected[MENU_NUM_ITEM] = {0, 0};
	 int xm = 0;
	 int ym = 0;
	 SDL_Event m_event;
	 while(true)
	 {
		 SDL_CF::ApplySurface(g_menu, des, 0, 0);
		 for(int i = 0; i < MENU_NUM_ITEM; ++i)
		 {
			 text_menu[i].CreateGameText(font, des);
		 }
		 while(SDL_PollEvent(&m_event))
		 {
			 switch (m_event.type)
			 {
			 case SDL_QUIT:
				 return 1;
			 case SDL_MOUSEMOTION:
			 {
				 xm = m_event.motion.x;
				 ym = m_event.motion.y;
				 for(int i = 0; i < MENU_NUM_ITEM; i++)
				 {
					 if(CheckFocus(xm, ym, text_menu[i].GetRect()) )
					 {
						 if(selected[i] == false)
						 {
							 selected[i] = 1;
							 text_menu[i].SetColor();
							 Mix_PlayChannel(-1, g_keyboard, 0);

							  
						 }

					 }
					 else
					 {
						  if(selected[i] == true)
						 {
							 selected[i] = 0;
							 text_menu[i].Changecolor();
						 }
					 }
				 }
			 }
			 break;
			 case SDL_MOUSEBUTTONDOWN:
				 {
					 xm = m_event.button.x;
					 ym = m_event.button.y;
					 for(int i = 0; i < MENU_NUM_ITEM; i++)
					 {
						 if(CheckFocus(xm, ym, text_menu[i].GetRect()))
							{
								return i;
							}
						  Mix_PlayChannel(-1, g_key2, 0);
					 }
				 }
				 break;
			 case SDL_KEYDOWN:
				 
					 if(m_event.key.keysym.sym == SDLK_ESCAPE)
						{
							return 1;
							
						}
				 
			 default:
				 break;
			 }
		 }
		  SDL_Flip(des);
	 }
	
	 return 1;

 }

	
