def round_up(number):
    if int(number) != number:
        number = int(number) + 1;
    return number;

n=int(input())
n_fact = 1
for i in range(1,n+1):
    n_fact *= i
a2 = round_up(n_fact**(1/3));
is_suitable = True

if n_fact % (a2 + 1) != 0:
    is_suitable = False
elif n_fact % (a2) != 0:
    is_suitable = False
elif n_fact % (a2 - 1) != 0:
    is_suitable = False

if is_suitable == True:
    print("Так, можна: ",(a2 - 1)," * ",a2," * ",(a2 + 1)," = ",n_fact)
else:
    print("Нi, не можна")



