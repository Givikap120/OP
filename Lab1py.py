k = int(input())
h = k // 3600
m = (k - h * 3600) // 60
h_name = "годин"
m_name = "хвилин"
if h == 1:
    h_name = "година"
elif h % 10 >= 2 and h % 10 <= 4:
   h_name = "години"
if m % 10 == 1:
   m_name = "хвилина";
elif m % 10 >= 2 and m % 10 <= 4:
   m_name = "хвилини"
print(h,h_name,m,m_name)
input('Для завершення натисніть ENTER') 
