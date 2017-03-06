#include"THippopotamus.h"

int THippopotamus::Live(int ttime){
	std::cout << "THippopotamus   ";
	if (CheckDie(this->GetAgeOfDeaht())) return 0;
	// c 8 до 10 и с 18 до 20 ест
	if (ttime >= 8 && ttime < 10 || ttime > 18 && ttime < 20)
		std::cout << GetName() << " is eating" << std::endl;
	// с 20 до 8 спит
	else if (ttime < 8 || ttime > 20)
		std::cout << GetName() << " is sleeping" << std::endl;
	//с 17 до 18 могут родить
	else if (ttime >= 17 && ttime <= 18){
		if (CheckReprod(this->GetAgeOfReprod())) return 1;
		std::cout << GetName() << " is lying in the mud" << std::endl;
	}
	// остальное время рычит на людей
	else
		std::cout << GetName() << " is lying in the mud" << std::endl;
	return 2;
}

size_t THippopotamus::GetAgeOfReprod(){
	return AgeOfReprod;
}

size_t THippopotamus::GetAgeOfDeaht(){
	return AgeOfDeath;
}

TAnimal* THippopotamus::Born(){
	std::cout  << "Enter name of child:";
	std::string str;
	std::cin >> str;
	TAnimal *tm = new THippopotamus(str);
	return tm;
}