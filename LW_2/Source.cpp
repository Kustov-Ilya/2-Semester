#include "TClass.h"

int main(){
	int n=0, k=0, Nom=0;
	std::string Name;
	while (n < 1){
		std::cout << "Enter nomber of elements" << std::endl;
		std::cin >> n;
		std::cin.clear();
		std::cin.sync();
	}
	THaSoPr *Massive = new THaSoPr[n];
	for (int i = 0; i < n; i++)
	{
		std::cout << "\n" <<i+1 << " hardware and software protection" << std::endl;
		std::cout << "Enter name of hardware and software protection:";
		std::cin >> Name;
		while (Nom < 1 || Nom>7){
			std::cout << "Enter the class of hardware and software protection from 1 to 7:";
			std::cin >> Nom;
			std::cin.clear();
			std::cin.sync();
		}
		Massive[i]=THaSoPr(Name, Nom);
		Nom = 0;
	}
	std::cout << "\n" << std::endl;
	while (k < 1 || k>7){
		std::cout << "Enter the class of protection, which you need from 1 to 7:";
		std::cin >> k;
		std::cin.clear();
		std::cin.sync();
	}
	for (int i = 0; i < n; i++)
	{
		if (Massive[i].Check(k) == 1) Massive[i].Print();
	}
	system("pause");
	return 0;
}
