#include<iostream>
#include<string>

using namespace std;

#ifndef MY_SYMBOL_H
#define MY_SYMBOL_H

class RealNum{
protected:
	double Num;
public:
	virtual ~RealNum() = default;

	RealNum();

	RealNum(double num)
		:Num(num){}

	virtual double Modul();

	virtual void Print();
};
#endif
