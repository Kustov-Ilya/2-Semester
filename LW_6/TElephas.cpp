#include"TElephas.h"

int TElephas::Live(int ttime){
	std::cout << "Elephas    ";
	if (CheckDie(this->GetAgeOfDeaht())) return 0;
	// c 6 до 10 и с 16 до 18 ест
	if (ttime >= 6 && ttime < 10 || ttime >= 16 && ttime < 18)
		std::cout << GetName() << " is eating" << std::endl;
	// с 18 до 6 спит
	else if (ttime < 6 || ttime >= 18)
		std::cout << GetName() << " is sleeping" << std::endl;
	//с 10 до 11 могут родить
	else if (ttime <= 11 && ttime >= 10) {
		if (CheckReprod(this->GetAgeOfReprod())) return 1;
		std::cout << GetName() << " is looking at people" << std::endl;
	}
	// остальное время смотрит на людей
	else
		std::cout << GetName() << " is looking at people" << std::endl;
	return 2;
}

size_t TElephas::GetAgeOfDeaht(){
	return AgeOfDeath;
}

TAnimal* TElephas::Born(){
	std::cout << "Enter name of child:";
	std::string str;
	std::cin >> str;
	TAnimal *tm = new TElephas(str);
	return tm;
}


size_t TElephas::GetAgeOfReprod(){
	return AgeOfReprod;
}