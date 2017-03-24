#pragma once
#include<iostream>
#include <exception>

class Exception
	: public std::exception
{
public:
	const char* what() const =0;
};

class BigLen
	: public Exception
{
public:
	const char* what() const {
		return "BigLen";
	}
};

class UnknownValue
	: public Exception
{
public:
	const char* what() const {
		return "UnknownValue";
	}
};

class UnknownType
	:public Exception
{
	const char* what() const {
		return "UnknownType";
	}
};