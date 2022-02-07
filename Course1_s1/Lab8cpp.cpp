#include <iostream>
#include <random>
#include <iomanip>
#include <ctime>
using namespace std;

void print(double* array, int size);
void print(double** array, int size);
double find_norm(double** array, int size);
double find_max(double* array, int size);
int length_of_int(int number);
void delete_matrix(double** array, int size);

int main()
{
    srand(time(NULL));
    setlocale(0, "");
    int n;
    cout << "Введiть n - розмiрнiсть масиву" << endl;
    cin >> n;
    double** A = new double*[n];
    double** B = new double*[n];
    
    for (int i = 0; i < n; i++) {
        A[i] = new double[n];
        B[i] = new double[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 200 - 100;
            B[i][j] = rand() % 200 - 100;
        }
    }
    cout << "Масив A:" << endl;
    print(A, n);
    cout << "Масив B:" << endl;
    print(B, n);
    double A_norm = find_norm(A,n), B_norm = find_norm(B, n);
    cout << "Норма А = " << A_norm << endl;
    cout << "Норма B = " << B_norm << endl;
    cout << "Середнє арифметичне = " << (A_norm + B_norm) / 2 <<endl;
    delete_matrix(A, n);
    delete_matrix(B, n);
    system("pause");
}

int length_of_int(int number) {
    int len = 0;
    while (number != 0) {
        number /= 10;
        len++;
    }
    return len;
}

void print(double* array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void print(double** array, int size) {
    int max_column_length = 0, curr_len;
    int* column_lengths = new int[size];
    for (int i = 0; i < size; i++) {
        max_column_length = 0;
        for (int j = 0; j < size; j++) {
            curr_len = length_of_int(array[j][i]);
            if (curr_len > max_column_length) max_column_length = curr_len;
        }
        column_lengths[i] = max_column_length;
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << setw(column_lengths[j] + 1) << array[i][j] << " ";
        }
        cout << endl;
    }
    delete[] column_lengths;
}

double find_norm(double** array, int size) {
    double* row_sums = new double[size];
    double summ;
    for (int i = 0; i < size; i++) {
        summ = 0;
        for (int j = 0; j < size; j++) {
            summ += abs(array[i][j]);
        }
        row_sums[i] = summ;
    }
    double max = find_max(row_sums, size);
    delete[] row_sums;
    return max;
}

double find_max(double* array, int size) {
    double max = array[0];
    for (int i = 0; i < size; i++) {
        if (array[i] > max) max = array[i];
    }
    return max;
}

void delete_matrix(double** array, int size) {
    for (int i = 0; i < size; i++) {
        delete[] array[i];
    }
    delete[] array;
}