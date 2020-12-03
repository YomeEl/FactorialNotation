#pragma once
#include <string>

struct TheLongest
{
public:
	TheLongest& operator=(const int& right);
	TheLongest& operator=(const std::string& right);
	TheLongest operator-(const TheLongest& right);
	bool operator>(const TheLongest& right);

private:
	std::string number = "0";
	//Делает длину left и right одинаковой, добавляя незначащие нули, и возвращает эту длину
	int EqualizeLengths(TheLongest& left, TheLongest& right);
	//Удаляет незначащие нули из числа a
	void RemoveLeadingZeroes(TheLongest& a);
};