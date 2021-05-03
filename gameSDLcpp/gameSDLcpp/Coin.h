#ifndef COIN_H_
#define COIN_H_
#include"COMMON_FUNCTION.h"
#include"BaseObject.h"
class CoinObject: public BaseObject
{
public:
	CoinObject();
	~CoinObject();
	void HandleMove(const int& x_border, const int& y_bolder);
	void Resetgift(const int& ybolder);
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
private:
	int x_val_;
	int y_val_;

};
#endif
