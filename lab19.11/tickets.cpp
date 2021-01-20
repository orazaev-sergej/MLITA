/*Оразаев Сергей Владимирович ПС-33
19.11. Несчастливые билеты (2)
Автобусный билет состоит из 2N цифр (2 ≤ N ≤ 105) и может начинаться с нулей. 
Он считается несчастливым, если число, образованными цифрами первой половины номера,
отличается в большую или меньшую сторону от числа из цифр второй половины номера 
на 13. Сколько всего несчастливых номеров?
Ввод из файла INPUT.TXT.  В единственной строке задается значение N. 
Вывод в файл OUTPUT.TXT. В единственной строке выводится количество несчастливых номеров.
Пример
Ввод
2
Вывод
174
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

    int firstHalfTicket = 1;
    int secondHalfTicket = 1;

    unsigned long long numAllTickets = 1;

    for (int i = 0; i < (2 * n); i++)
    {
        numAllTickets *= 10;
    }
    --numAllTickets;

    for (int i = 0; i < n; i++)
    {
        firstHalfTicket *= 10;
    }
    --firstHalfTicket;
    secondHalfTicket = firstHalfTicket;

    int sumFristHalfTicket = 0;
    int numUnhappyTickets = 0;

    for (int i = 0; i <= firstHalfTicket; i++)
    {
        int sumSecondHalfTicket = 0;
        for (int j = 0; j <= secondHalfTicket; j++)
        {
            if (sumSecondHalfTicket - sumFristHalfTicket == 13)
            {
                numUnhappyTickets++;
                break;
            }
            sumSecondHalfTicket++;
        }
        sumFristHalfTicket++;
    }

    fout << 2 * numUnhappyTickets;
}
