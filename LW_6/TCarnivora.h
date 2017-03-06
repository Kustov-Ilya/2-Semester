#pragma once
#include "TAnimal.h"

class TCarnivora :public TAnimal{
	std::string type = "TCarnivora";
public:
	TCarnivora()
		:TAnimal(){}
	TCarnivora(const std::string & name, size_t age = 0)
		: TAnimal(name, age){}
	virtual ~TCarnivora() = default;
	std::string CheckType(){
		return type;
	}
	virtual TAnimal* Born() = 0;
	virtual int Live(int time) = 0;
};