#include "TWall.h"



TWall::TWall()
{
}

TWall::TWall(const float &x, const float &y)
	:TStayNodes(x, y, 5, 5, cocos2d::Sprite::create("Wall.png"))
{
}

const size_t TWall::GetType()
{
	return size_t();
}




TWall::~TWall()
{
}
