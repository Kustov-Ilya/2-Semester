template<class It, class Cmp>
void qsort(It beg, It end, Cmp cmp)
{
		It prev = beg;
		It tmp = prev++;
		It next = end;
		while (prev != next)
		{
			if (cmp(*prev, *tmp)) ++prev;
			else{
				while ((prev != --next) && cmp(*tmp, *next));
				std::iter_swap(prev, next);
			}
		}
		std::iter_swap(beg, --prev);
		if (std::distance(beg, prev)>0)
			qsort(beg, prev, cmp);
		if (std::distance(next, end)>0)
			qsort(next, end, cmp);
}

int main() {
	std::vector<int> vec;
	for (int i = 0; i < 30; ++i) vec.push_back(rand() % 100);
	qsort<std::vector<int>::iterator, std::less<int>>(vec.begin(), vec.end(), std::less<int>());
	system("pause");
	return 0;
}
