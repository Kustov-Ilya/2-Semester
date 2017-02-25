#include"ComplexNum.h"

ComplexNum::ComplexNum(){
	Num = 0;
	NumI = 0;
}

double ComplexNum::Modul(){
	return sqrt(pow(Num, 2) + pow(NumI, 2));
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
