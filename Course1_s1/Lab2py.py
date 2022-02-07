r=int(input("Введіть r: "))
s=int(input("Введіть s: "))
a=int(input("Введіть a: "))
if a<0:
    print("a менше за 0")
    input('Для завершення натисніть ENTER') 
    sys.exit()
b=int(input("Введіть b: "))
if b<=0:
    print("b менше або дорiвнює 0")
    input('Для завершення натисніть ENTER') 
    sys.exit()
if a%b==r and a%b==s:
    print("Залишок дорівнює і r і s")
elif a%b==r:
    print("Залишок дорівнює r")
elif a%b==s:
    print("Залишок дорівнює s")
else:
    print("Залишок не дорівнює жодному з чисел")
input('Для завершення натисніть ENTER') 


    
