#include "TVector.h"


TVector::~TVector()
{
	delete[] Vec;
}


TVector::TVector()
{
	Size = 0;
	Vec = nullptr;
}


TVector::TVector(double* vec, int size)
{
	Size = size;
	Vec = new double[size];
	
	memcpy(Vec, vec, size*sizeof(double));
}


double TVector::operator[](size_t nom)
{
	if (nom > Size) return 0;
	return Vec[nom];
}


double *TVector:: operator=(const TVector& vec)
{
	if (Vec != nullptr) delete[] Vec;
	Vec = new double[vec.Size];
	Size = vec.Size;
	memcpy(Vec, vec.Vec, Size*sizeof(double));

	return Vec;
}


double * operator+(const TVector& a, const TVector& b)
{
	if (a.Vec == nullptr)
		if (b.Vec == nullptr) return 0;
		else return b.Vec;

	if (b.Vec == nullptr)
		return a.Vec;

	for (int i = 0; i < a.Size; i++)
	{
		a.Vec[i] = a.Vec[i] + b.Vec[i];
	}
	return a.Vec;
}


void TVector::Print(){
	for (int i = 0; i < Size; i++)
	{
		std::cout << Vec[i] << ' ';
	}
	std::cout << std::endl;
}
