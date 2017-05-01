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

	// ���������� ������� ������� ����� xn � ������������ dimension
	// ������ 1
	// n = 0
	// dimension = 3
	// �������� ������� "01010101"
	// ������ 2
	// n = 1
	// dimension = 4
	// �������� ������� "0011001100110011"
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

	// ������������� ���� "�� dimension ����������"
	static boolean_function zero(size_t dimension)
	{
		std::string var;
		for (size_type i = 0; i < pow(2, dimension); ++i)
			var += '0';
		return boolean_function(var);
	}

	// ������������� ������� "�� dimension ����������"
	static boolean_function one(size_t dimension)
	{
		std::string var;
		for (size_type i = 0; i < pow(2, dimension); ++i)
			var += '1';
		return boolean_function(var);
	}
	//
	static boolean_function from_anf(std::vector<value_type> v){
		boolean_function Anf(v);
		std::vector<bool> vec=Anf.anf();
		return vec;
	}

	boolean_function()
	{}
	//
	// ������ ������ �������������� ���� �� n ����������
	boolean_function(size_t n)
	{
		for (size_t i = 0; i < pow(2, n); ++i)
		{
			Vector.push_back(0);
		}
	}
	//
	//	// ������ ������ �� n ����������. �������� ����� value
	//	// ������
	//	// ����� value = 14, �.�. 0...00001110 � �������� �������
	//	// � n = 3
	//	// ����� ��� boolean_function ����� ����� x + y + xy + zx + zy + zyx
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
	//	// ����� table = "01110000"
	//	// ����� ��� boolean_function ����� ����� x + y + xy + zx + zy + zyx
	boolean_function(const std::string& table)
	{
		if (log2(table.size())-(int)log2(table.size())!=0) throw std::exception("ERROR lenght");
		for (size_t i = 0; i < table.size(); ++i)
		{
			if (table[i] == '0') Vector.push_back(0);
			else if(table[i] == '1')Vector.push_back(1);
			else throw;
		}

	}
	//
	//	// ����� table = {true, false, false, true};
	//	// ����� ��� boolean_function ����� ����� x + y + 1
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
		for(size_t n=0; n<rhs.size(); ++n)
			Vector.push_back(rhs.Vector[n]);
		return *this;
	}
	// �������� �� ������ 2
	// ���� ������ ���������� ���������� - ����������
	boolean_function& operator += (const boolean_function& rhs)
	{
		if (size() != rhs.size()){
			throw std::exception("ERROR lenght");
		}
		for (size_t n = 0; n < size(); ++n){
			if ((Vector[n] == 1 && rhs.Vector[n] == 1)||(Vector[n] == 0 && rhs.Vector[n] == 0))
				Vector[n] = 0;
			else Vector[n] = 1;
		}
		return *this;
	}
	//	// ����������
	//	// ���� ������ ���������� ���������� - ����������
	boolean_function& operator *= (const boolean_function& rhs)
	{
		if (size() != rhs.size()){
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
	// ����������
	// ���� ������ ���������� ���������� - ����������
	boolean_function& operator |= (const boolean_function& rhs)
	{
		if (size() != rhs.size()){
			throw std::exception("ERROR lenght");
		}
		for (size_t n = 0; n < size(); ++n)
		{
			if (Vector[n] == 0 && rhs.Vector[n] == 0) Vector[n] = 0;
			else Vector[n] = 1;
		}
		return *this;
	}
	// ��������� ���������
	boolean_function operator ~ ()
	{
		Vector.flip();
		return *this;
	}
	//
	// true ���� ������� �����
	//  ����� false
	bool operator == (const boolean_function& obj) const
	{
		size_t n;
		if (size() < obj.size()){
			n = size();
		}
		else{
			n = obj.size();
		}
		for (size_t i = 0; i < n; ++i){
			if (Vector[i] != obj.Vector[i]){
				return false;
			}
		}
		return true;
	}
	//
	//	// true ���� ���� ������� �������� � ������ ��� ����� rhs
	//	// false ���� �������� � ������ rhs
	//	// logic_error ���� ������ �� ��������
	bool operator >= (const boolean_function& rhs) const
	{

		if (size() != rhs.size()){
			throw std::exception("ERROR lenght");
		}
		size_type Comp = 0;
		for (size_t i = 0; i < size(); ++i)
		{
			if (static_cast<size_type>(rhs[i]) > static_cast<size_type>(Vector[i])) {
				if (Comp == 1) throw std::logic_error("ERROR: can't compare");
				if(Comp==0)Comp = 2;
			}
			else if (static_cast<size_type>(rhs[i]) > static_cast<size_type>(Vector[i])) {
				if (Comp == 2) throw std::logic_error("ERROR: can't compare");
				if (Comp == 0)Comp = 1;
			}
			else if (Comp == 0) Comp = 1;
		}
		return Comp==1;
	}
	//
	reference operator[](size_type ind)
	{
		return Vector[ind];
	}
	const_reference operator[](size_type ind) const
	{
		return Vector[ind];
	}

	reference at(size_type ind)
	{
		if (ind > size() - 1||size()==0) throw std::out_of_range("ERROR");
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
	// ����� ������� �������
	size_type size() const throw()
	{
		return Vector.size();
	}
	// ���������� ����������
	size_type dimension() const throw()
	{
		return log2(Vector.size());
	}
	//
	//	// ���������� �������� �������
	//	// ����� boolean_function ������ ������� f(x, y, z)
	//	// ����� ������� ������ f(vars[0], vars[1], vars[2])
	bool operator()(const std::vector<bool>& vars) const{
		if (vars.size() != dimension()) throw std::exception("ERROR lenght");
		size_type Num = dimension();
		size_type val = 0;
		for (auto it = vars.begin(); it != vars.end(); ++it) {
			val += (*it)*pow(2, Num);
			Num--;
		}
	}
	bool operator()(const std::initializer_list<bool> vars) const{
		if (vars.size() != dimension()) throw std::exception("ERROR lenght");
		size_type Num = dimension()-1;
		size_type val = 0;
		for (auto it = vars.begin(); it != vars.end(); ++it) {
			val += (*it)*pow(2, Num);
			Num--;
		}
		return Vector[val];
	}
	//
	//
	//	// T(x1, x2, ..., xN) - ������� �������
	//	// operator ������ ����� �������, ������� ����� ���������� G = T(fs[0], fs[1], ..., fs[N-1])
	boolean_function operator()(const std::vector<boolean_function>& fs) const{




		return *this;
	}
	boolean_function operator()(const std::initializer_list<boolean_function> vars) const{
	



		return *this;
	}
	//
	bool is_monotone() const
	{
		size_type shift = size();
		while ((shift /= 2) > 0) {
			size_t i = 0;
			while (i < shift) {
				for (size_type j = shift; j--; ++i)
					if (Vector[i] > Vector[i + shift]) {
						return false;
					}
			}
			i += shift;
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
		bool Check = false;
		std::vector<bool> Anf = anf();
		for (size_type i = 1; i < size(); ++i) {
			if (Anf[i] == 1 && log2(i) - (int)log2(i) != 0) return false;
			if (Anf[i] == 1 && log2(i) - (int)log2(i) == 0) Check = true;
		}
		return Check == true;
	}
	bool is_T1() const
	{
		return Vector[Vector.size() - 1] == 1;
	}
	bool is_T0() const
	{
		return Vector[0] == 0;
	}
	//����������� ��
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

	// ���������� ��� �������
	std::vector<value_type> anf() const
	{
		std::vector<bool> Anf, Pasc;
		Pasc = Vector;
		size_type Num = size();
		Anf.push_back(Pasc[0]);
		for (size_type i = 0; i < Num - 1; ++i) {
			size_type NumPasc = size();
			for (size_type j = 0; j < NumPasc - 1; ++j) {
				Pasc[j] = ((int)Pasc[j] + (int)Pasc[j + 1]) % 2;
			}
			Anf.push_back(Pasc[0]);
			--NumPasc;
		}
		return Anf;
	}
};
//
//// ����� boolean_function ������������ �� ���� ������� "01110000"
//// ����� get_polynom ������ ������ "x0 + x1 + x0x1 + x0x2 + x1x2 + x0x1x2"
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
