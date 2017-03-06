#include"TElephas.h"

int TElephas::Live(int ttime){
	std::cout << "Elephas    ";
	if (CheckDie(this->GetAgeOfDeaht())) return 0;
	// c 6 �� 10 � � 16 �� 18 ���
	if (ttime >= 6 && ttime < 10 || ttime >= 16 && ttime < 18)
		std::cout << GetName() << " is eating" << std::endl;
	// � 18 �� 6 ����
	else if (ttime < 6 || ttime >= 18)
		std::cout << GetName() << " is sleeping" << std::endl;
	//� 10 �� 11 ����� ������
	else if (ttime <= 11 && ttime >= 10) {
		if (CheckReprod(this->GetAgeOfReprod())) return 1;
		std::cout << GetName() << " is looking at people" << std::endl;
	}
	// ��������� ����� ������� �� �����
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