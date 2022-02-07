awnser = 1.0
awnser_prev = 0.0
chiselnik = 1.0
znamennik = 1
factor = 0
inp = float(input())
while int(awnser * 100000) != int(awnser_prev * 100000):
    awnser_prev = awnser
    factor+=1
    chiselnik*=inp
    znamennik*=factor
    print("drib","=",f'{chiselnik:.6g}',"/",znamennik,"=",f'{chiselnik/znamennik:.6f}')
    awnser+=chiselnik/znamennik
    print("sum","=",f'{awnser_prev:.8g}',"+",f'{chiselnik/znamennik:.6f}',"=",f'{awnser:.8g}')
print(int(awnser*100000)/100000)
input('Для завершення натисніть ENTER') 


    
