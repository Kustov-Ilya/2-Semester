#include<iostream>
#include<string>

using namespace std;

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

class ComplexNum : protected RealNum{
protected:
	double NumI;
public:
	~ComplexNum() = default;

	ComplexNum();

	ComplexNum(double num, double numi)
		:RealNum(num), NumI(numi){};

	double Modul();

	void Print();
};
