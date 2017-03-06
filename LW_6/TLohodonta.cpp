#include"TLohodonta.h"


int TLohodonta::Live(int ttime){
	std::cout << "Lohodonta   ";
	if (CheckDie(this->GetAgeOfDeaht())) return 0;
	// c 8 �� 12 � � 18 �� 20 ���
	if (ttime >= 8 && ttime < 12 || ttime >= 18 && ttime < 20)
		std::cout << GetName() << " is eating" << std::endl;
	// � 20 �� 8 ����
	else if (ttime < 8 || ttime >= 20)
		std::cout << GetName() << " is sleeping" << std::endl;
	//� 12 �� 14 ����� ������
	else if (ttime < 14 && ttime >= 12){
		if (CheckReprod(this->GetAgeOfReprod())) return 1;
		std::cout << GetName() << " is looking at people" << std::endl;
	}
	// ��������� ����� ������� �� �����
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