#ifndef __BOOLEAN_FUNCTION_INCLUDED__
#define __BOOLEAN_FUNCTION_INCLUDED__

#include <string>
#include <vector>
#include<sstream>
#include <math.h>
class boolean_function
{
public:
	using value_type = bool;
	using size_type = size_t;
	using reference = std::vector<value_type>::reference;
	using const_reference = std::vector<value_type>::const_reference;

	using iterator = typename std::vector<value_type>::iterator;
	using const_iterator = typename std::vector<value_type>::const_iterator;

	std::vector<bool> Vector;

public:

	// âîçâðàùàåò ôóíêöèþ êîòîðàÿ ðàâíà xn ñ ðàçìåðíîñòüþ dimension
	// ïðèìåð 1
	// n = 0
	// dimension = 3
	// âåðíåòñÿ ôóíêöèÿ "01010101"
	// ïðèìåð 2
	// n = 1
	// dimension = 4
	// âåðíåòñÿ ôóíêöèÿ "0011001100110011"
	static boolean_function var(size_t n, size_t dimension)
	{
		std::vector<bool> value;
		size_t Num = pow(2, dimension);
		while (value.size() < Num)
		{
			for (size_t i = 0; i < pow(2, n); ++i)
			{
				value.push_back(0);
			}
			for (size_t i = 0; i < pow(2, n); ++i)
			{
				value.push_back(1);
			}
		}
		return boolean_function(value);
	}

	// òîæäåñòâåííûé íîëü "îò dimension ïåðåìåííûõ"
	static boolean_function zero(size_t dimension)
	{
		std::string var;
		for (size_type i = 0; i < pow(2, dimension); ++i)
			var += '0';
		return boolean_function(var);
	}

	// òîæäåñòâåííàÿ åäèíèöà "îò dimension ïåðåìåííûõ"
	static boolean_function one(size_t dimension)
	{
		std::string var;
		for (size_type i = 0; i < pow(2, dimension); ++i)
			var += '1';
		return boolean_function(var);
	}
	//
	static boolean_function from_anf(std::vector<value_type> v) {
		boolean_function Anf(v);
		std::vector<bool> vec = Anf.anf();
		return vec;
	}

