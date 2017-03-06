#pragma once
#include "TProboscidea.h"


class TElephas :public TProboscidea{
	size_t AgeOfReprod = 5;
	size_t AgeOfDeath = 60;
public:
	TElephas()
		:TProboscidea(){}
	~TElephas() = default;
	TElephas(const std::string & name, size_t age = 0)
		:TProboscidea(name, age){}
	size_t GetAgeOfDeaht();
	size_t GetAgeOfReprod();
	virtual int Live(int ttime);
	virtual TAnimal *Born();
};