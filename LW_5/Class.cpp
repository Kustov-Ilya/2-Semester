#include"Class.h"

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

RATIONAL::RATIONAL(){}

RATIONAL RATIONAL::Subtraction(const RATIONAL &a, const RATIONAL &b){
	Numerator = a.Numerator*b.Denominator - a.Denominator*b.Numerator;
	Denominator = a.Denominator*b.Denominator;
	return *this;
}

RATIONAL RATIONAL::MultiplicDrob(const RATIONAL &a, const RATIONAL &b){
	Numerator = a.Numerator*b.Numerator;
	Denominator = a.Denominator*b.Denominator;
	return *this;
}

RATIONAL RATIONAL::Addition(const RATIONAL &a, const RATIONAL &b){
	Numerator = a.Numerator*b.Denominator + a.Denominator*b.Numerator;
	Denominator = a.Denominator*b.Denominator;
	return *this;
}

ostream & operator << (ostream &out, PAIR &nom){

	out << nom.First << ", " << nom.Second << endl;
	return out;
}

ostream & operator << (ostream &out, RATIONAL &nom){

	out << nom.Numerator << "/" << nom.Denominator << endl;
	return out;
}
