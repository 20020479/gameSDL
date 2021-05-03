#include"ChickenObject.h"


Chicken::Chicken()
{
	rect_.x = SCREEN_WIDTH*0.5;
	rect_.y = SCREEN_HEIGHT;
	rect_.w = CHICKEN_WIDTH;
	rect_.h = CHICKEN_HEIGHT;
	x_val_ = 0;
	y_val_ = 0;
}
Chicken::~Chicken()
{
}
void Chicken::Initegg(Bullet* p_egg)
{
	if(p_egg )
	{
		bool ret = p_egg->LoadImage("img/egg.png");
		if(ret)
		{
			p_egg->set_is_move(true);
			p_egg->setwidthheight(EGG_WIDTH, EGG_HEIGHT);
			p_egg->set_type( Bullet::EGG);
			p_egg->SetRect(rect_.x,rect_.y+rect_.h*0.5);
			p_bullet_list.push_back(p_egg);
		}
	}

}
void Chicken:: Makeegg(SDL_Surface* des, const int& x_limit, const int& y_limit)
{
	
	 for(int i = 0;i < p_bullet_list.size(); i++)
	{
		Bullet* p_egg = p_bullet_list.at(i);
		if(p_egg)
		
		{
			if(p_egg->get_is_move())
			
			{
				p_egg->Show(des);
				p_egg->HandleMoveEgg();
			}
			else
			{
				p_egg->set_is_move(true);
				p_egg->SetRect(rect_.x,rect_.y);
			}


		}

	}

}

void Chicken::HandleMove(const int& x_border, const int& y_bolder)
{
	rect_.x -= x_val_;
	if(rect_.x < 0)
	{
		rect_.x = SCREEN_WIDTH;
		int rand_y = rand()%400;
		if(rand_y > SCREEN_HEIGHT*0.5)
			{
				rand_y = SCREEN_HEIGHT*0.5;
			}
		rect_.y = rand_y;
	}

}


// reset chicken's location:
void Chicken::Reset(const int& xbolder)
{
	rect_.x = xbolder;
	rect_.x = SCREEN_WIDTH;
	int rand_y=rand()%400;
	if(rand_y > SCREEN_HEIGHT*0.5)
		{
			rand_y = SCREEN_HEIGHT*0.5;
		}
	rect_.y = rand_y;
	for(int i = 0; i < p_bullet_list.size(); i++)
		{
			Bullet* p_egg = p_bullet_list.at(i);
			if(p_egg)
			{
				Resetegg(p_egg);
			}
		}
	
}
void Chicken::Resetegg(Bullet* p_egg)
{
	p_egg->SetRect(rect_.x,rect_.y+rect_.h*0.5);
}

// delete egg:
void Chicken::removeegg(const int& idx)
{
	for(int i = 0; i < p_bullet_list.size(); i++)
	{ 
		if(idx < p_bullet_list.size())
		{
			Bullet* p_bullet = p_bullet_list.at(idx);
			p_bullet_list.erase(p_bullet_list.begin() + idx);
			if(p_bullet != NULL)
			{
				delete p_bullet;
				p_bullet = NULL;
			}
		}
	}
}