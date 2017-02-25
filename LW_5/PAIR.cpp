#include"PAIR.h"

PAIR::PAIR(){}

bool PAIR::Compare(){
	if (Second == First) return 1;
	return 0;
}

int PAIR::Multiplication(){
	return First*Second;
}

PAIR PAIR::Subtraction(const PAIR &a, const PAIR &b){
	First = a.First - b.First;
	Second = a.Second - b.Second;
	return *this;
}

ostream & operator << (ostream &out, PAIR &nom){

	out << nom.First << ", " << nom.Second << endl;
	return out;
}
