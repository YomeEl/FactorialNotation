#include "TheLongest.h"
#include <string>

TheLongest::TheLongest()
{
	number = "0";
}

TheLongest::TheLongest(int i)
{
	number = std::to_string(i);
}

TheLongest& TheLongest::operator=(const int& right)
{
	number = std::to_string(right);
	return *this;
}

TheLongest& TheLongest::operator=(const std::string& right)
{
	number = right;
	return *this;
}

TheLongest TheLongest::operator-(const TheLongest& right)
{
	TheLongest lhs = *this, rhs = right;
	int length = EqualizeLengths(lhs, rhs);

	TheLongest result;
	result.number = "";
	bool carry = false;
	for (int i = length - 1; i >= 0; i--)
	{
		int raw = lhs.number[i] - rhs.number[i] - carry;
		carry = false;
		if (raw < 0)
		{
			raw += 10;
			carry = true;
		}
		result.number = std::to_string(raw) + result.number;
	}

	RemoveLeadingZeroes(result);
	return result;
}

bool TheLongest::operator>(const TheLongest& right)
{
	TheLongest lhs = *this, rhs = right;
	int length = EqualizeLengths(lhs, rhs);

	bool result = false;
	int ptr = 0;
	while (!result && (ptr < length))
	{
		result = number[ptr] > right.number[ptr];
		ptr++;
	}

	return result;
}

bool TheLongest::operator>(const int& right)
{
	return *this > TheLongest(right);
}

int TheLongest::EqualizeLengths(TheLongest& left, TheLongest& right)
{
	int dif = left.number.length() - right.number.length();

	if (dif < 0)
	{
		left.number.insert(0, -dif, '0');
	}
	else
	{
		right.number.insert(0, dif, '0');
	}

	return left.number.length();
}

void TheLongest::RemoveLeadingZeroes(TheLongest& a)
{
	int cnt = 0;
	while (a.number[cnt] == '0')
	{
		cnt++;
	}
	a.number.erase(0, cnt);
}