	boolean_function()
	{}
	//
	// çàäàåò ôóíöèþ òîæäåñòâåííîãî íóëÿ îò n ïåðåìåííûõ
	boolean_function(size_t n)
	{
		for (size_t i = 0; i < pow(2, n); ++i)
		{
			Vector.push_back(0);
		}
	}
	//
	//	// çàäàåò ôóíöèþ îò n ïåðåìåííûõ. çíà÷åíèå ðàâíî value
	//	// ïðèìåð
	//	// ïóñòü value = 14, ò.å. 0...00001110 â äâîè÷íîé ñèñòåìå
	//	// à n = 3
	//	// òîãäà ÀÍÔ boolean_function áóäåò ðàâíà x + y + xy + zx + zy + zyx
	boolean_function(unsigned long long value, size_type n)
	{
		size_t Num = pow(2, n);
		while (value > 0) {
			Vector.push_back(value % 2);
			value /= 2;
		}
		while (size() < Num) {
			Vector.push_back(0);
		}
	}
	//
	//	// ïóñòü table = "01110000"
	//	// òîãäà ÀÍÔ boolean_function áóäåò ðàâíà x + y + xy + zx + zy + zyx
	boolean_function(const std::string& table)
	{
		if (log2(table.size()) - (int)log2(table.size()) != 0) throw std::exception("ERROR lenght");
		for (size_t i = 0; i < table.size(); ++i)
		{
			if (table[i] == '0') Vector.push_back(0);
			else if (table[i] == '1')Vector.push_back(1);
			else throw;
		}

	}
	//
	//	// ïóñòü table = {true, false, false, true};
	//	// òîãäà ÀÍÔ boolean_function áóäåò ðàâíà x + y + 1
	boolean_function(const std::vector<value_type>& table)
	{
		Vector = table;
	}
	boolean_function(const std::initializer_list<bool> vars)
	{
		if (log2(vars.size()) - (int)log2(vars.size()) != 0) throw std::exception("ERROR lenght");
		for (auto&a : vars)
		{
			Vector.push_back(a);
		}
	}
	boolean_function(const boolean_function& table)
	{
		Vector = table.Vector;
	}
	//
	boolean_function& operator=(const boolean_function& rhs)
	{
		for (size_t n = 0; n<rhs.size(); ++n)
			Vector.push_back(rhs.Vector[n]);
		return *this;
	}
	// ñëîæåíèå ïî ìîäóëþ 2
	// åñëè ðàçíîå êîëè÷åñòâî ïåðåìåííûõ - èñêëþ÷åíèå
	boolean_function& operator += (const boolean_function& rhs)
	{
		if (size() != rhs.size()) {
			throw std::exception("ERROR lenght");
		}
		for (size_t n = 0; n < size(); ++n) {
			if ((Vector[n] == 1 && rhs.Vector[n] == 1) || (Vector[n] == 0 && rhs.Vector[n] == 0))
				Vector[n] = 0;
			else Vector[n] = 1;
		}
		return *this;
	}
	//	// êîíúþíêöèÿ
	//	// åñëè ðàçíîå êîëè÷åñòâî ïåðåìåííûõ - èñêëþ÷åíèå
	boolean_function& operator *= (const boolean_function& rhs)
	{
		if (size() != rhs.size()) {
			throw std::exception("ERROR lenght");
		}
		for (size_t n = 0; n < size(); ++n)
		{
			if (Vector[n] == 1 && rhs.Vector[n] == 1) Vector[n] = 1;
			else Vector[n] = 0;
		}
		return *this;
	}
	//
	// äèçúþíêöèÿ
	// åñëè ðàçíîå êîëè÷åñòâî ïåðåìåííûõ - èñêëþ÷åíèå
	boolean_function& operator |= (const boolean_function& rhs)
	{
		if (size() != rhs.size()) {
			throw std::exception("ERROR lenght");
		}
		for (size_t n = 0; n < size(); ++n)
		{
			if (Vector[n] == 0 && rhs.Vector[n] == 0) Vector[n] = 0;
			else Vector[n] = 1;
		}
		return *this;
	}
	// ïîáèòîâîå îòðèöàíèå
	boolean_function operator ~ ()
	{
		Vector.flip();
		return *this;
	}
	//
	// true åñëè ôóíêöèè ðàâíû
	//  èíà÷å false
	bool operator == (const boolean_function& obj) const
	{
		size_t n;
		if (size() < obj.size()) {
			n = size();
		}
		else {
			n = obj.size();
		}
		for (size_t i = 0; i < n; ++i) {
			if (Vector[i] != obj.Vector[i]) {
				return false;
			}
		}
		return true;
	}
	//
	//	// true åñëè îäíà ôóíêöèÿ ñðàâíèìà è áîëüøå èëè ðàâíà rhs
	//	// false åñëè ñðàâíèìà è ìåíüøå rhs
	//	// logic_error åñëè ôóíöèè íå ñðàâíèìû
	bool operator >= (const boolean_function& rhs) const
	{

		if (size() != rhs.size()) {
			throw std::exception("ERROR lenght");
		}
		size_type Comp = 0;
		for (size_t i = 0; i < size(); ++i)
		{
			if (static_cast<size_type>(rhs[i]) > static_cast<size_type>(Vector[i])) {
				if (Comp == 1) throw std::logic_error("ERROR: can't compare");
				if (Comp == 0)Comp = 2;
			}
			else if (static_cast<size_type>(rhs[i]) > static_cast<size_type>(Vector[i])) {
				if (Comp == 2) throw std::logic_error("ERROR: can't compare");
				if (Comp == 0)Comp = 1;
			}
			else if (Comp == 0) Comp = 1;
		}
		return Comp == 1;
	}
	//
	reference operator[](size_type ind)
	{
		if (size() == 0)
			throw std::exception("ERROR");
		if (ind < 0 || ind >= size())
			throw std::exception("ERROR");
		return Vector[ind];
	}
	const_reference operator[](size_type ind) const
	{
		if (size() == 0)
			throw std::exception("ERROR");
		if (ind < 0 || ind >= size())
			throw std::exception("ERROR");
		return Vector[ind];
	}

