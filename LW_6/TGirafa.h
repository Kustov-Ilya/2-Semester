#pragma once
#include"TArtiodaclyla.h"


class TGirafa :public TArtiodaclyla{
	size_t AgeOfReprod = 10;
	size_t AgeOfDeath = 15;
public:
	TGirafa()
		:TArtiodaclyla(){}
	~TGirafa() = default;
	TGirafa(const std::string & name, size_t age = 0)
		: TArtiodaclyla(name, age){}
	size_t GetAgeOfDeaht();
	size_t GetAgeOfReprod();
	virtual int Live(int ttime);
	virtual TAnimal *Born();
};