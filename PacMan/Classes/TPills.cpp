#include "TPills.h"



TPills::TPills()
{
}

TPills::TPills(const float &x, const float &y, const int &len, const int &hei, cocos2d::Sprite * Pic, const size_t &typ)
	:TStayNodes(x, y, 5, 5, Pic)
{
	type = typ;
}

const size_t TPills::GetType()
{
	return type;
}



TPills::~TPills()
{
}
