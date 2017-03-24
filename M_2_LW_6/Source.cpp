#include "Header.h"
#include <iostream>
#include <exception>

template<typename T>
T FromString(const char * data) {
	throw UnknownType();
}

template<>
bool FromString<bool>(const char * data) {
	if (strcmp(data, "true")==0 || strcmp(data, "1")==0)
		return true;
	if (strcmp(data, "false")==0 || strcmp(data, "0")==0)
		return false;
	throw UnknownValue();
}

template<>
int FromString<int>(const char * data) {
	bool Minus = false;
	bool Symbol = false;
	int Elem;
	int Poz = 0;
	double Rez = 0.;
	if (data[0] == '-' || data[0] == '+') {
		if (data[0] == '-') {
			Minus = true;
		}
		Poz++;
	}
	while (data[Poz]) {
		if (48 <= data[Poz] && 57 >= data[Poz])
		{
			Elem = data[Poz] - 48;
			Poz++;
		}
		else if ((data[Poz] == '.' || data[Poz] == ',') && Symbol == false) {
			Poz++;
			Symbol = true;
		}
		else
			throw UnknownValue();
		if (Symbol == false) {
			Rez = Rez * 10 + Elem;
		}
	}
	if (Rez > 2147483647.0) throw BigLen();
	int EndRez = static_cast<int>(Rez);
	if (Minus == true) return EndRez*-1;
	return EndRez;
}

template<>
float FromString<float>(const char * data) {
	int Elem;
	bool Minus = false;
	bool real = false;
	int Poz = 0;
	int Num = 0;
	double Rez = 0.;
	if (data[0] == '-' || data[0] == '+') {
		if (data[0] == '-') {
			Minus = true;
		}
		Poz++;
	}
	while (data[Poz]) {
		if (data[Poz] != '.'&&data[Poz] != ',') {
			if (real == false) {
				if (48 <= data[Poz] && 57 >= data[Poz]) Elem = data[Poz] - 48;
				else throw UnknownValue();
				Rez = Rez * 10 + Elem;
			}
			else {
				Num++;
				if (48 <= data[Poz] && 57 >= data[Poz]) Elem = data[Poz] - 48;
				else throw UnknownValue();
				Rez += Elem/pow(10, Num);
			}
			Poz++;
		}
		else {
			real = true;
			Poz++;
		}
	}
	if (Rez > 2147483647.0) throw BigLen();
	float EndRez = static_cast<float>(Rez);
	if (Minus == true) return EndRez*-1;
	return EndRez;
}

int main() {
	char check1[] = "true";
	bool CheCheck = FromString<bool>(check1);
	char check2[] = "wqe";
	try {
		FromString<bool>("wer");
	}
	catch (Exception &q) {
		std::cout << q.what() << std::endl;
	}


	FromString<int>("-00345,4");
	try {
		FromString<int>("-02343457564565.4");
	}
	catch (Exception &q) {
		std::cout << q.what() << std::endl;
	}
	try {
		FromString<int>("-023434e.4");
	}
	catch (Exception &q) {
		std::cout << q.what() << std::endl;
	}


	FromString<float>("-00345,4");
	try {
		FromString<float>("-02343457564565.4");
	}
	catch (Exception &q) {
		std::cout << q.what() << std::endl;
	}
	try {
		FromString<float>("-023434e.4e");
	}
	catch (Exception &q) {
		std::cout << q.what() << std::endl;
	}
	try {
		FromString<int>("12134.1243,1");
	}
	catch (Exception &q) {
		std::cout << q.what()<<std::endl;
	}
	FromString<int>("9999999");
	system("pause");
	return 0;
}