#include"Header.h"

std::ostream & operator<<(std::ostream &out, const TInteger &rhs) {
	out << rhs.Data;
	return out;
}

TInteger::TInteger()
{}

TInteger::TInteger(double data)
{
	if (data > MAX_VALUE || data < MIN_VALUE) throw InvalideValue();
	Data = data;
}

TInteger::~TInteger()
{}

TInteger & TInteger::operator=(const TInteger & rhs)
{
	Data = rhs.Data;
	return *this;
}

TInteger & TInteger::operator=(const double data)
{
	if (data > MAX_VALUE || data < MIN_VALUE) throw InvalideValue();
	Data = data;
	return *this;
}

bool TInteger::operator==(const TInteger & rhs)
{
	if (rhs.Data == this->Data) return true;
	return false;
}

bool TInteger::operator==(const double data)
{
	if (data > MAX_VALUE || data < MIN_VALUE) throw InvalideValue();
	if (data == this->Data) return true;
	return false;
}

TInteger & TInteger::operator+=(const TInteger & rhs)
{
	double Dat = Data + rhs.Data;
	if (Dat > MAX_VALUE || Dat < MIN_VALUE) throw InvalideValue();
	Data = Dat;
	return *this;
}

TInteger & TInteger::operator+=(const double data)
{
	if (data > MAX_VALUE || data < MIN_VALUE) throw InvalideValue();
	double Dat = Data + data;
	if (Dat > MAX_VALUE || Dat < MIN_VALUE) throw InvalideValue();
	Data = Dat;
	return *this;
}

TInteger & TInteger::operator-=(const TInteger & rhs)
{
	double Dat = Data - rhs.Data;
	if (Dat > MAX_VALUE || Dat < MIN_VALUE) throw InvalideValue();
	Data = Dat;
	return *this;
}

TInteger & TInteger::operator-=(const double data)
{
	if (data > MAX_VALUE || data < MIN_VALUE) throw InvalideValue();
	double Dat = Data - data;
	if (Dat > MAX_VALUE || Dat < MIN_VALUE) throw InvalideValue();
	Data = Dat;
	return *this;
}

TInteger & TInteger::operator/=(const TInteger & rhs)
{
	Data /= rhs.Data;
	return *this;
}

TInteger & TInteger::operator/=(const double data)
{
	if (data > MAX_VALUE || data < MIN_VALUE) throw InvalideValue();
	Data /= data;
	return *this;
}

TInteger & TInteger::operator*=(const TInteger & rhs)
{
	double Dat = Data * rhs.Data;
	if (Dat > MAX_VALUE || Dat < MIN_VALUE) throw InvalideValue();
	Data = Dat;
	return *this;
}

TInteger & TInteger::operator*=(const double data)
{
	if (data > MAX_VALUE || data < MIN_VALUE) throw InvalideValue();
	double Dat = Data * data;
	if (Dat > MAX_VALUE || Dat < MIN_VALUE) throw InvalideValue();
	Data = Dat;
	return *this;
}

TInteger & TInteger::operator%=(const TInteger & rhs)
{
	double Dat = Data % rhs.Data;
	if (Dat > MAX_VALUE || Dat < MIN_VALUE) throw InvalideValue();
	Data = Dat;
	return *this;
}

TInteger & TInteger::operator%=(const double data)
{
	if (data > MAX_VALUE || data < MIN_VALUE) throw InvalideValue();
	int data1 = static_cast<int>(data);
	Data = Data % data1;
	return *this;
}

TInteger operator+(const TInteger &a, const TInteger &b) {
	return TInteger(a) += TInteger(b);
}

TInteger operator+(const TInteger &a, const double data) {
	return TInteger(a) += data;
}

TInteger operator+(const double data, const TInteger &a) {
	return TInteger(a) += data;
}

TInteger operator-(const TInteger &a, const TInteger &b) {
	return TInteger(a) -= TInteger(b);
}

TInteger operator-(const TInteger &a, const double data) {
	return TInteger(a) -= data;
}

TInteger operator-(const double data, const TInteger &a) {
	return TInteger(a) -= data;
}

TInteger operator*(const TInteger &a, const TInteger &b) {
	return TInteger(a) *= TInteger(b);
}

TInteger operator*(const TInteger &a, const double data) {
	return TInteger(a) *= data;
}

TInteger operator*(const double data, const TInteger &a) {
	return TInteger(a) *= data;
}

TInteger operator/(const TInteger &a, const TInteger &b) {
	return TInteger(a) /= TInteger(b);
}

TInteger operator/(const TInteger &a, const double data) {
	return TInteger(a) /= data;
}

TInteger operator/(const double data, const TInteger &a) {
	return TInteger(a) /= data;
}

TInteger operator%(const TInteger &a, const TInteger &b) {
	return TInteger(a) %= TInteger(b);
}

TInteger operator%(const TInteger &a, const double data) {
	return TInteger(a) %= data;
}

TInteger operator%(const double data, const TInteger &a) {
	return TInteger(a) %= data;
}