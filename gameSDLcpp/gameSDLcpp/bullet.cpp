#include"Bullet.h"
Bullet::Bullet()
{
	x_val_ = 0;
	y_val_ = 0;
	rect_.x = 0;
	rect_.y = 0;
	is_move_ = false;
	bullet_type_ = NONE;

}
Bullet::~Bullet()
{
}
void Bullet:: HandleMove(const int& x_border, const int& y_bolder)
{
	rect_.y -= y_val_;
	if(rect_.y > y_bolder)
		is_move_ = false;
}
void Bullet:: HandleMoveEgg()
{
	rect_.y+=10;
	if(rect_.y > SCREEN_HEIGHT)
		is_move_= false;
}

void HandleInputAction(SDL_Event events)
{
}


