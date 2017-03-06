#include"TTigris.h"

int TTigris::Live(int ttime){
	std::cout << "TTigris   ";
	if (CheckDie(this->GetAgeOfDeaht())) return 0;
	// c 8 �� 10 � � 16 �� 18 ���
	if (ttime >= 8 && ttime < 10 || ttime > 16 && ttime < 18)
		std::cout << GetName() << " is eating" << std::endl;
	// � 18 �� 8 ����
	else if (ttime < 8 || ttime >= 18)
		std::cout << GetName() << " is sleeping" << std::endl;
	//� 15 �� 16 ����� ������
	else if (ttime >= 15 && ttime <= 16){
		if (CheckReprod(this->GetAgeOfReprod())) return 1;
		std::cout << GetName() << " is growls at people" << std::endl;
	}
	// ��������� ����� ����� �� �����
	else
		std::cout << GetName() << " is growls at people" << std::endl;
	return 2;
}

size_t TTigris::GetAgeOfReprod(){
	return AgeOfReprod;
}

size_t TTigris::GetAgeOfDeaht(){
	return AgeOfDeath;
}

TAnimal* TTigris::Born(){
	std::cout << "Enter name of child:";
	std::string str;
	std::cin >> str;
	TAnimal *tm = new TTigris(str);
	return tm;
}