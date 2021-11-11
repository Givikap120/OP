
#include <iostream>
using namespace std;

double max(double a, double b) {
    if (a >= b) return a;
    else return b;
}

int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    cout << (max(a, a + b) + max(a, b + c)) / (1 + max(a + b * c, 1.15));
}

