#include "TMoveSprites.h"



TMoveSprites::TMoveSprites()
	:TObject()
{
}

TMoveSprites::TMoveSprites(const float &x, const float &y, const int &len, const int &hei, cocos2d::Sprite * Pic, const float &sp)
	:TObject(x, y, len, hei, Pic)
{
	Speed = sp;
}

void TMoveSprites::MRight()
{
	auto To = MoveBy::create(0.2, Vec2(Speed, 0));
	this->GetPict()->runAction(To);
	SetXPos(GetCoord().first + Speed);
}

void TMoveSprites::MLeft()
{
	auto To = MoveBy::create(0.2, Vec2(-Speed, 0));
	this->GetPict()->runAction(To);
	SetXPos(GetCoord().first - Speed);
}

void TMoveSprites::MDown()
{
	auto To = MoveBy::create(0.2, Vec2(0, -Speed));
	this->GetPict()->runAction(To);
	SetYPos(GetCoord().second - Speed);
}

void TMoveSprites::MUp()
{
	auto To = MoveBy::create(0.2, Vec2(0, Speed));
	this->GetPict()->runAction(To);
	SetYPos(GetCoord().second + Speed);
}

const size_t TMoveSprites::GetType()
{
	return size_t();
}

void TMoveSprites::setSpeed(const float &sp)
{
	Speed = sp;
}



TMoveSprites::~TMoveSprites()
{
}

