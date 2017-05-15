#include "TPacMan.h"



TPacMan::TPacMan()
{
}

TPacMan::TPacMan(const float &x, const float &y)
	:TMoveSprites(x, y, 5, 5, cocos2d::Sprite::create("PacMan.png"), 10)
{
	timer = 0;
	ishunter = 0;
}

float TPacMan::GetTimer()
{
	return timer;
}

void TPacMan::SetTimer(const float & tim)
{
	timer = tim;
}




const size_t TPacMan::GetIsHunter()
{
	return ishunter;
}

void TPacMan::ChangeIsHunt()
{
	if (ishunter == 1) ishunter = 0;
	else ishunter = 1;
}

TPacMan::~TPacMan(){}

