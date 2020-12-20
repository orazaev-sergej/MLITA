/* Оразаев Сергей Владимирович ПС-33
19.1. Кроссворд 2 (3)
Кроссворд размещен в квадрате. Строки и столбцы квадрата нумеруются снизу вверх и слева направо, начиная с 1.
Поля для слов располагаются горизонтально либо вертикально и задаются путем указания координат начальной и конечной клеток.
Какая-либо сортировка при задании полей отсутствует. Два пересекающихся слова могут располагаться как на одной горизонтали
либо вертикали, так и перпендикулярно друг другу. Подсчитать количество занятых клеток кроссворда.

Ввод. В первой строке файла INPUT.TXT заданы размер квадрата M (1 ≤ M ≤ 50) и количество слов кроссворда N (1 ≤ N ≤ 20). 
В следующих N строках указываются координаты (ai, bi) начальной и конечной клеток очередного слова (1 ≤ ai, bi ≤ M).
Вывод. В единственной строке выходного файла OUTPUT.TXT должно содержаться общее количество занятых клеток кроссворда.
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

    int n, m;
    fin >> n >> m;

    int sizeMassive = m * 4;

    std::vector<int> cells;

    for (int i = 0; i < sizeMassive; i++)
    {
        int element;
        fin >> element;
        cells.push_back(element);
    }

    std::vector<int> busyCells;

    for (int i = 0; i < cells.size(); i += 4)
    {
        int x1 = cells[i];
        int y1 = cells[i + 1];
        int x2 = cells[i + 2];
        int y2 = cells[i + 3];

        int differenceX = abs(x1 - x2);
        int differenceY = abs(y1 - y2);

        if (differenceX == 0)
        {
            int minY;
            if (y1 < y2)
                minY = y1;
            else
                minY = y2;

            int maxY = minY + differenceY;

            for(; minY <= maxY; minY++)
            {
                busyCells.push_back(x1);
                busyCells.push_back(minY);
            }
        }
        else
        {
            int minX;
            if (x1 < x2)
                minX = x1;
            else
                minX = x2;

            int maxX = minX + differenceX;

            for (; minX <= maxX; minX++)
            {
                busyCells.push_back(minX);
                busyCells.push_back(y1);
            }
        }
    }
    //запишем в новый вектор pair
    std::vector<std::pair <int, int>> uniqueCells;
    for (int i = 0; i < busyCells.size(); i += 2)
    {
        uniqueCells.push_back(std::make_pair(busyCells[i], busyCells[i + 1]));
    }

    //находим и удаляем повторяющиеся элементы
    std::sort(uniqueCells.begin(), uniqueCells.end());

    uniqueCells.erase(std::unique(uniqueCells.begin(), uniqueCells.end()), uniqueCells.end());

    //выводим кол-во уникальных элементов
    fout << uniqueCells.size();
}
