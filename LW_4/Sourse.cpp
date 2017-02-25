#include"RealNum.h"
#include"ComplexNum.h"

int main(){
	RealNum Num(-6.345);
	RealNum Nu;
	ComplexNum Nu1;
	ComplexNum NumC(5.345, -4.567);
	ComplexNum NumC1(5.345, 6.967);
	Num.Print();
	NumC.Print();
	NumC1.Print();
	Nu.Print();
	Nu1.Print();
	system("pause");
	return 0;
}
