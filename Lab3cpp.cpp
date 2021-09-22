#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Ukrainian");
    double awnser = 1, awnser_prev = 0, input, chiselnik = 1;
    long znamennik = 1, factor = 0;
    cin >> input;
    while (long(awnser * 100000) != long(awnser_prev * 100000)) {
        awnser_prev = awnser;
        factor++;
        chiselnik *= input;
        znamennik *= factor;
        awnser += chiselnik / znamennik;
    }
    cout << float(long(awnser * 100000)) / 100000 << endl;
    system("pause");
}

