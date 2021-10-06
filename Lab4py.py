n_current = 1
n_prev = 0
needed_num = int(input("Введiть номер числа Фiбоначi: "))
if needed_num == 0: print(n_prev)
else:
    for i in range(1, needed_num):
        temp = n_current + n_prev
        n_prev = n_current
        n_current = temp
    print(n_current)
input('Для завершення натисніть ENTER') 
