#pragma once
#include "TheLongest.h"

const int FACTORIALS_COUNT = 19;

struct Factorial
{
public:
	Factorial();
	int operator[](int i);
	void BuildFrom(TheLongest n);
	std::string AsSum();
	std::string AsVector();

private:
	int fac[FACTORIALS_COUNT];
};