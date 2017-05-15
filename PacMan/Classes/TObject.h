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

	virtual void MRight();
	virtual void MLeft();
	virtual void MDown();
	virtual void MUp();
	virtual float GetTimer();
	virtual void SetTimer(const float &tim);
	virtual const size_t GetDirect();
	virtual void SetDirect(const size_t &napr);
	virtual const size_t GetIsHunter();
	virtual void ChangeIsHunt();
	virtual void setSpeed(const float &sp);
	virtual const size_t GetType();
	cocos2d::Sprite* GetPict();
	void SetPict(std::string &rhs);

	void SetXPos(const float &x);

	void SetYPos(const float &y);

	virtual ~TObject();
};

