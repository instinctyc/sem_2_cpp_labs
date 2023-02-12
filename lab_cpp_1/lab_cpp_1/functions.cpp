#include "Header.h"
#include <iostream>

using namespace std;

void write1::output()
{
    for (int i = 0; i < 20; i++)
    {
        cout << " !";
    }
    cout << endl << endl;
}

void write1::output(char symbol)
{
    cout << "Вывод заданного символа 10 раз." << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << " " << symbol;
    }
    cout << endl << endl;
}

void write1::output(char symbol, int amount)
{
    cout << "Вывод символа " << symbol << " " << amount << " раз." << endl;
    for (int i = 0; i < amount; i++)
    {
        cout << " " << symbol;
    }
    cout << endl;
}

void write2::threeBefore(char symbol, int amount)
{
    cout << "---------------------------------" << endl
        << "Функция, что и предыдущие 3, но с параметрами по умолчанию." << endl;
    cout << "Вывод \"!\" 20 раз:" << endl;
    for (int i = 0; i < 20; i++)
    {
        cout << " !";
    }
    cout << endl << endl;

    cout << "Вывод заданного символа 10 раз." << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << " " << symbol;
    }
    cout << endl << endl;

    cout << "Вывод заданного символа заданное кол-во раз." << endl;
    for (int i = 0; i < amount; i++)
    {
        cout << " " << symbol;
    }
    cout << endl << endl;
}

int arrays3::oddSum(int massiv[], int SIZE)
{
    int sum = 0;
    for (int i = 0; i < SIZE; i += 2)
    {
        sum += massiv[i];
    }
    return sum;
}

double arrays3::oddSum(double massiv[], int SIZE)
{
    double sum = 0;
    for (int i = 0; i < SIZE; i += 2)
    {
        sum += massiv[i];
    }
    return sum;
}
