#include"RealNum.h"

class ComplexNum : protected RealNum{
protected:
	double NumI;
public:
	~ComplexNum() = default;

	ComplexNum();

	ComplexNum(double num, double numi)
		:RealNum(num), NumI(numi){};

	virtual double Modul();

	virtual void Print();
};
