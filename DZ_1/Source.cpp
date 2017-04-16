#include"TMultiset.h"

int main() {
	{
		TMultiset<int> MyMultiset;
		try {
			MyMultiset.Erase(2);
		}
		catch(std::exception &r){
			std::cout << r.what() << std::endl;
		}
		for (int i = 0; i < 30; ++i)
			MyMultiset.Insert(rand() % 100);
		int i=MyMultiset.Erase(1);
		std::cout << *MyMultiset.lower_bound(50)<<std::endl;
		std::cout << *MyMultiset.upper_bound(53) << std::endl;
		MyMultiset.print();
		std::cout << std::endl;
		MyMultiset.Erase(27);
		TMultiset<int>::Iterator it = MyMultiset.Find(91);
		std::cout << *it << '\n';
		std::cout << MyMultiset.Size() << '\n';
		MyMultiset.print();
		std::cout << std::endl;
		TMultiset<int> MyMulti;
		for(int i=0; i<30; ++i)
			MyMulti.Insert(rand() % 10);
		MyMulti.print();
		std::cout << std::endl;
		MyMultiset.Swap(MyMulti);
		MyMultiset.print();
		std::cout << std::endl;
		MyMulti.print();
		std::cout << std::endl;
		for (TMultiset<int>::Iterator it = MyMultiset.begin(); it != MyMultiset.end(); ++it)
			std::cout << '_' << *it;
		std::cout << '\n';
		size_t n = MyMulti.Count(100);
		int myints[] = { 12,75,12,35,20,35 };
		TMultiset<int> My;
		My.Insert({1, 3, 4});
		My.print();
		std::cout << '\n';
		TMultiset<int> My1;
		My1.Insert(MyMultiset.begin(), MyMultiset.Find(3));
		My1.print();
		std::cout << '\n';
		TMultiset<int> Mym = MyMulti;
		Mym.print();
		std::cout << '\n';
		TMultiset<std::string> Myy;
		Myy.Insert("wqert");
		Myy.Insert("wqert");
		Myy.print();

	}
		system("pause");
	
	return 0;
}