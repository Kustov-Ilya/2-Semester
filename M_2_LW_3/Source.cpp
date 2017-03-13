#include"Header.h"

int main() {
	bool Dat;
	TInteger Q1;
	TInteger Q2(29999);
	Q1 = 2999990;
	if (Q1 == Q2) Dat = true;
	else Dat = false;
	TInteger Q3 = Q1 + Q2;
	TInteger Q4 = Q3 + 6;
	Q4 = 7 + Q3;
	try {
		TInteger(5999999999);
	}
	catch(InvalideValue &q){
		q.what();
	}

	try {
		TInteger Q5 = Q1*Q2*45673;
	}
	catch (InvalideValue &q) {
		q.what();
	}

	try {
		TInteger Q6 = Q1 / 5999999999;
	}
	catch (InvalideValue &q) {
		q.what();
	}

	try {
		TInteger Q7= Q1+9999999999;
	}
	catch (InvalideValue &q) {
		q.what();
	}

	system("pause");
	return 0;
}
