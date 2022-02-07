def max(a, b):
    if a >= b:
        return a
    else:
        return b

a,b,c=input("Enter 3 numbers divided with spaces (a b c): ").split()
a=float(a)
b=float(b)
c=float(c)
print((max(a, a + b) + max(a, b + c)) / (1 + max(a + b * c, 1.15)))
