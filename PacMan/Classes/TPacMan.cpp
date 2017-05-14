#include "TPacMan.h"



TPacMan::TPacMan()
{
}

TPacMan::TPacMan(const float &x, const float &y)
	:TMoveSprites(x, y, 5, 5, cocos2d::Sprite::create("PacMan.png"), 10)
{
	ishunter = 0;
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

const size_t TPacMan::GetDirect()
{
	return size_t();
}




void TPacMan::SetDirect(const size_t &napr){}

TPacMan::~TPacMan(){}

