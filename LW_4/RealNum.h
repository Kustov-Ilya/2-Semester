#include<iostream>
#include<string>
using namespace std;

#ifndef MY_SYMBOL_H
#define MY_SYMBOL_H

class RealNum{
protected:
	double Num;
public:

	RealNum()
		:Num(0){}

	RealNum(double num)
		:Num(num){}

	virtual double Modul(){
		return fabs(Num);
	}

	virtual void Print(){
		cout << "RealNum: " << Num << " \nModul of RealNum: " << Modul() << endl;
	}
};
#endif
