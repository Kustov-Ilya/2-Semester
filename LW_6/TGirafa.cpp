#include"TGirafa.h"

int TGirafa::Live(int ttime){
	std::cout << "TGirafa   ";
	if (CheckDie(this->GetAgeOfDeaht())) return 0;
	// c 8 �� 10 � � 18 �� 20 ���
	if (ttime >= 8 && ttime < 10 || ttime > 18 && ttime < 20)
		std::cout << GetName() << " is eating" << std::endl;
	// � 22 �� 8 ����
	else if (ttime < 8 || ttime > 22)
		std::cout << GetName() << " is sleeping" << std::endl;
	//� 20 �� 22 ����� ������
	else if (ttime >= 20 && ttime <= 22){
		if (CheckReprod(this->GetAgeOfReprod())) return 1;
		std::cout << GetName() << " is breaking trees" << std::endl;
	}
	// ��������� ����� ����� �� �����
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