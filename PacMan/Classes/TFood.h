#pragma once
#include "TStayNodes.h"
class TFood :
	public TStayNodes
{
public:
	TFood();
	TFood(const float &x, const float &y);
	const size_t GetType();
	~TFood();
};

