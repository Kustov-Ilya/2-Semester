#include<iostream>
#include<vector>

template<class IT>
void sort(IT beg, IT end) {
	while (beg < --end) {
		for (IT i = beg; i != end; ++i) {
			if (*(i + 1) < *i) {
				std::swap(*i, *(i + 1));
			}
		}
	}
}

int main() {
	int arr[] = { 123, 3, 0, 13212, -100 };
	sort(arr + 0, arr + 3); // arr: 0, 3, 123, 13212, -100
	sort(arr + 2, arr + 5); // arr: 0, 3, -100, 123, 13212

	std::vector<double> vec = { 123.0, 3.0, 0.0, 13212.0, -100.0 };
	sort(vec.begin(), vec.end()); // vec: -100.0, 0.0, 3.0, 123.0, 13212.0
	system("pause");
	return 0;
}