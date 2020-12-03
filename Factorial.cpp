#include "Factorial.h"

Factorial::Factorial()
{
	for (int i = 0; i < FACTORIALS_COUNT; i++)
	{
		fac[i] = 0;
	}
}

int Factorial::operator[](int i)
{
	return fac[i];
}

void Factorial::BuildFrom(TheLongest n)
{
	throw new std::exception("BuldFrom is not implemented yet!");
}

std::string Factorial::AsSum()
{
	std::string result = "";
	for (int i = 0; i < FACTORIALS_COUNT; i++)
	{
		result += std::to_string(fac[i]) + " * " + std::to_string(i) + "! + ";
	}
	result.erase(result.length() - 3, 3);

	return result;
}

std::string Factorial::AsVector()
{
	std::string result = "(";
	for (int i = 0; i < FACTORIALS_COUNT; i++)
	{
		result += std::to_string(fac[i]) + ", ";
	}
	result.erase(result.length() - 1, 1);
	result[result.length() - 1] = ')';

	return result;
}