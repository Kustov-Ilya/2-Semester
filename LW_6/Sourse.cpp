#include "TZoo.h"

int main()
{
	TZoo myZoo("Penzenskiy Zoo", 16);
	TAnimal *Animal1 = new TElephas("Alesha", 100);
	if (!myZoo.AddNewAnimal(&Animal1))
		delete Animal1;
	TAnimal *Animal2 = new TElephas("Lena", 65);
	if (!myZoo.AddNewAnimal(&Animal2))
		delete Animal2;
	TAnimal *Animal3 = new TLohodonta("Gena", 12);
	if (!myZoo.AddNewAnimal(&Animal3))
		delete Animal3;
	TAnimal *Animal4 = new TLohodonta("Dasha", 15);
	if (!myZoo.AddNewAnimal(&Animal4))
		delete Animal4;
	TAnimal *Animal5 = new TTigris("Tigr", 45);
	if (!myZoo.AddNewAnimal(&Animal5))
		delete Animal5;
	TAnimal *Animal6 = new TTigris("Tigra", 12);
	if (!myZoo.AddNewAnimal(&Animal6))
		delete Animal6;
	TAnimal *Animal7 = new TLeo("Lev", 23);
	if (!myZoo.AddNewAnimal(&Animal7))
		delete Animal7;
	TAnimal *Animal8 = new TLeo("L'vica", 14);
	if (!myZoo.AddNewAnimal(&Animal8))
		delete Animal8;

	TAnimal *Animal9 = new TGirafa("Giraf", 16);
	if (!myZoo.AddNewAnimal(&Animal9))
		delete Animal9;
	TAnimal *Animal10 = new TGirafa("Girafiha", 12);
	if (!myZoo.AddNewAnimal(&Animal10))
		delete Animal10;
	TAnimal *Animal11 = new THippopotamus("Begemot", 23);
	if (!myZoo.AddNewAnimal(&Animal11))
		delete Animal11;
	TAnimal *Animal12 = new THippopotamus("Begemotiha", 34);
	if (!myZoo.AddNewAnimal(&Animal12))
		delete Animal12;

	TZoo myZoo1("Samarskiy Zoo", 14);
	TAnimal *AAnimal1 = new TElephas("Albert", 65);
	if (!myZoo1.AddNewAnimal(&AAnimal1))
		delete AAnimal1;
	TAnimal *AAnimal2 = new TElephas("Cicilia", 45);
	if (!myZoo1.AddNewAnimal(&AAnimal2))
		delete AAnimal2;
	TAnimal *AAnimal3 = new TLohodonta("Snoi", 23);
	if (!myZoo1.AddNewAnimal(&AAnimal3))
		delete AAnimal3;
	TAnimal *AAnimal4 = new TLohodonta("Sveta", 54);
	if (!myZoo1.AddNewAnimal(&AAnimal4))
		delete AAnimal4;
	TAnimal *AAnimal5 = new TTigris("Taras", 65);
	if (!myZoo1.AddNewAnimal(&AAnimal5))
		delete AAnimal5;
	TAnimal *AAnimal6 = new TTigris("Tanya", 23);
	if (!myZoo1.AddNewAnimal(&AAnimal6))
		delete AAnimal6;
	TAnimal *AAnimal7 = new TLeo("Leviafa", 11);
	if (!myZoo1.AddNewAnimal(&AAnimal7))
		delete AAnimal7;
	TAnimal *AAnimal8 = new TLeo("Leva", 12);
	if (!myZoo1.AddNewAnimal(&AAnimal8))
		delete AAnimal8;
	TAnimal *AAnimal9 = new TGirafa("Ganna", 2);
	if (!myZoo1.AddNewAnimal(&AAnimal9))
		delete AAnimal9;
	TAnimal *AAnimal10 = new TGirafa("Gora", 34);
	if (!myZoo1.AddNewAnimal(&AAnimal10))
		delete AAnimal10;
	TAnimal *AAnimal11 = new THippopotamus("Beg", 35);
	if (!myZoo1.AddNewAnimal(&AAnimal11))
		delete AAnimal11;
	TAnimal *AAnimal12 = new THippopotamus("Bagi", 31);
	if (!myZoo1.AddNewAnimal(&AAnimal12))
		delete AAnimal12;

	for (size_t i = 0; i < 100; ++i)
	{
		myZoo.Work();
		myZoo1.Work();
		if (i%5==0)
		myZoo.Swap(myZoo1);
		std::cout << std::endl;
		
		// поток ждет 1 секунду
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	system("pause");
}