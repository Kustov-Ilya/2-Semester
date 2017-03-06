#pragma once
#include "TAnimal.h"

class TArtiodaclyla :public TAnimal{
	std::string type = "TArtiodaclyla";
public:
	TArtiodaclyla()
		:TAnimal(){}
	TArtiodaclyla(const std::string & name, size_t age = 0)
		: TAnimal(name, age){}
	virtual ~TArtiodaclyla() = default;
	std::string CheckType(){
		return type;
	}
	virtual TAnimal* Born() = 0;
	virtual int Live(int time) = 0;
};