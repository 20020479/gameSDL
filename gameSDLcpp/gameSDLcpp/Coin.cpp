#include"Coin.h"
   

CoinObject::CoinObject()
{
	rect_.y = 0;
	rect_.x = 300;
	rect_.h = COIN_HEIGHT;
	rect_.w = COIN_WIDTH;

}
CoinObject:: ~CoinObject()
{
}
void CoinObject:: HandleMove(const int& x_border, const int& y_bolder)
{
	rect_.y += y_val_;
	if(rect_.y > SCREEN_HEIGHT)
	{
		rect_.y = 0;
		int rand_x = rand()%400;
		if(rand_x > SCREEN_WIDTH*0.5)
			{
				rand_x = SCREEN_WIDTH*0.5;
			}
		rect_.x = rand_x;
	}
}
void CoinObject::Resetgift(const int& ybolder)
{
	rect_.y = ybolder;
	rect_.y = 0;
	int rand_x=rand()%400;
	if(rand_x > SCREEN_WIDTH*0.5)
		{
			rand_x = SCREEN_WIDTH*0.5;
		}
	rect_.x = rand_x;
}