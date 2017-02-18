#include "iostream"

class TVector
{
private:
	double * Vec;
	int Size;
public:


	//деструктор
	~TVector();


	//конструктор без параметров, задающий пустой вектор
	TVector();

	
	//конструктор, создающий объект вектор на основе 
	//обычного одномерного массива размерности n
	TVector(double* vec, int size);


	//оператор []
	double operator[](size_t nom);


	//оператор =
	double * operator=(const TVector& vec);


	//функция вывода
	void Print();


	//оператор +
	friend double * operator+(const TVector& a, const TVector& b);



};
