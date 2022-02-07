#include <iostream>
#include <fstream>
#include "header.h"

using namespace std;

int main()
{
    ifstream file1("file1.txt"), file2("file2.txt");
    ofstream file_result("file_result.txt");
    if (!file1){
        cerr << "file1 not found or cannot be opened" << endl;
        exit(1);
    }
    if (!file2) {
        cerr << "file2 not found or cannot be opened" << endl;
        exit(1);
    }
    if (file_is_empty(&file1) or file_is_empty(&file2)) {
        exit(1);
    }
    copy_matching(&file2, &file1, &file_result);
    file1.close();
    file2.close();
    file_result.close();
}

