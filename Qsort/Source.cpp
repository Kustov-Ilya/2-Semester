#include<iostream>
#include<vector>

template<class It, class Cmp>
void qsort(It beg, It end, Cmp cmp)
{
	It Tend = end;
	--end;
	It point = sort<It, Cmp>(beg, end, cmp);
	It next = point;
	if(next!=end) ++next;

	if (std::distance(beg, point)>0)
		qsort<It, Cmp>(beg, point, cmp);
	if (std::distance(next, end)>0)
		qsort<It, Cmp>(next, Tend, cmp);
}

template<class It, class Cmp>
It sort(It beg, It end, Cmp cmp)
{
	It pos = beg;
	while (1){
		It i = end;

		while (cmp(*pos, *i) && (i > pos)) --i;

		if (i != pos) std::swap(*pos, *i);
		else
		{
			return pos;
			break;
		}

		pos = i;
		i = beg;
		++i;

		while (cmp(*i, *pos) && (i < pos)) ++i;

		if (i != pos) std::swap(*pos, *i);
		else
		{
			return pos;
			break;
		}
		pos = i;
	}
}

int main() {
	std::vector<int> vec;
	for (int i = 0; i < 30; ++i) vec.push_back(rand() % 100);
	qsort<std::vector<int>::iterator, std::less<int>>(vec.begin(), vec.end(), std::less<int>());
	system("pause");
	return 0;
}
