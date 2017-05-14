#include "TScopedPtrObj.h"



TScopedPtrObj::TScopedPtrObj()
{
}


TScopedPtrObj::~TScopedPtrObj()
{
	delete Ptr;
}

void TScopedPtrObj::operator=(TObject * ptr)
{
	delete Ptr;
	Ptr = ptr;
}


