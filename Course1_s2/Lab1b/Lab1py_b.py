import os.path
import pickle

import fileFunctions as ff
import otherFunctions as of

def inputToFile(file):
    product = of.productDict()
    while True:
        product["name"] = str(input("Enter name of product\n"))
        if ord(product["name"][0]) == 24:
            break
        product["type"] = str(input("Enter product type\n"))
        product["color"] = str(input("Enter product color\n"))
        product["price"] = float(input("Enter product price\n"))
        product["quantity"] = int(input("Enter product quantity\n"))
        pickle.dump(product, file)
        print(product["name"]+" was added to file")

def fileCreateEdit(filename):
    if os.path.isfile(filename):
        print(filename + " is already found. Clear it? (y/n)")
        choose = input()
        if choose == "y" or choose == "Y" or choose == "+" : file = open(filename, 'wb')
        else: file = open(filename, 'ab')
    else: file = open(filename, 'wb')
    print("Enter "+filename+" text (CTRL+X and enter - end of file):")
    inputToFile(file)
    return file

base_file = fileCreateEdit("basefile_py.dat")
base_file.close()
base_file = open("basefile_py.dat", 'rb')
database = ff.readFile(base_file)
print("Current database:\n")
of.printDB(database)

type_filter = str(input("\nEnter type filter:\n"))
filtered_database = of.keyFilter(database, "type" ,type_filter)
print("\nFiltered database: ")
of.printDB(filtered_database)
filtered_file = open("filteredfile_py.dat", 'wb')
ff.writeFile(filtered_file, filtered_database)
filtered_file.close()

filtered_file = open("filteredfile_py.dat", 'rb')
filteredfile_database = ff.readFile(filtered_file)
filtered_file.close()

filtered_file = open("filteredfile_py.dat", 'wb')
print("Enter price deleting range")
min_filter = float(input("Min value:\n"))
max_filter = float(input("Max value:\n"))
filteredfile_database = of.deleteByKeyRange(filteredfile_database, "price", min_filter, max_filter)
ff.writeFile(filtered_file, filteredfile_database)
print("\nCurrent filteredfile database:")
of.printDB(filteredfile_database)

base_file.close()
filtered_file.close()
input("Enter to close")
