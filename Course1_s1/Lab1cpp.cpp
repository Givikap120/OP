#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Ukrainian");
    int k, h, m;
    cin >> k;
    h = (k) / 3600;
    m = (k - h * 3600) / 60;
    string h_name = " годин ", m_name = " хвилин";
    if (h % 10 == 1) h_name = " година ";
    else if (h % 10 >= 2 and h % 10 <= 4) h_name = " години ";
    if (m % 10 == 1) m_name = " хвилина ";
    else if (m % 10 >= 2 and m % 10 <= 4) m_name = " хвилини ";
    cout << h << h_name << m << m_name <<endl;
    system("pause");
}

