#pragma once
#include "TObject.h"
class TStayNodes :
	public TObject
{
public:
	TStayNodes();
	TStayNodes(const float x, const float y, const int len, const int hei, cocos2d::Sprite * Pic);
	virtual const size_t GetType()=0;
	virtual ~TStayNodes();
	virtual void MRight();
	virtual void MLeft();
	virtual void MDown();
	virtual void MUp();
	virtual const size_t GetDirect();
	virtual void SetDirect(const size_t &napr);
	virtual const size_t GetIsHunter();
	virtual void ChangeIsHunt();
};

