#pragma once
#include "TObject.h"
#include"cocos2d.h"
#include<string>
class TMoveSprites :
	public TObject
{
private:
	float Speed;
public:
	TMoveSprites();
	TMoveSprites(const float &x, const float &y, const int &len, const int &hei, cocos2d::Sprite * Pic, const float &sp);
	void MRight();
	void MLeft();
	void MDown();
	void MUp();
	virtual const size_t GetDirect();
	virtual void SetDirect(const size_t &napr);
	virtual const size_t GetIsHunter();
	virtual void ChangeIsHunt();
	virtual float GetTimer();
	virtual void SetTimer(const float &tim);
	const size_t GetType();
	void setSpeed(const float &sp);
	virtual ~TMoveSprites();
};

