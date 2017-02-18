#include "TVector.h"

int main()
{
	int n = 0;
	while (n < 1){
		std::cout << "Enter nomber of elements"<< std::endl;
		std::cin >> n;
		std::cin.clear();
		std::cin.sync();
	}
	double* Mas1 = new double[n];
	for (int i = 0; i < n; i++)
		Mas1[i] = rand() % 100;
	double* Mas2 = new double[n];
	for (int i = 0; i < n; i++)
		Mas2[i] = rand() % 100;
	TVector Vec1(Mas1, n);
	TVector Vec2(Mas2, n);
	std::cout << "Vec1=";
	Vec1.Print();
	std::cout << "\nVec2=";
	Vec2.Print();
	std::cout << "\nThird element of Vec1=" <<Vec1[2] << std::endl;
	TVector Vec3;
	Vec3 = Vec1;
	std::cout << "\nVec3=";
	Vec3.Print();
	double* Mas = new double[n];
	Mas = Vec1 + Vec3;
	TVector Vec(Mas, n);

	std::cout << "\nVec3+Vec1=";
	Vec.Print();
	std::cout << "\n";
	system("pause");
	return 0;
}
