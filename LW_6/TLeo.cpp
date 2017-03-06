#include"TLeo.h"

int TLeo::Live(int ttime){
	std::cout << "TLeo   ";
	if (CheckDie(this->GetAgeOfDeaht())) return 0;
	// c 6 до 8 и с 16 до 18 ест
	if (ttime >= 6 && ttime < 8 || ttime >= 16 && ttime < 18)
		std::cout << GetName() << " is eating" << std::endl;
	// с 18 до 6 спит
	else if (ttime < 6 || ttime >= 18)
		std::cout << GetName() << " is sleeping" << std::endl;
	//с 8 до 9 могут родить
	else if (ttime >= 8 && ttime <= 9){
		if (CheckReprod(this->GetAgeOfReprod())) return 1;
		std::cout << GetName() << " is growls at people" << std::endl;
	}
	// остальное время рычит на людей
	else
		std::cout << GetName() << " is growls at people" << std::endl;
	return 2;
}

size_t TLeo::GetAgeOfReprod(){
	return AgeOfReprod;
}

size_t TLeo::GetAgeOfDeaht(){
	return AgeOfDeath;
}

TAnimal* TLeo::Born(){
	std::cout  << "Enter name of child:";
	std::string str;
	std::cin >> str;
	TAnimal *tm = new TLeo(str);
	return tm;
}