/*19.5. Квадраты (2)
Составить программу, которая будет находить, на сколько квадратов можно разрезать
данный прямоугольник, если от него каждый раз отрезается квадрат максимально большой площади.
Стороны прямоугольника и квадратов выражены натуральными числами.

Ввод. В первой строке файла INPUT.TXT стороны прямоугольника A и B (1 ≤  A, B ≤ 1018).
Вывод. Выходной файл OUTPUT.TXT содержит одно число - количество квадратов.
Ограничение. Время работы на одном тесте не более 1 сек.
Пример 
Ввод
6 4
Вывод
3
*/

#include<iostream>
#include<fstream>

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

	unsigned long long int a, b;
	int numSquares = 1;
	fin >> a >> b;

	while (a != b)
	{
		if (a < b)
			b -= a;

		else if (a > b)
			a -= b;

		numSquares++;
	}

	fout << numSquares;

	return 0;
}
