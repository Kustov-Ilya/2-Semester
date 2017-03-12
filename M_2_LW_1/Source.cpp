#include "Header.h"
#include <iostream>
#include <exception>

int CharToNum(char ch) {
	if (48 <= ch && 57 >= ch) return ch - 48;
	else throw UnknownValue();
}

bool BoolFromString(const char * data) {
	if (strcmp(data, "true")==0 || strcmp(data, "1")==0)
		return true;
	if (strcmp(data, "false")==0 || strcmp(data, "0")==0)
		return false;
	throw UnknownValue();
}

int IntFromString(const char * data) {
	bool Minus = false;
	int FirstPoz = 0;
	int Poz = 0;
	if (data[0] == '-') { 
		Minus = true;
		FirstPoz++;
	}
	if (data[0] == '+') FirstPoz++;
	while (data[FirstPoz + Poz]) {
		if (data[FirstPoz + Poz] == '0' && Poz == 0) FirstPoz++;
		else if(data[FirstPoz + Poz]=='.'|| data[FirstPoz + Poz]==',')
		{
			break;
		}
		else Poz++;
	}
	if (Poz > 10) throw BigLen();
	double Rez = 0.;
	for (int i = 0; i < Poz; i++) {
		if (CharToNum(data[FirstPoz + i])) {
			Rez += CharToNum(data[FirstPoz + i])*pow(10, Poz-i-1);
		}
	}
	if (Rez > 2147483647.0) throw BigLen();
	int RezEnd = static_cast<int>(Rez);
	if (Minus == true) return RezEnd*-1;
	return RezEnd;
}

int FloatFromString(const char * data) {
	bool Minus = false;
	int FirstPoz = 0;
	int Poz = 0;
	if (data[0] == '-') {
		Minus = true;
		FirstPoz++;
	}
	if (data[0] == '+') FirstPoz++;
	while (data[FirstPoz + Poz]) {
		if (data[FirstPoz + Poz] == '0' && Poz == 0) FirstPoz++;
		else if (data[FirstPoz + Poz] == '.' || data[FirstPoz + Poz] == ',')
		{
			break;
		}
		else Poz++;
	}
	if (Poz > 10) throw BigLen();
	double Rez = 0.;
	for (int i = 0; i < Poz; i++) {
		if (CharToNum(data[FirstPoz + i])) {
			Rez += CharToNum(data[FirstPoz + i])*pow(10, Poz - i - 1);
		}
	}
	for (int i = 1; data[FirstPoz+Poz+i]; i++)
	{
		double u = pow(10, -i);
		Rez += CharToNum(data[FirstPoz + i])/pow(10, i);
	}
	if (Rez > 2147483647.0) throw BigLen();
	float RezEnd = static_cast<float>(Rez);
	if (Minus == true) return RezEnd*-1;
	return RezEnd;
}

int main() {
	char r = ' ';
	try {
		CharToNum(r);
	}
	catch(UnknownValue &q){
		std::cout << "Unknown Value" << std::endl;
	}


	char check1[] = "true";
	bool CheCheck = BoolFromString(check1);
	char check2[] = "wqe";
	try {
		BoolFromString("wer");
	}
	catch (UnknownValue &q) {
		std::cout << "Unknown Value" << std::endl;
	}


	IntFromString("-00345,4");
	try {
		IntFromString("-02343457564565.4");
	}
	catch (BigLen &q) {
		std::cout << "Big Len" << std::endl;
	}
	try {
		IntFromString("-023434e.4");
	}
	catch (UnknownValue &q) {
		std::cout << "Unknown Value" << std::endl;
	}


	FloatFromString("-00345,4");
	try {
		FloatFromString("-02343457564565.4");
	}
	catch (BigLen &q) {
		std::cout << "Big Len" << std::endl;
	}
	try {
		FloatFromString("-023434e.4e");
	}
	catch (UnknownValue &q) {
		std::cout << "Unknown Value" << std::endl;
	}
	system("pause");
	return 0;
}