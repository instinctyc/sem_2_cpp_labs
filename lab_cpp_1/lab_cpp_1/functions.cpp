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
    cout << "����� ��������� ������� 10 ���." << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << " " << symbol;
    }
    cout << endl << endl;
}

void write1::output(char symbol, int amount)
{
    cout << "����� ������� " << symbol << " " << amount << " ���." << endl;
    for (int i = 0; i < amount; i++)
    {
        cout << " " << symbol;
    }
    cout << endl;
}

void write2::threeBefore(char symbol, int amount)
{
    cout << "---------------------------------" << endl
        << "�������, ��� � ���������� 3, �� � ����������� �� ���������." << endl;
    cout << "����� \"!\" 20 ���:" << endl;
    for (int i = 0; i < 20; i++)
    {
        cout << " !";
    }
    cout << endl << endl;

    cout << "����� ��������� ������� 10 ���." << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << " " << symbol;
    }
    cout << endl << endl;

    cout << "����� ��������� ������� �������� ���-�� ���." << endl;
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
