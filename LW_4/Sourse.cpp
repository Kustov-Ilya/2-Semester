#include"RealNum.h"
#include"ComplexNum.h"

int main(){
	RealNum *Real = new RealNum(-6.345);
	RealNum *Complex1 = new ComplexNum(5.345, 6.967);
	ComplexNum *Complex2 = new ComplexNum(4.324, -4.322);
	Real->Print();
	Complex1->Print(); 
	Complex2->Print();
	delete Real;
	delete Complex1;
	delete Complex2;
	system("pause");
	return 0;
}