	reference at(size_type ind)
	{
		if (ind > size() - 1 || size() == 0) throw std::out_of_range("ERROR");
		return Vector[ind];
	}
	const_reference at(size_type ind) const
	{
		if (ind > size() - 1 || size() == 0) throw std::out_of_range("ERROR");
		return Vector[ind];
	}
	//
	iterator begin()
	{
		return Vector.begin();
	}
	iterator end()
	{
		return Vector.end();
	}
	//
	const_iterator cbegin() const
	{
		return Vector.cbegin();
	}
	const_iterator cend() const
	{
		return Vector.cend();
	}
	//
	// äëèíà ñòîëáöà ôóíêöèè
	size_type size() const throw()
	{
		return Vector.size();
	}
	// êîëè÷åñòâî ïåðåìåííûõ
	size_type dimension() const throw()
	{
		return log2(Vector.size());
	}
	//
	//	// âîçâðàùàåò çíà÷åíèå ôóíêöèè
	//	// ïóñòü boolean_function çàäàåò ôóíêöèþ f(x, y, z)
	//	// òîãäà ôóíêöèÿ âåðíåò f(vars[0], vars[1], vars[2])
	bool operator()(const std::vector<bool>& vars) const {
		if (vars.size() != dimension()) throw std::exception("ERROR lenght");
		size_type Num = dimension();
		size_type val = 0;
		for (auto it = vars.begin(); it != vars.end(); ++it) {
			val += (*it)*pow(2, Num);
			Num--;
		}
	}
	bool operator()(const std::initializer_list<bool> vars) const {
		if (vars.size() != dimension()) throw std::exception("ERROR lenght");
		size_type Num = dimension() - 1;
		size_type val = 0;
		for (auto it = vars.begin(); it != vars.end(); ++it) {
			val += (*it)*pow(2, Num);
			Num--;
		}
		return Vector[val];
	}
	//
	//
	//	// T(x1, x2, ..., xN) - òåêóùàÿ ôóíêöèÿ
	//	// operator âåðíåò íîâóþ ôóíêöèþ, êîòîðàÿ ðàâíà êîìïîçèöèè G = T(fs[0], fs[1], ..., fs[N-1])
	boolean_function operator()(const std::vector<boolean_function>& fs) const {
		size_t s = 0;
		for (auto &v : fs)
			if (v.size() > s) s = v.size();

		std::vector<boolean_function> bf = fs;
		for (auto it = bf.begin(); it != bf.end(); ++it) {
			while (it->size() != s) {
				size_t i = it->size();
				it->Vector.resize(2 * i);
				for (size_t j = 0; j < i ; ++j) {
					it->Vector[i + j] = it->Vector[j];
				}
			}
		}
		std::vector<bool> tmp;
		for (size_t i = 0; i < s; ++i) {
			std::vector<bool> rhs;
			for (size_t j = 0; j < fs.size(); ++j)
				rhs.push_back(bf.at(j).at(i));
			tmp.push_back((*this)(rhs));
		}
		boolean_function Func(tmp);
		return Func;
		
	}
	boolean_function operator()(const std::initializer_list<boolean_function> vars) const {
		std::vector<value_type> res;
		std::vector<boolean_function> f;
		int s = 0;
		for (auto &v : vars){
			if (v.size() > s)
				s = v.size();
			f.push_back(v);
		}
		int len = vars.size();
		int** mas = new int*[s];
		for (int i = 0; i < s; i++) mas[i] = new int[len];
		int it = 0;
		while (it < f.size()){
			for (int i = 0; i < len; i++){
				int k = 0;
				for (int j = 0; j < s; j++){
					if (k >= f[it].size())k = 0;
					mas[j][i] = f[it][k];
					k++;
				}
				it++;
			}
		}

		for (int i = 0; i < s; i++){
			int ch = 0;
			int st = 0;
			for (int j = len - 1; j > -1; j--){
				ch = ch + pow(2, st)*mas[i][j];
				st++;
			}
			res.push_back(Vector[ch]);
		}
		for (int i = 0; i < s; i++)
			delete[] mas[i];
		delete[] mas;
		boolean_function result(res);
		return result;
	}
	//
	bool is_monotone() const
	{
		for (size_t i = 1; i < Vector.size(); ++i) {
			if (Vector[i-1] > Vector[i])
				return false;
		}
		return true;
	}
	bool is_symmetric() const
	{
		std::vector<bool> CheckVector;
		for (size_type i = 0; i < size(); ++i) {
			CheckVector.push_back(Vector[Vector.size() - 1 - i]);
		}
		CheckVector.flip();
		if (Vector == CheckVector) return true;
		return false;
	}
	bool is_linear() const {
		std::vector<value_type> a = anf();
		size_t t = 0;
		for (size_t i = 1; i < a.size(); ++i)
		{
			if (i == pow(2, t))
				++t;
			else if (a[i] == 1)
				return false;
		}
		return true;
	}
	bool is_T1() const
	{
		return Vector[Vector.size() - 1] == 1;
	}
	bool is_T0() const
	{
		return Vector[0] == 0;
	}
	//ðàâíîâåñíàÿ ëè
	bool is_balanced() const
	{
		return weight() == (size() / 2);
	}
	size_t weight() const
	{
		size_type result = 0;
		for (size_type i = 0; i < size(); ++i)
			if (Vector[i] == 1) ++result;
		return result;
	}

