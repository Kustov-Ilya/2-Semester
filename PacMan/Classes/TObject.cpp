#include "TObject.h"

TObject::TObject(){}

TObject::TObject(const float &x, const float &y, const int &len, const int &hei, cocos2d::Sprite * Pic)
{
	TPointXY.first = x;
	TPointXY.second = y;
	TSize.first = len;
	TSize.second = hei;
	Pict = Pic;
	Pict->setPosition(Vec2(x, y));
}

const std::pair<int, int> TObject::GetCoord()
{
	return TPointXY;
}

const std::pair<int, int> TObject::GetSize()
{
	return TSize;
}

void TObject::MRight()
{
}

void TObject::MLeft()
{
}

void TObject::MDown()
{
}

void TObject::MUp()
{
}

float TObject::GetTimer()
{
	return 0.0f;
}

void TObject::Add30Sec()
{
}

const size_t TObject::GetDirect()
{
	return size_t();
}

void TObject::SetDirect(const size_t & napr)
{
}

const size_t TObject::GetIsHunter()
{
	return size_t();
}

void TObject::ChangeIsHunt()
{
}

const size_t TObject::GetType()
{
	return size_t();
}

cocos2d::Sprite * TObject::GetPict()
{
	return Pict;
}

void TObject::SetXPos(const float &x)
{
	TPointXY.first = x;
}

void TObject::SetYPos(const float &y)
{
	TPointXY.second = y;
}

TObject::~TObject(){}
