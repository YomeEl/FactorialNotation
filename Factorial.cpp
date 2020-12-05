#include "Factorial.h"

Factorial::Factorial()
{
	for (int i = 0; i < MAX_FACTORIALS_COUNT; i++)
	{
		fac[i] = 0;
	}
	count = 0;
}

int Factorial::operator[](int i)
{
	return fac[i];
}

void Factorial::BuildFrom(TheLongest n)
{
	TheLongest factorials[MAX_FACTORIALS_COUNT];
	factorials[0] = 1;
	int last = 1;
	bool flag = true;
	while (flag)
	{
		factorials[last] = factorials[last - 1] * (last + 1);
		flag = factorials[last] <= n;
		last += flag;
	}
	last--;

	count = last + 1;
	while (last >= 0)
	{
		while (n >= factorials[last])
		{
			n = n - factorials[last];
			fac[last]++;
		}
		last--;
	}
}

std::string Factorial::AsSum()
{
	std::string result = "";
	for (int i = 0; i < count; i++)
	{
		if (fac[i] > 0)
		{
			result += std::to_string(fac[i]) + " * " + std::to_string(i + 1) + "! + ";
		}
	}
	if (result.length() > 0)
	{
		result.erase(result.length() - 3, 3);
	}
	else
	{
		result = "0";
	}

	return result;
}

std::string Factorial::AsVector()
{
	int cnt = count;

	if (cnt == 0)
	{
		return "(0)";
	}

	std::string result = "(";
	for (int i = 0; i < cnt; i++)
	{
		result += std::to_string(fac[i]) + ", ";
	}
	result.erase(result.length() - 1, 1);
	result[result.length() - 1] = ')';

	return result;
}