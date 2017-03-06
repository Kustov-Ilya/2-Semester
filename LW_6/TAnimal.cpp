#include "TAnimal.h"



TAnimal::TAnimal()
	: Name()
	, Age(0)
{ }

TAnimal::TAnimal(const std::string & name, size_t age)
	: Name(name)
	, Age(age)
{ }

std::string TAnimal::GetName() const
{
	return Name;
}

size_t TAnimal::GetAge() const
{
	return Age;
}

int TAnimal::CheckDie(size_t aged){
	if (GetAge() >= aged){
		srand(time(0));
		int t = rand() % 25;
		if (t==0){
			std::cout << GetName() << " die" << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));
			delete this;
			return 1;
		}
	}
	return 0;
}

bool TAnimal::CheckReprod(size_t aged){
	if (GetAge() >= aged){
		srand(time(0));
		int t = rand() % 3;
		if (t ==0){
			std::cout << GetName() << " is finding partner for the birth of the child" << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));
			return 1;
		}
	}
	return 0;
}