#include <iostream>
#include "Factorial.h"
#include <fstream>

bool CheckInput(std::string input)
{
	bool result = true;
	for (int i = 0; i < input.length(); i++)
	{
		result = result && (input[i] >= '0' && input[i] <= '9');
	}

	return result && input.length() < 18;
}

void UseConsole()
{
	setlocale(LC_ALL, "Russian");

	TheLongest N;
	std::string input;
	bool success = false;
	while (!success)
	{
		std::cout << "Введите число для перевода в факториальную систему счисления:\n";
		std::getline(std::cin, input);
		success = CheckInput(input);
		if (!success)
		{
			std::cout << "Некорректный ввод! Попробуйте снова.\n";
		}
	}
	N = input;

	Factorial f;
	f.BuildFrom(N);
	std::cout << f.AsVector() << std::endl << f.AsSum();

	std::cout << std::endl;
	system("pause");
}

void UseFiles()
{
	std::string ifname = "input.txt";
	std::string ofname = "output.txt";

	std::ifstream in(ifname);
	std::ofstream out(ofname);

	std::string input;
	std::getline(in, input);
	if (CheckInput(input))
	{
		TheLongest N;
		N = input;

		Factorial f;
		f.BuildFrom(N);

		out << f.AsSum();
	}
	else
	{
		out << "Некорректный ввод!";
	}
}

int main()
{
	const bool USE_FILES = false;

	if (USE_FILES)
	{
		UseFiles();
	}
	else
	{
		UseConsole();
	}

	return 0;
}