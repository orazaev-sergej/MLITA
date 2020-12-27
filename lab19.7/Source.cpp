/*Оразаев Сергей Владимирович ПС-33
19.7. Последняя цифра (2)
Найти последнюю цифру числа an, где a и n – натуральные числа (1 ≤ a, n ≤ 104).
Ввод. В единственной строке файла INPUT.TXT заданы числа a и n.
Вывод. В файл OUTPUT.TXT вывести единственное требуемое число.
Пример
Ввод
7 2
Вывод
9
*/

#include <iostream>
#include <fstream>

int main()
{
	std::ifstream fin;
	std::ofstream fout;

	fin.open("input.txt");
	if (!fin)
	{
		std::cout << "error open input.txt";
		return 1;
	}

	fout.open("output.txt");
	if (!fout)
	{
		std::cout << "error open output.txt";
		return 1;
	}

	int a, n;
	int ostatokA = 0;
	int ostatokN = 0;

	fin >> a >> n;

	int lastA = a % 10;
	int lastN = n % 10;

	if (n == 0)
		fout << 1;
	else if (lastA == 0 || lastA == 1 || lastA == 5 || lastA == 6)
		fout << lastA;
	else if (lastA == 4)
	{
		if (lastN % 2 == 1)
			fout << lastA;
		else
			fout << 6;
	}
	else if (lastA == 9)
	{
		if (lastN % 2 == 1)
			fout << lastA;
		else
			fout << 1;
	}
	else
	{
		int vivod = 1;
		ostatokN = n % 4;
		if (ostatokN == 0)
			ostatokN = 0;
		for (int i = 1; i <= ostatokN; i++)
			vivod *= lastA;
		vivod %= 10;
		fout << vivod;
	}
}
