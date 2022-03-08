#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>
#include "header.h"

using namespace std;


int main()
{
    fstream base_file = fileCreateEdit("basefile.dat");
    base_file.close();
    base_file.open("basefile.dat", ios::in, ios::binary);
    if (fileIsEmpty(&base_file)) {
        exit(1);
    }

    vector<product> database = readFile(&base_file);
    cout << "Current database:" << endl;
    print(database);

    cout << endl << "Enter type filter:" << endl;
    string type_filter;
    cin >> type_filter;
    vector<product> filtered_database = filterByType(database, type_filter);
    cout << endl << "Filtered database: " << endl;
    print(filtered_database);
    fstream filtered_file("filteredfile.dat", ios::out, ios::binary);
    writeFile(&filtered_file, filtered_database);
    filtered_file.close();

    filtered_file.open("filteredfile.dat", ios::in);
    vector<product> filteredfile_database = readFile(&filtered_file);
    filtered_file.close();

    filtered_file.open("filteredfile.dat", ios::out);
    cout << "Enter price deleting range" << endl;
    float min_filter, max_filter;
    cin >> min_filter >> max_filter;
    filteredfile_database = deleteByPriceRange(filteredfile_database, min_filter, max_filter);
    writeFile(&filtered_file, filteredfile_database);
    cout << endl << "Current filteredfile database:" << endl;
    print(filteredfile_database);

    base_file.close();
    filtered_file.close();

    system("pause");
}