#pragma once
#include "TAnimal.h"

class TProboscidea :public TAnimal{
	std::string type = "TProboscidea";
public:
	TProboscidea()
		:TAnimal(){}
	TProboscidea(const std::string & name, size_t age = 0)
		: TAnimal(name, age){}
	virtual ~TProboscidea() = default;
	std::string CheckType(){
		return type;
	}
	virtual TAnimal* Born() = 0;
	virtual int Live(int time) = 0;
};