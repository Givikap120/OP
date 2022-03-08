#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "header.h"

using namespace std;

string readString(fstream* file);
void writeString(fstream* file, string str);

int getFileSize(fstream* file);

vector<product> readFile(fstream* file) {
	vector<product> result;
	product cell;
	int file_size = getFileSize(file);
	while (file->tellg() < file_size) {
		result.push_back(readProduct(file));
	}
	return result;
}

void writeFile(fstream* file, vector<product> database) {
	for (size_t i = 0; i < database.size(); i++)
	{
		writeProduct(file, database[i]);
	}
}

product readProduct(fstream* file) {
	product result;
	result.name = readString(file);
	result.type = readString(file);
	result.color = readString(file);
	file->read((char*)&result.price, sizeof(result.price));
	file->read((char*)&result.quantity, sizeof(result.quantity));
	return result;
}

void writeProduct(fstream* file, product item) {
	writeString(file, item.name);
	writeString(file, item.type);
	writeString(file, item.color);
	file->write((char*)&item.price, sizeof(item.price));
	file->write((char*)&item.quantity, sizeof(item.quantity));
}

string readString(fstream* file) {
	int size;
	file->read((char*)&size, sizeof(size));
	char* buf = new char[size + 1];
	buf[size] = '\0';
	file->read(buf, size);
	string str = buf;
	delete[] buf;
	return str;
}

void writeString(fstream* file, string str) {
	int size = str.size();
	file->write((char*)&size, sizeof(size));
	file->write(str.c_str(), size);
}


bool fileIsEmpty(fstream* file) {
	string temp;
	*file >> temp;
	if (temp == "") return true;
	else {
		file->seekg(0);
		return false;
	}
}

bool checkForFile(string name) {
	ifstream file(name);
	if (file) {
		file.close();
		return true;
	}
	else {
		file.close();
		return false;
	}
}

int getFileSize(fstream* file) {
	int current_ptr = file->tellg();
	file->seekg(0, ios::end);
	int size = file->tellg();
	file->seekg(current_ptr, ios::beg);
	return size;
}