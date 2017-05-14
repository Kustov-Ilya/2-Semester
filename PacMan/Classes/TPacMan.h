#pragma once
#include "TMoveSprites.h"
class TPacMan :
	public TMoveSprites
{
private:
	size_t ishunter;
public:
	TPacMan();
	TPacMan(const float &x, const float &y);
	const size_t GetIsHunter();
	void ChangeIsHunt();
	const size_t GetDirect();
	void SetDirect(const size_t &napr);
	~TPacMan();
};

