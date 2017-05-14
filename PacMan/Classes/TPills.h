#pragma once
#include "TStayNodes.h"
class TPills :
	public TStayNodes
{
private:
	size_t type;
public:
	TPills();
	TPills(const float &x, const float &y, const int &len, const int &hei, cocos2d::Sprite * Pic, const size_t &typ);
	virtual const size_t GetType();
	virtual ~TPills();
};

