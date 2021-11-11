#include <iostream>
#include <cmath>
using namespace std;
long round_up(double number) {
    if (long(number) != number) number = long(number) + 1;
    return long(number);
}
int main()
{
    setlocale(LC_ALL, "Ukrainian");
    int n;
    long n_fact = 1, a2;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        n_fact *= i;
    }
    a2 = round_up(pow(n_fact, 1.0 / 3));

    bool is_suitable = true;
    if (n_fact % (a2 + 1) != 0) is_suitable = false;
    else if (n_fact % (a2) != 0) is_suitable = false;
    else if (n_fact % (a2 - 1) != 0) is_suitable = false;

    if (is_suitable == true) cout << "Так, можна: " << a2 - 1 << " * " << a2 << " * " << a2 + 1 << " = " << n_fact;
    else cout << "Нi, не можна";
}

