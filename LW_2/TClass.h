#include<iostream>
#include <string>

//HaSoPr-hardware and software protection
class THaSoPr{
private:
	std::string Name;
	std::size_t Nomber;
public:


	//Деструктор
	~THaSoPr();


	//Конструктор по умолчанию
	THaSoPr();


	//Пользовательский конструктор
	THaSoPr(const std::string & nName, const std::size_t & nNomber);


	//Функция вывода 
	void Print();


	//Функция, проверяющая можно ли это СЗ использовать для заданного класса
	bool Check(const std::size_t & nNomber);
};
