#include "TStayNodes.h"



TStayNodes::TStayNodes()
{
}

TStayNodes::TStayNodes(const float x, const float y, const int len, const int hei, cocos2d::Sprite * Pic)
	:TObject(x, y, len, hei, Pic)
{
}

const size_t TStayNodes::GetType()
{
	return size_t();
}


TStayNodes::~TStayNodes()
{
}



