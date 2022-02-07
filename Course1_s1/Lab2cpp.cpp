#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Ukrainian");
    int r, s, a, b;
    cout << "Введiть r: ";
    cin >> r;
    cout << "Введiть s: ";
    cin >> s;
    cout << "Введiть a: ";
    cin >> a;
    if (a < 0) {
        cout << "a менше за 0" << endl;
        system("pause");
        return 0;
    }
    cout << "Введiть b: ";
    cin >> b;
    if (b <= 0) {
        cout << "b менше або дорiвнює 0" << endl;
        system("pause");
        return 0;
    }
    if (a % b == r and a % b == s) cout << "Залишок дорiвнює i r i s";
    else if (a % b == r) cout << "Залишок дорiвнює r";
    else if (a % b == s) cout << "Залишок дорiвнює s";
    else cout<<"Залишок не дорiвнює жодному з чисел";
    cout << endl;
    system("pause");
}

