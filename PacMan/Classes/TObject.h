#pragma once
#include<iostream>
#include"cocos2d.h"
USING_NS_CC;

class TObject
{
private:
	cocos2d::Sprite* Pict;
	std::pair<float, float> TPointXY;
	std::pair<int, int> TSize;
public:
	TObject();

	TObject(const float &x, const float &y, const int &len, const int &hei, cocos2d::Sprite * Pic);

	const std::pair<int, int> GetCoord();

	const std::pair<int, int> GetSize();

	virtual void MRight()=0;
	virtual void MLeft()=0;
	virtual void MDown()=0;
	virtual void MUp()=0;
	virtual const size_t GetDirect()=0;
	virtual void SetDirect(const size_t &napr) =0;
	virtual const size_t GetIsHunter()=0;
	virtual void ChangeIsHunt()=0;
	virtual const size_t GetType()=0;
	cocos2d::Sprite* GetPict();

	void SetXPos(const float &x);

	void SetYPos(const float &y);

	virtual ~TObject();
};

