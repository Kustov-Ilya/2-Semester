#pragma once
#include "TStayNodes.h"
class TWall :
	public TStayNodes
{
public:
	TWall();
	TWall(const float &x, const float &y);
	const size_t GetType();
	~TWall();
};

