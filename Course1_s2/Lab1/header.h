#pragma once
#include <string>
using namespace std;

bool file_is_empty(ifstream* file);
bool is_in_file(string sample, ifstream* file);
void copy_matching(ifstream* get, ifstream* compare, ofstream* copy);