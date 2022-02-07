def is_in_file(sample, file):
    file.seek(0)
    if sample[-1] != '\n': sample += '\n'
    for temp in file:
        if temp[-1] != '\n': temp += '\n'
        if sample==temp: return True
    return False
def copy_matching(get, compare, copy):
    for current_line in get:
        if is_in_file(current_line, compare) == True: print(current_line, file=copy, end="")

file1 = open("file1.txt", 'r')
file2 = open("file2.txt", 'r')
file_result = open("file_result.txt", 'w');
copy_matching(file2, file1, file_result)
file1.close()
file2.close()
file_result.close()
