#include"Header.h"

int main() {
	int* a = new int[2];
	a[0] = 0;
	a[1] = 1;
	TArray <int, 4> test{1, 3, 4};
	TArray <int, 4> test1;
	test1 = { 1, 3, 3, 4 };
	int *k = test.begin();
	test.swap(test1);
	system("pause");
	return 0;
}