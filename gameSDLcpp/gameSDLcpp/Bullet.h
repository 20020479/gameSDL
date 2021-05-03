#ifndef BULLET_H_
#define BULLET_H_

#include"BaseObject.h"
#define WIDTH_LAZER 35
#define HEIGHT_LAZER 5
#define WIDTH_SPHERE 10
#define HEIGHT_SPHERE 10
class Bullet : public BaseObject
{
public:
	  enum bullettype
	{
		NONE = 0,
		LAZER = 1,
		SPHERE = 2,
		EGG = 3
	};
	Bullet();
	~Bullet();
	void HandleInputAction(SDL_Event events);
	void HandleMove(const int& x_border, const int& y_bolder);
	void HandleMoveEgg();
	 int get_type()const
	{
		return bullet_type_;
	}
	void set_type(const int& type)
	{
		bullet_type_ = type;
	}
	bool get_is_move()const
	{
		return is_move_;
	}
	bool set_is_move(bool is_move)
	{
		is_move_ = is_move;
		return is_move_;
	}
	void setwidthheight(const int& wid,const int& hei)
	{
		rect_.w = wid;
		rect_.h = hei;
	}
	void set_y_val(const int& val)
	{
		y_val_ = val;
	}
	void set_x_val(const int& val)
	{
		x_val_ = val;
	}
	int get_x_val()const
	{
		return x_val_;
	}
	int get_y_val()const 
	{
		return y_val_;
	}
		
private:
	int x_val_;
	int y_val_;
	bool is_move_;
	int bullet_type_;

};




#endif BULLET_H_
