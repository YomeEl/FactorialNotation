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
	//������ ����� left � right ����������, �������� ���������� ����, � ���������� ��� �����
	int EqualizeLengths(TheLongest& left, TheLongest& right);
	//������� ���������� ���� �� ����� a
	void RemoveLeadingZeroes(TheLongest& a);
	void Mult10();
};