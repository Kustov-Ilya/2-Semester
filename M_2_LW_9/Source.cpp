#include<iostream>
#include"Header.h"

int main() {
	{
		int *p = new int[2];
		p[0] = 0;
		p[1] = 1;
		int *k = new int[2];
		k[0] = 1;
		k[1] = 2;
		TScopedPtr<int> Test(p);
		Test.reset(k);
		TScopedPtr<int> Test1;
		bool pe = Test1 == nullptr;
		if (Test) std::cout << "1234";
		swap(Test, Test1);
	}
	system("pause");
	return 0;
}