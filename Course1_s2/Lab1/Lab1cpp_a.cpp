#include <iostream>
#include <fstream>
#include "header.h"
#include <string>

using namespace std;

int main()
{
    string choose;
    ofstream ofile1, ofile2;
    if (check_for_file("file1.txt")) {
        cout << "file1.txt is already found. Clear it? (y/n)" << endl;
        cin >> choose;
        cin.ignore();
        if (choose == "y" or choose == "Y" or choose == "+") ofile1.open("file1.txt", ios::out);
        else ofile1.open("file1.txt", ios::app);
    }
    else ofile1.open("file1.txt", ios::out);
    cout << "Enter file1 text (CTRL+X and enter - end of input):" << endl;
    cin_to_ofstream(&ofile1);
    if (check_for_file("file2.txt")) {
        cout << "file2.txt is already found. Clear it? (y/n)" << endl;
        cin >> choose;
        cin.ignore();
        if (choose == "y" or choose == "Y" or choose == "+") ofile2.open("file2.txt", ios::out);
        else ofile2.open("file2.txt", ios::app);
    }
    else ofile2.open("file2.txt", ios::out);
    cout << "Enter file2 text (CTRL+X and enter - end of input):" << endl;
    cin_to_ofstream(&ofile2);
    ofile1.close();
    ofile2.close();
    ifstream ifile1("file1.txt"), ifile2("file2.txt");
    ofstream ofile_result("file_result.txt");
    if (!ifile1) {
        cerr << "file1 not found or cannot be opened" << endl;
        exit(1);
    }
    if (!ifile2) {
        cerr << "file2 not found or cannot be opened" << endl;
        exit(1);
    }
    if (file_is_empty(&ifile1) or file_is_empty(&ifile2)) {
        exit(1);
    }
    copy_not_matching(&ifile2, &ifile1, &ofile_result);
    ofile_result.close();
    ifstream ifile_result("file_result.txt");
    int num_of_lines = count_num_of_lines(&ifile_result);
    cout << "Num of file2 lines which in't in file1 = " << num_of_lines << endl << endl;
    cout << "file1.txt:" << endl;
    print(&ifile1);
    cout << "file2.txt:" << endl;
    print(&ifile2);
    cout << "file_result.txt:" << endl;
    print(&ifile_result);
    ifile1.close();
    ifile2.close();
    ifile_result.close();
}

