#include"TGirafa.h"

int TGirafa::Live(int ttime){
	std::cout << "TGirafa   ";
	if (CheckDie(this->GetAgeOfDeaht())) return 0;
	// c 8 до 10 и с 18 до 20 ест
	if (ttime >= 8 && ttime < 10 || ttime > 18 && ttime < 20)
		std::cout << GetName() << " is eating" << std::endl;
	// с 22 до 8 спит
	else if (ttime < 8 || ttime > 22)
		std::cout << GetName() << " is sleeping" << std::endl;
	//с 20 до 22 могут родить
	else if (ttime >= 20 && ttime <= 22){
		if (CheckReprod(this->GetAgeOfReprod())) return 1;
		std::cout << GetName() << " is breaking trees" << std::endl;
	}
	// остальное время рычит на людей
	else
		std::cout << GetName() << " is breaking trees" << std::endl;
	return 2;
}

size_t TGirafa::GetAgeOfReprod(){
	return AgeOfReprod;
}

size_t TGirafa::GetAgeOfDeaht(){
	return AgeOfDeath;
}

TAnimal* TGirafa::Born(){
	std::cout  << "Enter name of child:";
	std::string str;
	std::cin >> str;
	TAnimal *tm = new TGirafa(str);
	return tm;
}