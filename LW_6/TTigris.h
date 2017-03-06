#pragma once
#include"TCarnivora.h"


class TTigris :public TCarnivora{
	size_t AgeOfReprod = 3;
	size_t AgeOfDeath = 25;
public:
	TTigris()
		:TCarnivora(){}
	~TTigris() = default;
	TTigris(const std::string & name, size_t age = 0)
		: TCarnivora(name, age){}
	size_t GetAgeOfDeaht();
	size_t GetAgeOfReprod();
	virtual int Live(int ttime);
	virtual TAnimal *Born();
};