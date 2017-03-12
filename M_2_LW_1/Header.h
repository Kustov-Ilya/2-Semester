#pragma once

#include <exception>

class Exception
	: public std::exception
{};

class BigLen
	: public Exception
{};

class UnknownValue
	: public Exception
{};