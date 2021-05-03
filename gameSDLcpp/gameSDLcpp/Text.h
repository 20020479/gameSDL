#ifndef TEXT_H_
#define TEXT_H_
#include "BaseObject.h"
#include<string.h>
#include<SDL_ttf.h>

class TextObject: public BaseObject
{
public:
	TextObject();
	~TextObject();
	void SetText(const std::string & text)
	{
	text_val = text;
	}
	void SetColor();
	void Changecolor();
	void CreateGameText(TTF_Font* font, SDL_Surface* des);
private:
	std:: string text_val;
	SDL_Color text_color;
	
};

#endif
