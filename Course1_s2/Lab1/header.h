#pragma once
#include <string>
using namespace std;

bool file_is_empty(ifstream* file);
bool is_in_file(string sample, ifstream* file);
void copy_not_matching(ifstream* get, ifstream* compare, ofstream* copy);
int count_num_of_lines(ifstream* file);
void print(ifstream* file);
void cin_to_ofstream(ofstream* file);
bool check_for_file(string name);