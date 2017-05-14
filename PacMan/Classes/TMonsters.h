#pragma once
#include "TMoveSprites.h"
class TMonsters :
	public TMoveSprites
{
private:
	size_t direction;
public:
	TMonsters();
	TMonsters(const float &x, const float &y);
	~TMonsters();
	const size_t GetDirect();
	void SetDirect(const size_t &napr);
	const size_t GetIsHunter();
	void ChangeIsHunt();
};

