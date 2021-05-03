#include"Explosion.h"

ExplosionObject:: ExplosionObject()
{
}
ExplosionObject:: ~ExplosionObject()
{
}
void ExplosionObject:: set_clip()
{
	clip_[0].x = 0;
	clip_[0].y = 0;
	clip_[0].w = WIDTH_EXPLOSION;
	clip_[0].h = HEIGHT_EXPLOSION;
	clip_[1].x = WIDTH_EXPLOSION;
	clip_[1].y = 0;
	clip_[1].w = WIDTH_EXPLOSION;
	clip_[1].h = HEIGHT_EXPLOSION;
	clip_[2].x = WIDTH_EXPLOSION*2;
	clip_[2].y = 0;
	clip_[2].w = WIDTH_EXPLOSION;
	clip_[2].h = HEIGHT_EXPLOSION;
	clip_[3].x = WIDTH_EXPLOSION*3;
	clip_[3].y = 0;
	clip_[3].w = WIDTH_EXPLOSION;
	clip_[3].h = HEIGHT_EXPLOSION;


}
void ExplosionObject:: ShowExp(SDL_Surface* des)
{
	if(frame_ >= 4)
	{
		frame_ = 0;
	}
	SDL_CF::ApplySurfaceClip(this->p_object_, des, &clip_[frame_], rect_.x, rect_.y);
}
