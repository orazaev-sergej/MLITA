/*Оразаев Сергей ПС-33
* 19.8. Сапер (3)
В некоторых клетках прямоугольной таблицы M×N (0 < M, N ≤ 10) имеются “мины” (игра Minesweeper).
Проставить во всех клетках таблицы либо символ мины ‘*’, либо число от 0 до 8,
показывающее число мин в соседних клетках по горизонтали, вертикали или диагонали.
Ввод. Первая строка файла INPUT.TXT содержит целые числа M и N через пробел, задающие число
строк и столбцов соответственно. Каждая из последующих M строк содержит ровно N символов.
Безопасные клетки обозначаются ‘+’, а мины ‘*’.
Вывод. В файл OUTPUT.TXT вывести M строк по N символов.
Пример
Ввод
3 5
++*+*
**+++
+*+**
Вывод
23*2*
**443
3*3**
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

	int n, m;
	fin >> n >> m;

	std::vector<std::vector <char>> chTable(n, std::vector<char>(m));
	std::vector<std::vector <int>> intTable(n, std::vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		std::string line;
		fin >> line;
		char element;

		for (int j = 0; j < line.size(); j++)
		{
			chTable[i][j] = line[j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (chTable[i][j] == '*')
			{
				if (i != n - 1 && chTable[i + 1][j] == '+')
					intTable[i + 1][j] += 1;
				if (i != 0 && chTable[i - 1][j] == '+')
					intTable[i - 1][j] += 1;
				if (j != m - 1 && chTable[i][j + 1] == '+')
					intTable[i][j + 1] += 1;
				if (j != 0 && chTable[i][j - 1] == '+')
					intTable[i][j - 1] += 1;
				if (i != n - 1 && j != m - 1 && chTable[i + 1][j + 1] == '+')
					intTable[i + 1][j + 1] += 1;
				if (i != 0 && j != 0 && chTable[i - 1][j - 1] == '+')
					intTable[i - 1][j - 1] += 1;
				if (i != 0 && j != m - 1 && chTable[i - 1][j + 1] == '+')
					intTable[i - 1][j + 1] += 1;
				if (i != n - 1 && j != 0 && chTable[i + 1][j - 1] == '+')
					intTable[i + 1][j - 1] += 1;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (chTable[i][j] == '+')
				chTable[i][j] = intTable[i][j] + '0';
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			fout << chTable[i][j];
		}
		fout << std::endl;
	}
}
