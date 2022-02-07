#include <fstream>
#include <string>
#include <iostream>
#include "header.h"

using namespace std;

bool file_is_empty(ifstream* file) {
	string temp;
	*file >> temp;
	if (temp == "") return true;
	else return false;
}
bool is_in_file(string sample, ifstream* file) {
	file->seekg(0);
	string temp;
	
	while (file->eof() == false) {
		getline(*file, temp);
		if (sample == temp) return true;
	}
	return false;
}
void copy_matching(ifstream* get, ifstream* compare, ofstream* copy) {
	string current_line;
	while (get->eof() == false)
	{
		getline(*get, current_line);
		if (is_in_file(current_line, compare) == true) *copy << current_line << endl;
	}
}