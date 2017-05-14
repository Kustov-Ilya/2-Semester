#include "TPill1.h"



TPill1::TPill1()
{
}

TPill1::TPill1(const float &x, const float &y)
	:TPills(x, y, 5, 5, cocos2d::Sprite::create("placebo.png"), 1)
{
}



TPill1::~TPill1()
{
}
