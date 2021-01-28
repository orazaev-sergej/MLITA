/*Оразаев Сергей ПС-33
 19.6. Змейка (3)
Змей Горыныч убедительно просит расположить N2 чисел от 1 до N2 в квадрате змейкой.
Ввод. В единственной строке файла INPUT.TXT задано число N (1 ≤  N ≤ 50).
Вывод. Файл OUTPUT.TXT содержит N2  чисел по N  чисел в строке в форме змейки.
Пример
Ввод
4
Вывод
1 2 6 7
3 5 8 13
4 9 12 14
10 11 15 16
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

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

	int num = 2;
	int count = 1;
	int i = 0, j = 1;
	square[0][0] = 1;

	for (int count = 1; count < n; count++)
	{
		for (j = count, i = 0; i <= count; i++, j--)
		{
			square[i][j] = num;
			num++;
		}
		if (count < n - 1)
		{
			count++;
			for (i = count, j = 0; j <= count; i--, j++)
			{
				square[i][j] = num;
				num++;
			}
		}
	}

	for (count = 1; count < n; count++)
	{
		for (i = count, j = n - 1; j >= count; i++, j--)
		{
			square[i][j] = num;
			num++;
		}
		if (count < n)
		{
			count++;
			for (i = n - 1, j = count; i >= count; i--, j++)
			{
				square[i][j] = num;
				num++;
			}
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
}
