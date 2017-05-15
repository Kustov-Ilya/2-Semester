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
	virtual const size_t GetDirect()=0;
	virtual void SetDirect(const size_t &napr) =0;
	virtual const size_t GetIsHunter() = 0;
	virtual void ChangeIsHunt() = 0;
	const size_t GetType();
	void setSpeed(const float &sp);
	virtual ~TMoveSprites();
};

