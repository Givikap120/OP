#include <iostream>
#include <fstream>
#include <vector>
#include "header.h"
#include <string>

using namespace std;

int main()
{
    ofstream ofile1 = file_create_edit("file1.txt");
    ofstream ofile2 = file_create_edit("file2.txt");
    ofile1.close();
    ofile2.close();
    ifstream ifile1("file1.txt"), ifile2("file2.txt");
    if (file_is_empty(&ifile1) or file_is_empty(&ifile2)) {
        exit(1);
    }
    vector<string> file1_text = read_file(&ifile1);
    vector<string> file2_text = read_file(&ifile2);
    ofstream ofile_result("file_result.txt");
    vector<string> result = copy_not_matching(file2_text, file1_text);
    write_file(result, &ofile_result);
    ofile_result.close();
    int num_of_lines = result.size();
    cout << "Num of file2 lines which in't in file1 = " << num_of_lines << endl << endl;
    cout << "file1.txt:" << endl;
    print(file1_text);
    cout << "file2.txt:" << endl;
    print(file2_text);
    cout << "file_result.txt:" << endl;
    print(result);
    ifile1.close();
    ifile2.close();
}