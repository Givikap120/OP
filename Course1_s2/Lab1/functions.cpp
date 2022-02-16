#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "header.h"

using namespace std;

ofstream file_create_edit(string filename) {
	string choose;
	ofstream file;
	if (check_for_file(filename)) {
		cout << filename <<" is already found. Clear it? (y/n)" << endl;
		cin >> choose;
		cin.ignore();
		if (choose == "y" or choose == "Y" or choose == "+") file.open(filename, ios::out);
		else file.open(filename, ios::app);
	}
	else file.open(filename, ios::out);
	cout << "Enter " << filename << " text (CTRL+X and enter - end of input):" << endl;
	cin_to_ofstream(&file);
	return file;
}
bool file_is_empty(ifstream* file) {
	string temp;
	*file >> temp;
	if (temp == "") return true;
	else {
		file->seekg(0);
		return false;
	}
}
bool is_in_text(string sample, vector<string> text) {
	for (size_t i = 0; i < text.size(); i++) {
		if (sample == text[i]) return true;
	}
	return false;
}
vector<string> copy_not_matching(vector<string> get, vector<string> compare) {
	vector<string> result;
	for (size_t i = 0; i < get.size(); i++)
	{
		if (is_in_text(get[i], compare) == false) {
			result.push_back(get[i]);
		}
	}
	return result;
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

void print(vector<string> text) {
	for (size_t i = 0; i < text.size(); i++)
	{
		cout << text[i] << endl;
	}
	cout << endl;
}

vector<string> read_file(ifstream* file) {
	vector<string> result;
	string line;
	while (*file) {
		getline(*file, line);
		result.push_back(line);
	}
	return result;
}

void write_file(vector<string> text, ofstream* file) {
	for (size_t i = 0; i < text.size(); i++)
	{
		*file << text[i] << endl;
	}
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