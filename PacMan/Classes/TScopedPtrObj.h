#pragma once
#include"TObject.h"
class TScopedPtrObj
{
private:
	std::vector<TObject*> Ptr;
public:
	TScopedPtrObj()=default;
	~TScopedPtrObj() {
		for (auto it = Ptr.begin(); it != Ptr.end(); ++it)
			delete *it;
	}

	std::vector<TObject*>& operator*() {
		return Ptr;
	}
	std::vector<TObject*>* operator->() {
		return &Ptr;
	}
	std::vector<TObject*>* Get() {
		return &Ptr;
	}
};

