#pragma once
#include"TArtiodaclyla.h"


class THippopotamus :public TArtiodaclyla{
	size_t AgeOfReprod = 13;
	size_t AgeOfDeath = 40;
public:
	THippopotamus()
		:TArtiodaclyla(){}
	~THippopotamus() = default;
	THippopotamus(const std::string & name, size_t age = 0)
		: TArtiodaclyla(name, age){}
	size_t GetAgeOfDeaht();
	size_t GetAgeOfReprod();
	virtual int Live(int ttime);
	virtual TAnimal *Born();
};