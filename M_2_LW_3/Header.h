#pragma once
#include<iostream>
#include<exception>
#define MAX_VALUE 2147483647
#define MIN_VALUE -2147483647
class InvalideValue
	:public std::exception
{
public:
	void what() {
		std::cout << "Invalide Value" << std::endl;
	}
};


class TInteger
{
	int Data;
public:
	TInteger();

	TInteger(double data);

	~TInteger();

	TInteger& operator=(const TInteger &rhs);

	TInteger& operator=(const double data);

	bool operator==(const TInteger &rhs);

	bool operator==(const double data);

	TInteger& operator+=(const TInteger &rhs);

	TInteger& operator+=(const double data);

	TInteger& operator-=(const TInteger &rhs);

	TInteger& operator-=(const double data);

	TInteger& operator/=(const TInteger &rhs);

	TInteger& operator/=(const double data);

	TInteger& operator*=(const TInteger &rhs);

	TInteger& operator*=(const double data);

	TInteger& operator%=(const TInteger &rhs);

	TInteger& operator%=(const double data);

	friend std::ostream & operator<<(std::ostream &, const TInteger &);
};

TInteger operator+(const TInteger &a, const TInteger &b);

TInteger operator+(const TInteger &a, const double data);

TInteger operator+(const double data, const TInteger &a);

TInteger operator-(const TInteger &a, const TInteger &b);

TInteger operator-(const TInteger &a, const double data);

TInteger operator-(const double data, const TInteger &a);

TInteger operator*(const TInteger &a, const TInteger &b);

TInteger operator*(const TInteger &a, const double data);

TInteger operator*(const double data, const TInteger &a);

TInteger operator/(const TInteger &a, const TInteger &b);

TInteger operator/(const TInteger &a, const double data);

TInteger operator/(const double data, const TInteger &a);

TInteger operator%(const TInteger &a, const TInteger &b);

TInteger operator%(const TInteger &a, const double data);

TInteger operator%(const double data, const TInteger &a);