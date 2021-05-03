#include"PlayerPower.h"


void PlayerPower:: AddPos(const int& xpos)
{
	pos_list_.push_back(xpos);
}
void PlayerPower::Render(SDL_Surface* des)
{
	if(number_ == pos_list_.size())
	{
		for(int i = 0; i < pos_list_.size(); i++)
		{
			rect_.x = pos_list_.at(i);
			Show(des);
		}
	}
}
void PlayerPower:: Init()
{
	LoadImage("img/health.png");
	number_ = 3;
	if(pos_list_.size() > 0)
	pos_list_.clear();
	AddPos(20);
	AddPos(60);
	AddPos(100);
}
void PlayerPower::decrease()
{
	number_--;
	pos_list_.pop_back();
}
