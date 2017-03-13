#pragma once
#include<iostream>
#include <exception>

class Exception
	: public std::exception
{
public:
	virtual void what()=0;
};

class BigLen
	: public Exception
{
public:
	void what() {
		std::cout << "BigLen" << std::endl;
	}
};

class UnknownValue
	: public Exception
{
public:
	void what() {
		std::cout << "UnknownValue" << std::endl;
	}
};
