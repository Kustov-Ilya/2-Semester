#pragma once
#include "TMoveSprites.h"
class TPacMan :
	public TMoveSprites
{
private:
	size_t ishunter;
	float timer;
public:
	TPacMan();
	TPacMan(const float &x, const float &y);
	float GetTimer();
	void SetTimer(const float &tim);
	const size_t GetIsHunter();
	void ChangeIsHunt();
	~TPacMan();
};

