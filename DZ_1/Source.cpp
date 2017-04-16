#include"TMultiset.h"

int main() {
	{
		TMultiset<int> MyMultiset;
		try {
			MyMultiset.erase(2);
		}
		catch(std::exception &r){
			std::cout << r.what() << std::endl;
		}
		for (int i = 0; i < 30; ++i)
			MyMultiset.insert(rand() % 100);
		int i=MyMultiset.erase(1);
		std::cout << *MyMultiset.lower_bound(50)<<std::endl;
		std::cout << *MyMultiset.upper_bound(53) << std::endl;
		MyMultiset.print();
		std::cout << std::endl;
		MyMultiset.erase(27);
		TMultiset<int>::Iterator it = MyMultiset.find(91);
		std::cout << *it << '\n';
		std::cout << MyMultiset.size() << '\n';
		MyMultiset.print();
		std::cout << std::endl;
		TMultiset<int> MyMulti;
		for(int i=0; i<30; ++i)
			MyMulti.insert(rand() % 10);
		MyMulti.print();
		std::cout << std::endl;
		MyMultiset.swap(MyMulti);
		MyMultiset.print();
		std::cout << std::endl;
		MyMulti.print();
		std::cout << std::endl;
		for (TMultiset<int>::Iterator it = MyMultiset.begin(); it != MyMultiset.end(); ++it)
			std::cout << '_' << *it;
		std::cout << '\n';
		size_t n = MyMulti.count(100);
		int myints[] = { 12,75,12,35,20,35 };
		TMultiset<int> My;
		My.insert({1, 3, 4});
		My.print();
		std::cout << '\n';
		TMultiset<int> My1;
		My1.insert(MyMultiset.begin(), MyMultiset.find(3));
		My1.print();
		std::cout << '\n';
		TMultiset<int> Mym = MyMulti;
		Mym.print();
		std::cout << '\n';
		TMultiset<std::string> Myy;
		Myy.insert("wqert");
		Myy.insert("wqert");
		Myy.print();
		int p=Myy.size();
		Myy.clear();
		bool o=Myy.empty();
	}
		system("pause");
	
	return 0;
}