#include"RealNum.h"

RealNum::RealNum(){
	Num = 0;
}

double RealNum::Modul(){
	return fabs(Num);
}

void RealNum::Print(){
	cout << "RealNum: " << Num << " \nModul of RealNum: " << Modul() << endl;
}
