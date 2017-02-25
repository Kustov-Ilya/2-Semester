#include<iostream>
#include<string>

using namespace std;

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

class RATIONAL :public PAIR{
protected:
	int Numerator;
	int Denominator;
public:
	//Конструктор по умолчанию
	RATIONAL();

	//Деструктор
	~RATIONAL()=default;

	//Конструктор c элементами
	RATIONAL(int a, int b)
		:Numerator(a), Denominator(b){}

	//Функция вычитания из a b
	RATIONAL Subtraction(const RATIONAL &a, const RATIONAL &b);

	//Функция умножения дробей
	RATIONAL MultiplicDrob(const RATIONAL &a, const RATIONAL &b);

	//Функция сложения дробей
	RATIONAL Addition(const RATIONAL &a, const RATIONAL &b);

	//Оператор вывода
	friend ostream &operator << (ostream &out, RATIONAL &nom);
};
