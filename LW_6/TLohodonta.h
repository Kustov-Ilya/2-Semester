#pragma once
#include "TProboscidea.h"


class TLohodonta :public TProboscidea{
	size_t AgeOfReprod = 8;
	size_t AgeOfDeath = 65;
public:
	TLohodonta()
		:TProboscidea(){}
	~TLohodonta() = default;
	TLohodonta(const std::string & name, size_t age = 0)
		: TProboscidea(name, age){}
	size_t GetAgeOfDeaht();
	size_t GetAgeOfReprod();
	virtual int Live(int ttime);
	virtual TAnimal *Born();
};