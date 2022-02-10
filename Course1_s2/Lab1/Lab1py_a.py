import os.path

def is_in_file(sample, file):
    file.seek(0)
    if sample[-1] != '\n': sample += '\n'
    for temp in file:
        if temp[-1] != '\n': temp += '\n'
        if sample==temp: return True
    return False

def copy_not_matching(get, compare, copy):
    counter = 0
    for current_line in get:
        if is_in_file(current_line, compare) == False:
            print(current_line, file=copy, end="")
            counter+=1
    return counter

def print_file(file):
    for i in file:
        print(i,end="")
    print()

def cin_to_ofstream(file):
    while (True):
        temp = input()
        if ord(temp[0]) == 24: break
        print(temp, file=file)
        
if os.path.isfile("file1.txt"):
    print("file1.txt is already found. Clear it? (y/n)")
    choose = input()
    if choose == "y" or choose == "Y" or choose == "+" : file1 = open("file1.txt", 'w')
    else: file1 = open("file1.txt", 'a')
else: file1 = open("file1.txt", 'w')
print("Enter file1 text (CTRL+X and enter - end of file):")
cin_to_ofstream(file1)

if os.path.isfile("file2.txt"):
    print("file2.txt is already found. Clear it? (y/n)")
    choose = input()
    if choose == "y" or choose == "Y" or choose == "+" : file2 = open("file2.txt", 'w')
    else: file2 = open("file2.txt", 'a')
else: file2 = open("file2.txt", 'w')
print("Enter file1 text (CTRL+X and enter - end of file):")
cin_to_ofstream(file2)

file1.close()
file2.close()

file1 = open("file1.txt", 'r')
file2 = open("file2.txt", 'r')
file_result = open("file_result.txt", 'w');
print("Num of file2 lines which in't in file1:")
num_of_lines = copy_not_matching(file2, file1, file_result)
print(num_of_lines)
file1.close()
file2.close()
file_result.close()

file1 = open("file1.txt", 'r')
file2 = open("file2.txt", 'r')
file_result = open("file_result.txt", 'r')
print("file1.txt:")
print_file(file1)
print("file2.txt:")
print_file(file2)
print("file_result.txt:")
print_file(file_result)
file1.close()
file2.close()
file_result.close()
input("Enter to close")
