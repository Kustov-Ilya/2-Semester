#include"TLohodonta.h"


int TLohodonta::Live(int ttime){
	std::cout << "Lohodonta   ";
	if (CheckDie(this->GetAgeOfDeaht())) return 0;
	// c 8 до 12 и с 18 до 20 ест
	if (ttime >= 8 && ttime < 12 || ttime >= 18 && ttime < 20)
		std::cout << GetName() << " is eating" << std::endl;
	// с 20 до 8 спит
	else if (ttime < 8 || ttime >= 20)
		std::cout << GetName() << " is sleeping" << std::endl;
	//с 12 до 14 могут родить
	else if (ttime < 14 && ttime >= 12){
		if (CheckReprod(this->GetAgeOfReprod())) return 1;
		std::cout << GetName() << " is looking at people" << std::endl;
	}
	// остальное время смотрит на людей
	else
		std::cout << GetName() << " is looking at people" << std::endl;
	return 2;
}

size_t TLohodonta::GetAgeOfReprod(){
	return AgeOfReprod;
}

size_t TLohodonta::GetAgeOfDeaht(){
	return AgeOfDeath;
}

TAnimal* TLohodonta::Born(){
	std::cout  << "Enter name of child:";
	std::string str;
	std::cin >> str;
	TAnimal *tm = new TLohodonta(str);
	return tm;
}