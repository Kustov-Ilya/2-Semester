#include "TStayNodes.h"



TStayNodes::TStayNodes()
{
}

TStayNodes::TStayNodes(const float x, const float y, const int len, const int hei, cocos2d::Sprite * Pic)
	:TObject(x, y, len, hei, Pic)
{
}


TStayNodes::~TStayNodes()
{
}

void TStayNodes::MRight()
{
}

void TStayNodes::MLeft()
{
}

void TStayNodes::MDown()
{
}

void TStayNodes::MUp()
{
}

const size_t TStayNodes::GetDirect()
{
	return size_t();
}

void TStayNodes::SetDirect(const size_t &napr)
{
}

const size_t TStayNodes::GetIsHunter()
{
	return size_t();
}

void TStayNodes::ChangeIsHunt()
{
}
