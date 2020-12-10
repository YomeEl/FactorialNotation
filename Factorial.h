#pragma once
#include "TheLongest.h"

const int MAX_FACTORIALS_COUNT = 19;

struct Factorial
{
public:
	Factorial();
	int operator[](int i);
	void BuildFrom(TheLongest n);
	std::string AsSum();
	std::string AsVector();

private:
	int factorials[MAX_FACTORIALS_COUNT];
	int count;
	TheLongest original;
};