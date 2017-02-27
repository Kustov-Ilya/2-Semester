#include"RealNum.h"

class ComplexNum : public RealNum{
protected:
	double NumI;
public:

	ComplexNum()
		:RealNum(0), NumI(0){}

	ComplexNum(double num, double numi)
		:RealNum(num), NumI(numi){}

	virtual double Modul(){
		return sqrt(pow(Num, 2) + pow(NumI, 2));
	}

	virtual void Print(){
		cout << "ComplexNum: " << Num << " + i*";
		if (NumI > 0) {
			cout << NumI;
		}
		else{
			cout << "(" << NumI << ")";
		}
		cout << " \nModul of ComplexNum: " << Modul() << endl;
	}
};
