#include "TMonsters.h"

TMonsters::TMonsters(){}

TMonsters::TMonsters(const float &x, const float &y)
	:TMoveSprites(x, y, 5, 5, cocos2d::Sprite::create("Enemy1.png"), 10)
{
	//1==up
	//2==down
	//3==right
	//4==left
	direction = 1;
}


TMonsters::~TMonsters()
{
}

const size_t TMonsters::GetDirect()
{
	return direction;
}

void TMonsters::SetDirect(const size_t &napr)
{
	direction = napr;
}

