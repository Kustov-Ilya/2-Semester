#pragma once
#include"TCarnivora.h"


class TLeo :public TCarnivora{
	size_t AgeOfReprod = 3;
	size_t AgeOfDeath = 20;
public:
	TLeo()
		:TCarnivora(){}
	~TLeo() = default;
	TLeo(const std::string & name, size_t age = 0)
		: TCarnivora(name, age){}
	size_t GetAgeOfDeaht();
	size_t GetAgeOfReprod();
	virtual int Live(int ttime);
	virtual TAnimal *Born();
};