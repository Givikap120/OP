#include <fstream>
#include <string>
#include <iostream>
#include "header.h"

using namespace std;

bool file_is_empty(ifstream* file) {
	string temp;
	*file >> temp;
	if (temp == "") return true;
	else {
		file->seekg(0);
		return false;
	}
}
bool is_in_file(string sample, ifstream* file) {
	file->clear();
	file->seekg(0);
	string temp;

	while (file->eof() == false) {
		getline(*file, temp);
		if (sample == temp) return true;
	}
	return false;
}
void copy_not_matching(ifstream* get, ifstream* compare, ofstream* copy) {
	string current_line;
	bool first = true;
	while (get->eof() == false)
	{
		getline(*get, current_line);
		if (is_in_file(current_line, compare) == false) {
			*copy << current_line << endl;
		}
	}
}

int count_num_of_lines(ifstream* file) {
	file->clear();
	file->seekg(0);
	int counter = 0;
	string trashcan;
	while (*file) {
		getline(*file, trashcan);
		counter++;
	}
	return counter - 1;
}
void print(ifstream* file) {
	file->clear();
	file->seekg(0);
	string temp;
	while (*file) {
		getline(*file, temp);
		cout << temp << endl;
	}
	cout << endl;
}

void cin_to_ofstream(ofstream* file) {
	string temp;
	while (true) {
		getline(cin, temp);
		if (temp[0] == 24) break;
		*file << temp << endl;
	}
}

bool check_for_file(string name) {
	ifstream file(name);
	if (file) return true;
	else return false;
}