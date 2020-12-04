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
	bool operator>(const TheLongest& right);
	bool operator>(const int& right);

private:
	std::string number;
	//Делает длину left и right одинаковой, добавляя незначащие нули, и возвращает эту длину
	int EqualizeLengths(TheLongest& left, TheLongest& right);
	//Удаляет незначащие нули из числа a
	void RemoveLeadingZeroes(TheLongest& a);
	void Mult10();
};