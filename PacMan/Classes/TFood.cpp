#include "TFood.h"



TFood::TFood()
{
}

TFood::TFood(const float &x, const float &y)
	:TStayNodes(x, y, 5, 5, cocos2d::Sprite::create("pill.png"))
{
}

const size_t TFood::GetType()
{
	return size_t(99);
}


TFood::~TFood()
{
}


