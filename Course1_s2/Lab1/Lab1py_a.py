import os.path

def file_create_edit(filename):
    if os.path.isfile(filename):
        print(filename + " is already found. Clear it? (y/n)")
        choose = input()
        if choose == "y" or choose == "Y" or choose == "+" : file = open(filename, 'w')
        else: file = open(filename, 'a')
    else: file = open(filename, 'w')
    print("Enter "+filename+" text (CTRL+X and enter - end of file):")
    cin_to_ofstream(file)
    return file

def is_in_text(sample, text):
    if sample[-1] != '\n': sample += '\n'
    for temp in text:
        if temp[-1] != '\n': temp += '\n'
        if sample==temp: return True
    return False

def copy_not_matching(get, compare):
    result = []
    for current_line in get:
        if is_in_text(current_line, compare) == False:
            result.append(current_line)
    return result

def read_file(file):
    file_text = []
    for i in file:
        file_text.append(i)
    return file_text

def print_arr(arr):
    for i in arr:
        print(i, end="")
    print()

def cin_to_ofstream(file):
    while (True):
        temp = input()
        if ord(temp[0]) == 24: break
        print(temp, file=file)
        

file1 = file_create_edit("file1.txt")
file2 = file_create_edit("file2.txt")
file1.close()
file2.close()

file1 = open("file1.txt", 'r')
file2 = open("file2.txt", 'r')
file1_text = read_file(file1)
file2_text = read_file(file2)

file_result = open("file_result.txt", 'w');
result = copy_not_matching(file2_text, file1_text)
print("Num of file2 lines which in't in file1:")
num_of_lines = len(result)
print(num_of_lines)
file1.close()
file2.close()
file_result.close()

print("file1.txt:")
print_arr(file1_text)
print("file2.txt:")
print_arr(file2_text)
print("file_result.txt:")
print_arr(result)
input("Enter to close")
