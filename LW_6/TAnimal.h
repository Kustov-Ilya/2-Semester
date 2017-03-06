#pragma once
#include <string>
#include <iostream>
#include<ctime>
#include <thread>

class TAnimal
{
	std::string Name;
	size_t Age;

public:
	TAnimal();
	TAnimal(const std::string & name, size_t age = 0);
	virtual ~TAnimal() = default;
	virtual int Live(int time) = 0;
	int CheckDie(size_t aged);
	virtual TAnimal* Born() = 0;
	bool CheckReprod(size_t aged);
	std::string GetName() const;
	std::string virtual CheckType() = 0;
	size_t GetAge() const;
};
