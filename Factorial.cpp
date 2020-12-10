#include "Factorial.h"

Factorial::Factorial()
{
	for (int i = 0; i < MAX_FACTORIALS_COUNT; i++)
	{
		factorials[i] = 0;
	}
	count = 0;
}

int Factorial::operator[](int i)
{
	return factorials[i];
}

void Factorial::BuildFrom(TheLongest n)
{
	original = n;
	TheLongest base[MAX_FACTORIALS_COUNT];
	base[0] = 1;
	int last = 1;
	bool flag = true;
	while (flag)
	{
		base[last] = base[last - 1] * (last + 1);
		flag = base[last] <= n;
		last += flag;
	}
	last--;

	count = last + 1;
	while (last >= 0)
	{
		while (n >= base[last])
		{
			n = n - base[last];
			factorials[last]++;
		}
		last--;
	}
}

std::string Factorial::AsSum()
{
	std::string result = original.ToString() + " = ";
	for (int i = count - 1; i >= 0; i--)
	{
		if (factorials[i] > 0)
		{
			result += std::to_string(factorials[i]) + " * " + std::to_string(i + 1) + "! + ";
		}
	}
	if (result.length() > 4)
	{
		result.erase(result.length() - 3, 3);
	}
	else
	{
		result += "0";
	}

	return result;
}

std::string Factorial::AsVector()
{
	if (count == 0)
	{
		return "(0)";
	}

	std::string result = original.ToString() + " = (";
	for (int i = count - 1; i >= 0; i--)
	{
		result += std::to_string(factorials[i]) + ", ";
	}
	result.erase(result.length() - 1, 1);
	result[result.length() - 1] = ')';

	return result;
}