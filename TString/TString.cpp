#include "TString.h"


TString::~TString()
{
	delete[] Data;
}


TString::TString()
{
	Data = new char[1];
	Data[0] = '\0';
}


TString::TString(const TString& rhs)
{
	size_t Len = rhs.Size();
	Data = new char[Len + 1];
	for (int i = 0; i < Len + 1; i++)
	{
		Data[i] = rhs.Data[i];
	}
}


TString::TString(const char * data)
{
	size_t Len = 0;
	while (data[Len] != '\0')
	{
		Len++;
	}
	Data = new char[Len + 1];
	for (int i = 0; i < Len + 1; i++)
	{
		Data[i] = data[i];
	}
}


TString& TString::operator =(const TString& rhs)
{
	if (rhs == *this) return *this;
	if(Data != nullptr) delete[] Data;
	size_t Len = rhs.Size();
	Data = new char[Len + 1];
	for (int i = 0; i < Len + 1; i++)
	{
		Data[i] = rhs.Data[i];
	}
	return *this;
}


TString& TString::operator +=(const TString& rhs)
{
	size_t Len1= Size();
	size_t Len2 = rhs.Size();
	size_t Len = Len1 + Len2;
	char * Data1 = new char[Len + 1];
	for (int i = 0; i < Len1; i++)
	{
		Data1[i] = Data[i];
	}
	for (int i = 0; i < Len2 + 1; i++)
	{
		Data1[Len1 + i] = rhs.Data[i];
	}
	delete[] Data;
	Data = Data1;
	return *this;
}


bool TString::operator ==(const TString& rhs) const
{
	size_t Len = Size();
	if (Len != rhs.Size()) return false;
	for (int i = 0; i < Len; i++)
	{
		if (Data[i] != rhs.Data[i]) return false;
	}
	return true;
}


bool TString::operator <(const TString& rhs) const
{
	int length;
	if (rhs.Size() > Size())
		length = rhs.Size();
	else
		length = Size();
	for (int i = 0; i<length; i++){
		if (Data[i] == rhs.Data[i]) continue;
		if (Data[i]<rhs.Data[i]) return true;
		if (Data[i]>rhs.Data[i]) return false;
	}
	return false;
}


size_t TString::Find(const TString& substr) const{
	int Len1 = Size();
	int Len2 = substr.Size();
	if (Len2 > Len1) return -1;
	int chek, t = 0, i = 0;
	for (i; i < Len1 - Len2 + 1; i++){
		t = i;
		for (int j = 0; j < Len2; j++)
		{
			if (Data[t] == substr.Data[j])
			{
				t++;
				chek = 1;
				continue;
			}
			else
			{
				chek = 0;
				break;
			}
		}
		if (chek == 1) return i;
	}
	return -1;
}


void TString::Replace(char oldSymbol, char newSymbol)
{
	for (int i = 0; i < Size(); i++)
		if (Data[i] == oldSymbol)
		{
			Data[i] = newSymbol;
		}
}


size_t TString::Size() const
{
	size_t i = 0;
	for (i; Data[i]; i++);
	return i;
}


bool TString::Empty() const
{
	if (Data[0]==NULL) return true;
	return false;
}


char TString::operator[](size_t index) const
{
	return Data[index];
}


char& TString::operator[](size_t index)
{
	return Data[index];
}


void TString::RTrim(char symbol)
{
	int Len = Size();
	int t = 0;
	if (Data[Len - 1 - t] == symbol)
	{
		t++;
	}
	char* Data1 = new char[Len - t + 1];
	for (int i = 0; i < Len - t; i++)
	{
		Data1[i] = Data[i];
	}
	Data1[Len - t] = '\0';
	delete[] Data;
	Data = Data1;
}


void TString::LTrim(char symbol)
{
	int Len = Size();
	int t = 0;
	if (Data[t] == symbol)
	{
		t++;
	}
	char * Data1 = new char[Len - t + 1];
	for (int i = 0; i < Len - t + 1; i++)
	{
		Data1[i] = Data[i + t];
	}
	delete[] Data;
	Data = Data1;
}


TString operator+(const TString & a, const TString & b)
{
	return (TString(a) += TString(b));
}


bool operator!=(const TString & a, const TString & b)
{
	if (a == b) return false;
	return true;
}


bool operator>(const TString & a, const TString & b)
{
	if (a == b) return false;
	if (a < b) return false;
	return true;
}


std::ostream & operator<<(std::ostream &out, const TString &str)
{
	out << str.Data;
	return out;
}
