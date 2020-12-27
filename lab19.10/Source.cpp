/*19.10. Магазин (2)
В магазине штучных изделий продают флешки, бляшки, чашки и другие товары.
В налоговой инспекции оказались два списка. В первом указано количество проданных 
товаров каждого вида, а во втором - цены каждого вида товаров. Порядок товаров в 
списках разный. Добрый и злой инспекторы для начисления налогов желают определить
наименьшую и наибольшую возможную выручку от всех проданных товаров.
Ввод. Первая строка файла INPUT.TXT содержит число видов товаров N (1 ≤ N ≤ 50). 
Во второй строке задаются через пробел целые положительные числа X1, X2,…, XN, 
определяющие количество каждого вида товара (1 ≤ Xi ≤ 200). 
В третьей строке задаются через пробел целые положительные числа Y1, Y2,…, YN , 
определяющие цены каждого вида товара (1 ≤ Yi ≤ 200). Данные по одному и тому же 
товару в общем случае содержатся в элементах списков X и Y с разными номерами.
Вывод. Результат в файле OUTPUT.TXT в виде двух целых чисел через пробел.
Пример
Ввод
2
5 1
4 7
Вывод
27 39
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

std::vector<int> getFin(int n, std::ifstream& fin);
int addPrice(std::vector<int>& numProd, std::vector<int>& priceProd, int n);

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

    std::vector<int> numProd, priceProd;
    numProd = getFin(n, fin);
    priceProd = getFin(n, fin);

    sort(numProd.begin(), numProd.end());
    sort(priceProd.begin(), priceProd.end());
       
    int maxPrice = addPrice(numProd, priceProd, n);

    sort(priceProd.begin(), priceProd.end(), std::greater<int>());

    int minPrice = addPrice(numProd, priceProd, n);

    fout << minPrice;
    fout << ' ';
    fout << maxPrice;
}

std::vector<int> getFin(int n, std::ifstream& fin)
{
    std::vector<int> vectorFin;

    for (int i = 0; i < n; i++)
    {
        int getFin;
        fin >> getFin;
        vectorFin.push_back(getFin);
    }

    return vectorFin;
}
int addPrice(std::vector<int>& numProd, std::vector<int>& priceProd, int n)
{
    int sumPrice = 0;

    for (int i = 0; i < n; i++)
    {
        sumPrice += numProd[i] * priceProd[i];
    }

    return sumPrice;
}
