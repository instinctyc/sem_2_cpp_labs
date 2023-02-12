#include <iostream>
#include "Header.h"  // <<<===
#define DEFAULT_INT int  // <<<===
typedef char oneSymbol;  // <<<===

using std::cout;  // <<<===
using std::cin;  // <<<===
using std::endl;  // <<<===

int main()
{
    setlocale(LC_ALL, "ru");
    
    oneSymbol symbol; DEFAULT_INT amount;  // <<<===

    cout << "Вывод \"!\" 20 раз:" << endl;
    write1::output();

    cout << "Введите символ: ";
    cin >> symbol;
    write1::output(symbol);

    cout << "Введите символ: ";
    cin >> symbol;
    cout << "Введите количество: ";
    cin >> amount;
    write1::output(symbol, amount);
    
    write2::threeBefore();
    
    
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "Сумма нечётных позиций (int): " << arrays3::oddSum(arr, sizeof(arr) / sizeof(int)) << endl;
    double arrD[] = {1.1, 2.3, 3.5, 4.7, 5.9, 1, 1, 1, 1};
    cout << "Сумма нечётных позиций (double): " << arrays3::oddSum(arrD, sizeof(arrD) / sizeof(double)) << endl;
    float arrF[] = { 1.1, 2.3, 3.5, 4.7, 5.9, 1, 1, 1, 1 };
    cout << "Сумма нечётных позиций <указанный тип>(float): " << arrays3::oddSum<float> (arrF, sizeof(arrF)/sizeof(float)) << endl;
    cout << "Максимальное число чётной позиции <указанный тип>(int): " << unknown4::maximEven<int>(-2, -3, -5, -1, 0) << endl;

    return 0;
}
