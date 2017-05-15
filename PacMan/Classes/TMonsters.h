#pragma once
#include "C:\Users\lenovo\Documents\cocos2d_Projects\MyGame\Classes\TMoveSprites.h"
class TMonsters :
	public TMoveSprites
{
private:
	size_t direction;
public:
	TMonsters();
	TMonsters(const float &x, const float &y);
	~TMonsters();
	const size_t GetDirect();
	void SetDirect(const size_t &napr);
	const size_t GetIsHunter();
	void ChangeIsHunt();
};

