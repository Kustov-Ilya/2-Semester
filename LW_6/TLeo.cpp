#include"TLeo.h"

int TLeo::Live(int ttime){
	std::cout << "TLeo   ";
	if (CheckDie(this->GetAgeOfDeaht())) return 0;
	// c 6 �� 8 � � 16 �� 18 ���
	if (ttime >= 6 && ttime < 8 || ttime >= 16 && ttime < 18)
		std::cout << GetName() << " is eating" << std::endl;
	// � 18 �� 6 ����
	else if (ttime < 6 || ttime >= 18)
		std::cout << GetName() << " is sleeping" << std::endl;
	//� 8 �� 9 ����� ������
	else if (ttime >= 8 && ttime <= 9){
		if (CheckReprod(this->GetAgeOfReprod())) return 1;
		std::cout << GetName() << " is growls at people" << std::endl;
	}
	// ��������� ����� ����� �� �����
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