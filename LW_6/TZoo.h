#pragma once
#include "TAnimal.h"
#include "TProboscidea.h"
#include"TElephas.h"
#include"TLohodonta.h"
#include"TCarnivora.h"
#include"TLeo.h"
#include"TTigris.h"
#include"TArtiodaclyla.h"
#include"TGirafa.h"
#include"THippopotamus.h"


const int STEP = 1;

class TZoo
{
	typedef TAnimal * TPtrAnimal;

	std::string Name;

	/// �����
	TPtrAnimal * Animals;

	/// ������������ ����������� ��������
	size_t Capacity;

	/// ���������� ������ � ��������
	size_t NumAnimals;

	/// ����� �����
	int Time;
public:
	TZoo(std::string name, size_t capacity);
	std::string GetName();
	bool AddNewAnimal(TAnimal ** newAnimal);
	void DeleteAnimal(int i);
	void Work();
	void Swap(TZoo& zoo);
	~TZoo();
};