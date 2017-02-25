#include"RATIONAL.h"

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

ostream & operator << (ostream &out, RATIONAL &nom){

	out << nom.Numerator << "/" << nom.Denominator << endl;
	return out;
}
