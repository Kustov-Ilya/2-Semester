#include "TZoo.h"



TZoo::TZoo(std::string name, size_t capacity)
	: Capacity(capacity)
	, Name(name)
	, NumAnimals(0)
	, Time(10)
{
	Animals = new TPtrAnimal[Capacity];
	memset(Animals, 0, sizeof(TPtrAnimal) * Capacity);
}

bool TZoo::AddNewAnimal(TAnimal ** newAnimal)
{
	// Проверяем корректность входного параметра
	if (newAnimal == nullptr)
		return false;

	// Зоопарк полон, нельзя добавить нового зверя
	if (NumAnimals == Capacity)
		return false;

	// Добавляем зверя в массив
	Animals[NumAnimals] = *newAnimal;

	// Забираем зверя у старого владельца, чтобы не удалить зверя дважды
	*newAnimal = nullptr;

	// Увеличиваем счетчик
	++NumAnimals;

	return true;
}

void TZoo::DeleteAnimal(int i){
	while (i != NumAnimals-1){
		Animals[i] = Animals[i + 1];
		i++;
	}
	NumAnimals--;
}

std::string TZoo::GetName(){
	return Name;
}

void TZoo::Work()
{
	std::cout << "\n"<<Name << std::endl;
	size_t i = 0;
	int Pare = 0;
	while(i < NumAnimals)
	{
		if (Animals[i] != nullptr){
			// Демонстрация работы динамического полиморфизма
			int check = Animals[i]->Live(Time);
			if (check == 0) DeleteAnimal(i);
			else if (check == 1) {
				Pare++;
				if (Pare == 2){
					TAnimal *tmp = Animals[i]->Born();
					this->AddNewAnimal(&tmp);
					Pare = 0;
				}
				i++;
			}
			else i++;
			
		}
	}
	Time += STEP;
	if (Time > 24)
		Time -= 24;
}


TZoo::~TZoo()
{
	for (size_t i = 0; i < NumAnimals; ++i)
	{
		delete Animals[i];
	}
	delete[] Animals;
}

void TZoo::Swap(TZoo& zoo){
	std::cout << "Enter name of animal, which you want swap:";
	std::string buf;
	std::cin >> buf;
	int i = 0;
	while (i < NumAnimals){
		if (Animals[i]->GetName() == buf){
			int k = 0;
			while (k < zoo.NumAnimals){
				if (zoo.Animals[k]->CheckType() == Animals[i]->CheckType()){
					TAnimal *tmp = Animals[i];
					Animals[i] = zoo.Animals[k];
					zoo.Animals[k] = tmp;
					return;
				}
				k++;
			}
		}
		i++;
	}
	i = 0;
	while (i < zoo.NumAnimals){
		if (zoo.Animals[i]->GetName() == buf){
			int k = 0;
			while (k < NumAnimals){
				if (zoo.Animals[i]->CheckType() == Animals[k]->CheckType()){
					TAnimal *tmp = Animals[k];
					Animals[k] = zoo.Animals[i];
					zoo.Animals[i] = tmp;
					return;
				}
				k++;
			}
		}
		i++;
	}
	std::cout << "The exchange is not possible." << std::endl;

}