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
    awnser+=chiselnik/znamennik
print(int(awnser*100000)/100000)
input('Для завершення натисніть ENTER') 


    