	bool is_functionally_complete_system() const {
		return ((!is_T0()) && (!is_T1()) && (!is_linear()) && (!is_monotone()) && (!is_symmetric()));
	}

	// Âîçâðàùàåò ÀÍÔ ôóíêöèè
	std::vector<value_type> anf() const
	{
		std::vector<value_type> temp;
		std::vector<value_type> tria = Vector;
		for (size_t i = 0; i < Vector.size(); ++i)
		{
			temp.push_back(tria[0]);
			for (size_t k = 0; k < tria.size() - 1; ++k)
			{
				tria[k] = (tria[k]==tria[k + 1])?0:1;
			}
			tria.pop_back();
		}
		return temp;
	}
};
//
//// ïóñòü boolean_function ïðåäñòàâëÿåò èç ñåáÿ ôóíêöèþ "01110000"
//// òîãäà get_polynom âåðíåò ñòðîêó "x0 + x1 + x0x1 + x0x2 + x1x2 + x0x1x2"
std::string get_polynom(const boolean_function& rhs) {
	std::string qwe;
	std::vector<bool> Anf = rhs.anf();
	if (Anf[0] == 1) qwe += "1 + ";
	for (size_t i = 1; i < rhs.size(); ++i) {
		if (Anf[i] == 1) {
			qwe += " + ";
			size_t Num = i;
			size_t n = 0;
			while (Num > 0) {
				if (Num % 2 == 1) {
					qwe += "x";
					std::ostringstream ost;
					ost << n;
					std::string s_num = ost.str();
					qwe += s_num;
				}
				Num /= 2;
				n++;
			}
		}
	}

	return qwe;
}
//
boolean_function operator + (const boolean_function& a, const boolean_function& b)
{
	boolean_function tmp = a;
	return tmp += b;
}
//
boolean_function operator * (const boolean_function& a, const boolean_function& b)
{
	boolean_function tmp = a;
	return tmp *= b;
}
//
boolean_function operator | (const boolean_function& a, const boolean_function& b)
{
	boolean_function tmp = a;
	return tmp |= b;
}
//
bool operator != (const boolean_function& a, const boolean_function& b)
{
	return !(a == b);
}
#endif  __BOOLEAN_FUNCTION_INCLUDED__