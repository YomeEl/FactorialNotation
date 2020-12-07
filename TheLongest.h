#pragma once
#include <string>

struct TheLongest
{
public:
	TheLongest();
	TheLongest(int i);

	TheLongest& operator=(const int& right);
	TheLongest& operator=(const std::string& right);
	TheLongest operator-(const TheLongest& right);
	TheLongest operator+(const TheLongest& right);
	TheLongest operator*(const TheLongest& right);
	bool operator==(const TheLongest& right);
	bool operator>(const TheLongest& right);
	bool operator>(const int& right);
	bool operator<(const TheLongest& right);
	bool operator>=(const TheLongest& right);
	bool operator<=(const TheLongest& right);

	std::string ToString();

private:
	std::string number;

	void RemoveLeadingZeroes(TheLongest& a);
	void Mult10();
};