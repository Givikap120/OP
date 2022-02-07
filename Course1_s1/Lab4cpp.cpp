#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Ukrainian");
    unsigned long n_current = 1, n_prev = 0, needed_num, temp;
    cout << "Введiть номер числа Фiбоначi: ";
    cin >> needed_num;
    if (needed_num == 0) cout << n_prev <<endl;
    else {
        for (int i = 1; i < needed_num; i++) {
            temp = n_current + n_prev;
            n_prev = n_current;
            n_current = temp;
        }
        cout << n_current <<endl;
    }
    system("pause");
}
