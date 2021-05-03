#ifndef EXPLOSION_H_
#define EXPLOSION_H_
#include "COMMON_FUNCTION.h"
#include "BaseObject.h"
#define WIDTH_EXPLOSION 165
#define HEIGHT_EXPLOSION 165

class ExplosionObject : public BaseObject
{
public:
	ExplosionObject();
	~ExplosionObject();
	void set_clip();
	void set_frame(const int&  fr)
	{
		frame_ = fr;
	}

	void ShowExp(SDL_Surface* des);


private:
	int frame_;
	SDL_Rect clip_[4];
};

#endif EXPLOSION_H_
