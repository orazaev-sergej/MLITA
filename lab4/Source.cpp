/*Оразаев Сергей Владимирович ПС-33
Расположить N2  чисел от 1 до N2 в квадрате по спирали.
Ввод.В единственной строке файла INPUT.TXT задано число N(1 ≤  N ≤ 50).
Вывод.Выходной файл OUTPUT.TXT содержит N2  чисел  по N  чисел по спирали.
Пример
Ввод
4
Вывод
1 2 3 4
12 13 14 5
11 16 15 6
10 9 8 7
*/
#include <iostream>
#include <fstream>
#include <vector>

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

	//создание вектора на n строк по n элементов
	std::vector<std::vector <int>> square(n, std::vector<int>(n));

	int num = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n - i; j++)
		{
			square[i][j] = num;
			num++;
		}
		for (int j = i + 1; j < n - i; j++)
		{
			square[j][n - 1 - i] = num;
			num++;
		}
		for (int j = n - 2 - i; j >= i; j--)
		{
			square[n - 1 - i][j] = num;
			num++;
		}
		for (int j = n - 2 - i; j > i; j--)
		{
			square[j][i] = num;
			num++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fout << square[i][j] << ' ';
		}
		fout << std::endl;
	}
	

	return 0;
}
