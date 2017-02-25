#include"PAIR.h"

class RATIONAL :public PAIR{
protected:
	int Numerator;
	int Denominator;
public:
	//Конструктор по умолчанию
	RATIONAL();

	//Деструктор
	~RATIONAL() = default;

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
