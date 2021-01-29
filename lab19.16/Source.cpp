/*Оразаев Сергей ПС-33
19.16. Простые числа (3)
Найти сумму простых чисел, расположенных между N и K (0 < N ≤ K ≤ 4×106), включая эти числа.
Ввод. В первой строке файла INPUT.TXT содержатся через пробел натуральные числа N и K.
Вывод. Вывести в файл OUTPUT.TXT одно число - сумму простых чисел, расположенных между N и K.
Пример
Ввод
1 5
Вывод
10
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

	int n, k;
	fin >> n >> k;

	int size = k - n + 1;

	bool* massiv = new bool;
	unsigned long int i = 0, j = 0;

	if (n < 2)
		n = 2;

	for (j = n; j <= k; j++) 
		massiv[j] = true;

	j = 2;

	while (j * j <= k)
	{
		i = j * j;
		if (massiv[j])
			while (i <= k)
			{
				massiv[i] = false;
				i = i + j;
			}
		j = j + 1;
	}
	int sum = 0;
	for (j = n; j <= k; j++)
	{
		if (massiv[j] == true)
			sum += j;
	}
	fout << sum;
	return 0;
}
