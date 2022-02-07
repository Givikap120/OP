#include <iostream>
#include <random>
#include <ctime>
using namespace std;

void print(double* array, int size);
double* find_max(double* array, int size);
double* find_min(double* array, int size);

int main()
{
    srand(time(NULL));
    setlocale(0, "");
    int n;
    cout << "Введiть n - розмiрнiсть масиву" << endl;
    cin >> n;
    double* F = new double[n];
    double* G = new double[n];
    for (int i = 0; i < n; i++) {
        F[i] = rand() % 200 - 100;
        G[i] = rand() % 200 - 100;
    }
    cout << "Масив F:" << endl;
    print(F, n);
    cout << "Масив G:" << endl;
    print(G, n);
    double* fmax = find_max(F, n);
    double* gmin = find_min(G, n);
    double z = abs(*fmax + *gmin) / 2;
    cout << "fmax = " << *fmax << endl;
    cout << "gmin = " << *gmin << endl;
    cout << "z = " << z << endl;
    *fmax = z;
    *gmin = z;
    cout << "Новий масив F:" << endl;
    print(F, n);
    cout << "Новий масив G:" << endl;
    print(G, n);
}

void print(double* array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

double* find_max(double* array, int size) {
    double* max = &array[0];
    for (int i = 0; i < size; i++) {
        if (array[i] > *max) max = &array[i];
    }
    return max;
}

double* find_min(double* array, int size) {
    double* min = &array[0];
    for (int i = 0; i < size; i++) {
        if (array[i] < *min) min = &array[i];
    }
    return min;
}