#include"Header.h"

template<typename T>
void printVector(const TVector<T>& vec)
{
	for (int i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}



int main()
{
	{
		TVector<int> vec;
		for (int i = 0; i < 32; ++i)
			vec.push_back(i);

		TVector<float> vecq;
		for (int i = 0; i < 32; ++i)
			vecq.push_back(1.2);

		int *k=new int[2];
		k[0] = 1;
		k[1] = 2;

		TVector<int*> vecqq;
		for (int i = 0; i < 32; ++i)
			vecqq.push_back(k);

		printVector(vecq);

		printVector(vec);

		vec.insert(vec.begin() + 10, 1000);
		printVector(vec);

		vec.insert(vec.begin() + 10, 4, 1000);
		printVector(vec);

		vec.erase(vec.begin(), vec.begin() + 10);
		printVector(vec);

		vec.erase(vec.begin());
		printVector(vec);

		std::cout << vec.front() << std::endl;
		std::cout << vec.back() << std::endl;

		vec.pop_back();
		std::cout << vec.back() << std::endl;

		size_t oldSize = vec.size();
		vec.resize(44);
		printVector(vec);

		vec.resize(oldSize);
		printVector(vec);

		TVector<int> vec2;
		for (int i = 0; i < 2; ++i)
			vec2.push_back(i);

		vec2.swap(vec);
		printVector(vec2);
		printVector(vec);

		vec2 = vec;
		printVector(vec2);
		printVector(vec);

		try
		{
			TVector<int>::value_type item = vec2.at(1000000);
		}
		catch (const std::exception & e)
		{
			std::cout << e.what();
		}

		try
		{
			vec2.resize(UINT64_MAX);
		}
		catch (const std::exception & e)
		{
			std::cout << e.what();
		}
		delete[] k;
	}
	system("pause");
}