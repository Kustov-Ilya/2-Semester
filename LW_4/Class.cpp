#include"Class.h"

RealNum::RealNum(){
	Num = 0;
}

double RealNum::Modul(){
	return fabs(Num);
}

ComplexNum::ComplexNum(){
	Num = 0;
	NumI = 0;
}

double ComplexNum::Modul(){
	return sqrt(pow(Num, 2) + pow(NumI, 2));
}

void RealNum::Print(){
	cout << "RealNum: "<< Num << " \nModul of RealNum: " << Modul() << endl;
}

void ComplexNum::Print(){
	cout << "ComplexNum: " << Num << " + i*";
	if (NumI > 0) {
		cout << NumI;
	}
	else{
		cout << "(" << NumI << ")";
	}
	cout << " \nModul of ComplexNum: " << Modul() << endl;
}
