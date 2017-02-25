#include"Class.h"

int main(){
	PAIR Pa1(4, 7);
	PAIR Pa2(6, 7);
	bool Che = Pa1.Compare();
	int Mul = Pa2.Multiplication();
	PAIR Pa3;
	Pa3.Subtraction(Pa1, Pa2);
	RATIONAL Ra1(5, 9);
	RATIONAL Ra2(7, 8);
	RATIONAL Ra3, Ra4, Ra5;
	Ra3.Subtraction(Ra1, Ra2);
	Ra4.Addition(Ra1, Ra2);
	Ra5.MultiplicDrob(Ra1, Ra2);
	cout << "Pa1: " <<Pa1 << "Pa2: " << Pa2;
	cout << "Pa1-Pa2: "<<  Pa3;
	cout << "Ra1: " << Ra1 << "Ra2: " << Ra2;
	cout << "Ra1-Ra2: " <<  Ra3;
	cout << "Ra1+Ra2: " <<  Ra4;
	cout << "Ra1*Ra2: " <<  Ra5;
	system("pause");
	return 0;
}
