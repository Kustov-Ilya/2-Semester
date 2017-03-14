#include"Header.h"

std::ostream & operator<<(std::ostream &out, const TInteger &rhs) {
	out << rhs.Data;
	return out;
}

TInteger::TInteger()
{}

TInteger::TInteger(long long int data)
{
	checkVal(data);
	Data = data;
}

TInteger::~TInteger()
{}

bool TInteger::checkVal(long long int data)
{
	if (data > MAX_VALUE || data < MIN_VALUE) throw InvalideValue();
	return true;
}

TInteger & TInteger::operator=(const TInteger & rhs)
{
	Data = rhs.Data;
	return *this;
}

TInteger & TInteger::operator=(const long long int data)
{
	checkVal(data);
	Data = data;
	return *this;
}

bool TInteger::operator==(const TInteger & rhs)
{
	if (rhs.Data == this->Data) return true;
	return false;
}

bool TInteger::operator==(const long long int data)
{
	checkVal(data);
	if (data == this->Data) return true;
	return false;
}

TInteger & TInteger::operator+=(const TInteger & rhs)
{
	long long int Dat = Data + rhs.Data;
	checkVal(Dat);
	Data = Dat;
	return *this;
}

TInteger & TInteger::operator+=(const long long int data)
{
	checkVal(data);
	long long int Dat = Data + data;
	checkVal(Dat);
	Data = Dat;
	return *this;
}

TInteger & TInteger::operator-=(const TInteger & rhs)
{
	long long int Dat = Data - rhs.Data;
	checkVal(Dat);
	Data = Dat;
	return *this;
}

TInteger & TInteger::operator-=(const long long int data)
{
	checkVal(data);
	long long int Dat = Data - data;
	checkVal(Dat);
	Data = Dat;
	return *this;
}

TInteger & TInteger::operator/=(const TInteger & rhs)
{
	Data /= rhs.Data;
	return *this;
}

TInteger & TInteger::operator/=(const long long int data)
{
	checkVal(data);
	Data /= data;
	return *this;
}

TInteger & TInteger::operator*=(const TInteger & rhs)
{
	long long int Dat = Data * rhs.Data;
	checkVal(Dat);
	Data = Dat;
	return *this;
}

TInteger & TInteger::operator*=(const long long int data)
{
	checkVal(data);
	long long int Dat = Data * data;
	checkVal(Dat);
	Data = Dat;
	return *this;
}

TInteger & TInteger::operator%=(const TInteger & rhs)
{
	Data = Data % rhs.Data;
	return *this;
}

TInteger & TInteger::operator%=(const long long int data)
{
	checkVal(data);
	Data = Data % data;
	return *this;
}

TInteger operator+(const TInteger &a, const TInteger &b) {
	return TInteger(a) += TInteger(b);
}

TInteger operator+(const TInteger &a, const long long int data) {
	return TInteger(a) += data;
}

TInteger operator+(const long long int data, const TInteger &a) {
	return TInteger(a) += data;
}

TInteger operator-(const TInteger &a, const TInteger &b) {
	return TInteger(a) -= TInteger(b);
}

TInteger operator-(const TInteger &a, const long long int data) {
	return TInteger(a) -= data;
}

TInteger operator-(const long long int data, const TInteger &a) {
	return TInteger(a) -= data;
}

TInteger operator*(const TInteger &a, const TInteger &b) {
	return TInteger(a) *= TInteger(b);
}

TInteger operator*(const TInteger &a, const long long int data) {
	return TInteger(a) *= data;
}

TInteger operator*(const long long int data, const TInteger &a) {
	return TInteger(a) *= data;
}

TInteger operator/(const TInteger &a, const TInteger &b) {
	return TInteger(a) /= TInteger(b);
}

TInteger operator/(const TInteger &a, const long long int data) {
	return TInteger(a) /= data;
}

TInteger operator/(const long long int data, const TInteger &a) {
	return TInteger(a) /= data;
}

TInteger operator%(const TInteger &a, const TInteger &b) {
	return TInteger(a) %= TInteger(b);
}

TInteger operator%(const TInteger &a, const long long int data) {
	return TInteger(a) %= data;
}

TInteger operator%(const long long int data, const TInteger &a) {
	return TInteger(a) %= data;
}