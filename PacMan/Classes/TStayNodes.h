#pragma once
#include "TObject.h"
class TStayNodes :
	public TObject
{
public:
	TStayNodes();
	TStayNodes(const float x, const float y, const int len, const int hei, cocos2d::Sprite * Pic);
	virtual const size_t GetType();
	virtual ~TStayNodes();
	void MRight();
	void MLeft();
	void MDown();
	void MUp();
	const size_t GetDirect();
	void SetDirect(const size_t &napr);
	const size_t GetIsHunter();
	void ChangeIsHunt();
};

