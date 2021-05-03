#ifndef PLAYER_POWER_H_
#define PLAYER_POWER_H_
#include"BaseObject.h"
#include<vector>



class PlayerPower : public BaseObject
{
public:
	void SetNum(const int& num)
	{
		number_ = num;
	}
	void AddPos(const int& xpos);
	void Render(SDL_Surface* des);
	void Init();
	void decrease();
	
private:
	int number_;  // so mang
	std:: vector<int>pos_list_;
};



#endif 