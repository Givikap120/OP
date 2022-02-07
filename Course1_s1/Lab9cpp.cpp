#include <iostream>
#include <Windows.h>
#include <random>
#include <ctime>

using namespace std;

const int base_length = 64;

char generate_random_symbol(double chance_of_space);
bool is_starting_on_symbols(char* text, char goal[64]);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));
    cout << "Введіть рядок довжиною до "<<base_length<<" символів(для рандомної генерації залиште рядок пустим)"<<endl;
    char str[base_length];
    gets_s(str);
    if (str[0] == 0) {
        cout << "Рядок було рандомно сгенеровано: ";
        for (int i = 0; i < base_length; i++) {
            str[i] = generate_random_symbol(0.2);
            cout << str[i];
        }
        cout << endl;
    }
    cout << "Введіть шукані символи" << endl;
    char goal_char[base_length];
    for (int i = 0; i < base_length; i++) goal_char[i] = char(0);
    cin >> goal_char;
    int num_of_matching = 0;
    num_of_matching += is_starting_on_symbols(&str[0], goal_char);
    for (int i = 0; i < base_length; i++) {
        if(str[i]==' ') num_of_matching += is_starting_on_symbols(&str[i+1], goal_char);
    }
    cout << "Знайдена кількість входжень - " << num_of_matching <<endl;
    system("pause");
}

char generate_random_symbol(double chance_of_space) {
    //' ' 32
    if ((double(rand()) / RAND_MAX) < chance_of_space) return char(32);
    //a-z 97-122
    else return char(rand() % 26 + 97);
}

bool is_starting_on_symbols(char* text, char goal[64]) {
    for (int i = 0; i < base_length; i++) {
        if (goal[i] == 0) break;
        else if (goal[i] != *text) return false;
        text++;
    }
    return true;
}

