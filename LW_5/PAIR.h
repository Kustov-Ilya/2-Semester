#include<iostream>
#include<string>

using namespace std;

#ifndef MY_SYMBOL_H
#define MY_SYMBOL_H

class PAIR{
protected:
	int First;
	int Second;
public:
	//Конструктор по умолчанию
	PAIR();

	//Деструктор
	virtual ~PAIR()=default;

	//Конструктор c элементами
	PAIR(int a, int b)
		:First(a), Second(b){}

	//Функция сравниения на равенство
	bool Compare();

	//Функция перемножения
	int Multiplication();

	//Функция вычитания из a b
	virtual PAIR Subtraction(const PAIR &a, const PAIR &b);

	//Оператор вывода
	friend ostream &operator << (ostream &out, PAIR &nom);
};
#endif 
