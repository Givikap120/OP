#pragma once
#include <string>
using namespace std;

ofstream file_create_edit(string filename);
bool file_is_empty(ifstream* file);
bool is_in_text(string sample, vector<string> text);
vector<string> read_file(ifstream* file);
void write_file(vector<string> text, ofstream* file);
vector<string> copy_not_matching(vector<string> get, vector<string> compare);
void print(ifstream* file);
void print(vector<string> text);
void cin_to_ofstream(ofstream* file);
bool check_for_file(string name);