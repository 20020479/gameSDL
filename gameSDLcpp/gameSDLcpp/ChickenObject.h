#ifndef CHICKEN_H_
#define CHICKEN_H_
#define CHICKEN_WIDTH 72
#define CHICKEN_HEIGHT 62
#define EGG_WIDTH 22
#define EGG_HEIGHT 21
#include"BaseObject.h"
#include"COMMON_FUNCTION.h"
#include"Bullet.h"
#include <vector>


class Chicken: public BaseObject
{
public:
	Chicken();
	~Chicken();
	void HandleMove(const int& x_border, const int& y_bolder);
	void set_x_val(const int& val)
	{
		x_val_ = val;
	}
	void set_y_val(const int& val)
	{
		y_val_ = val;
	}
	 int get_x_val() const
    {
        return x_val_;
    }
    int get_y_val() const
    {
        return y_val_;
    }
	void Set_bullet_list(std::vector<Bullet*> bullet_list)
	{
		p_bullet_list = bullet_list;
	}
	std::vector<Bullet*>Getbulletlist() const
	{
		return p_bullet_list;
	}
	void Chicken::Initegg(Bullet* p_egg);
	void Makeegg(SDL_Surface* des, const int& x_limit, const int& y_limit);
	void Reset(const int& xbolder);
	void Resetegg(Bullet* p_egg);
	void removeegg(const int& idx);

private:
	int x_val_;
	int y_val_;
	std:: vector<Bullet*>  p_bullet_list;
};




#endif CHICKEN_H_