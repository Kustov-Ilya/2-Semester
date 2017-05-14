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
