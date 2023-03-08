#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <filesystem>

namespace fs = std::filesystem;

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    ifstream file;
    file.open("C:\\Всё\\ВолГУ\\2 семестр\\Информатика и программирование\\lab_cpp_2\\Mall_Customers.csv");
    if (file.is_open() == false)
    {
        cout << "Ошибка открытия файла" << endl;
        return 2;
    }
    int max_str_nums = 0;

    string cur_str = "";
    char del = '\n';
    getline(file, cur_str, del);

    int older_than_40 = 0, nstr_block = 0;
    string str_block = "";

    int users_male_count = 0, users_female_count = 0;
    double a_s_r_male = 0, a_s_r_female = 0;  // averge_spending_rating
    bool isFemale = false, isMale = false;

    while (getline(file, cur_str, del))
    {
        max_str_nums++;  // счёт сколько строк всего
        nstr_block = 0;  // номер блока
        isFemale = false;
        isMale = false;
        for (int i = 0; i < cur_str.length(); i++)
        {
            if (cur_str[i] == ',')
            {
                if ((nstr_block % 5 == 2) && (stoi(str_block)>40))
                {
                    older_than_40++;
                }
                if ((nstr_block%5==1) && (str_block == "Female"))
                {
                    isFemale = true;
                }
                if ((nstr_block % 5 == 1) && (str_block == "Male"))
                {
                    isMale = true;
                }
                str_block = "";
                nstr_block++;
                continue;
            }
            str_block += cur_str[i];
            if ((nstr_block % 5 == 4) && (i+1 == cur_str.length()))
            {
                if (isMale)
                {
                    a_s_r_male += stod(str_block);
                    users_male_count++;
                }
                if (isFemale)
                {
                    a_s_r_female += stod(str_block);
                    users_female_count++;
                }
            }
        }
    }

    cout << endl << "Число посетителей возрастом более 40 лет - " << older_than_40 << endl;
    cout << "Средний рейтинг трат мужчин - " << left << fixed << setprecision(1) <<(double)a_s_r_male / users_male_count << endl;
    cout << "Средний рейтинг трат женщин - " << left << fixed << setprecision(1) << (double)a_s_r_female / users_female_count << endl;
    file.close();
    file.open("C:\\Всё\\ВолГУ\\2 семестр\\Информатика и программирование\\lab_cpp_2\\Mall_Customers.csv");
    getline(file, cur_str, del);
    
    int *str_nums = new int[max_str_nums];
    for (int x = 0; x < max_str_nums; x++)
    {
        str_nums[x] = 0;
    }
    bool spend_r, income_r;

    int str_num = 0;
    str_block = "";
    while (getline(file, cur_str, del))
    {
        nstr_block = 0;
        spend_r = false;
        income_r = false;
        isFemale = false;
        for (int i = 0; i < cur_str.length(); i++)
        {
            if ((nstr_block % 5 == 4) && (i + 1 == cur_str.length()))
            {
                str_block += cur_str[i];
                if (stoi(str_block) < 50)
                {
                    spend_r = true;
                }
                str_block = "";
                continue;
            }
            if (cur_str[i] == ',')
            {
                if ((nstr_block % 5 == 1) && (str_block == "Female"))
                {
                    isFemale = true;
                }
                if ((nstr_block % 5 == 3) && (stoi(str_block) > 75))
                {
                    income_r = true;
                }
                str_block = "";
                nstr_block++;
                continue;
            }
            str_block += cur_str[i];
        }
        if (income_r && spend_r && isFemale)
        {
            str_nums[str_num] = 1;
        }
        str_num++;
    }
    
    file.close();
    file.open("C:\\Всё\\ВолГУ\\2 семестр\\Информатика и программирование\\lab_cpp_2\\Mall_Customers.csv");
    getline(file, cur_str, del);

    string block;

    ofstream outfile("female_statistics.txt");

    outfile << "ID     Genre  Age    Income Spending Score\n";

    for (int i = 0; getline(file, cur_str, del); i++)
    {
        if (str_nums[i] == 1)
        {
            block = "";
            for (int j = 0; j < cur_str.length(); j++)
            {
                if (cur_str[j] != ',')
                {
                    block += cur_str[j];
                }
                else //(cur_str[j] == ',')
                {
                    outfile << left << setw(6) << block << ' ';
                    block = "";
                }
                if (j + 1 == cur_str.length())
                {
                    outfile << left << setw(6) << block << '\n';
                }
            }
        }
    }

    file.close();
    outfile.close();

    cout << endl << "Файлы каталога с проектом:" << endl;
    for (const auto& entry : fs::directory_iterator(".")) {
        std::cout << entry.path().filename() << std::endl;
    }
    fs::create_directory("new_directory");
    fs::copy(fs::current_path() / "female_statistics.txt", fs::current_path() / "new_directory/female_statistics.txt");
    fs::remove(fs::current_path() / "female_statistics.txt");

    return 0;
}
