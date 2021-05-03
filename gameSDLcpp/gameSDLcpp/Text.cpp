#include"Text.h"
 

TextObject::TextObject()
{
}
TextObject::~TextObject()
{
}
void TextObject::SetColor()
{
    SDL_Color color = {255, 255, 255};
	text_color = color;
}
void TextObject:: Changecolor()
{
	SDL_Color color2 = {0, 0, 0};
	text_color = color2;
}
void TextObject:: CreateGameText(TTF_Font* font, SDL_Surface* des)
	{
		p_object_ = TTF_RenderText_Solid(font, text_val.c_str(), text_color);
		Show(des);
	}
