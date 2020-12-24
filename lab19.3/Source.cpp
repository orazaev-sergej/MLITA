/*Оразаев Сергей Владимирович
19.2. Домино (3)
 Найти количество вариантов покрытия прямоугольника 2×N прямоугольниками 2×1. 
 Покрытия, которые преобразуются друг в друга симметриями, считать различными.
Ввод. В единственной строке входного файла INPUT.TXT задано значение N (1 ≤ N ≤ 20).
Вывод. В единственной строке выходного файла OUTPUT.TXT должно содержаться количество вариантов
покрытия прямоугольника.
Пример
Ввод
5
Вывод
8 
*/

#include <iostream>
#include <fstream>

int fib(int num)
{
	if (num == 1)
		return 1;
	if (num == 0)
		return 0;
	return fib(num - 1) + fib(num - 2);
}

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

	int n;
	fin >> n;

	int numDominoes;
	numDominoes =  fib(n + 1);

	fout << numDominoes;

	return 0;
}
