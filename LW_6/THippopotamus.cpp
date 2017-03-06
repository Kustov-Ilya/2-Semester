#include"THippopotamus.h"

int THippopotamus::Live(int ttime){
	std::cout << "THippopotamus   ";
	if (CheckDie(this->GetAgeOfDeaht())) return 0;
	// c 8 �� 10 � � 18 �� 20 ���
	if (ttime >= 8 && ttime < 10 || ttime > 18 && ttime < 20)
		std::cout << GetName() << " is eating" << std::endl;
	// � 20 �� 8 ����
	else if (ttime < 8 || ttime > 20)
		std::cout << GetName() << " is sleeping" << std::endl;
	//� 17 �� 18 ����� ������
	else if (ttime >= 17 && ttime <= 18){
		if (CheckReprod(this->GetAgeOfReprod())) return 1;
		std::cout << GetName() << " is lying in the mud" << std::endl;
	}
	// ��������� ����� ����� �� �����
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