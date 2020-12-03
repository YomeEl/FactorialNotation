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
	//������ ����� left � right ����������, �������� ���������� ����, � ���������� ��� �����
	int EqualizeLengths(TheLongest& left, TheLongest& right);
	//������� ���������� ���� �� ����� a
	void RemoveLeadingZeroes(TheLongest& a);
};