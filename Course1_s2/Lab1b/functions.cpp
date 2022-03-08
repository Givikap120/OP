#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "header.h"

using namespace std;

void cinToFstream(fstream* file);

fstream fileCreateEdit(string filename) {
	string choose;
	fstream file;
	if (checkForFile(filename)) {
		cout << filename << " is already found. Clear it? (y/n)" << endl;
		cin >> choose;
		cin.ignore();
		if (choose == "y" or choose == "Y" or choose == "+") file.open(filename, ios::out, ios::binary);
		else file.open(filename, ios::app, ios::binary);
	}
	else file.open(filename, ios::out, ios::binary);
	cout << "Enter " << filename << " products (CTRL+X and enter in name input - end of input):" << endl;
	cinToFstream(&file);
	return file;
}

vector<product> filterByType(vector<product> database, string filter) {
	for (size_t i = 0; i < database.size(); i++)
	{
		if (database[i].type != filter) database.erase(database.begin() + i);
	}
	return database;
}

vector<product> deleteByPriceRange(vector<product> database, float min, float max) {
	for (size_t i = 0; i < database.size(); i++)
	{
		if (database[i].price >= min and database[i].price <= max) database.erase(database.begin() + i);
	}
	return database;
}

void cinToFstream(fstream* file) {
	product input;
	while (true) {
		cout << "Enter name of product:" << endl;
		getline(cin, input.name);
		if (input.name[0] == 24) break;
		cout << "Enter product type:" << endl;
		getline(cin, input.type);
		cout << "Enter product color:" << endl;
		getline(cin, input.color);
		cout << "Enter product price:" << endl;
		cin >> input.price;
		cout << "Enter product quantity:" << endl;
		cin >> input.quantity;
		cin.ignore();
		writeProduct(file, input);
		cout << input.name << " was added to file" << endl;
	}
}

void print(vector<product> database) {
	for (size_t i = 0; i < database.size(); i++)
	{
		cout << "Product name - " << database[i].name << endl;
		cout << "Type - " << database[i].type << endl;
		cout << "Color - " << database[i].color << endl;
		cout << "Price - " << database[i].price << endl;
		cout << "Quantity - " << database[i].quantity << endl;
		cout << endl;
	}
}