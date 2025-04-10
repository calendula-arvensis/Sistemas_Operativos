/*
EJERCICIO 3: 
              T        q15         q10         q10        q5       T          T                      T
(0-10)p1,(10-15)p1, (15-20)p2, (20-30)p3, (30-40)p4, (40-45)p3, (45-50)p5, (50-55)p3, (55-65)p6, (65-70)p6
(70-80)p4, (80-90)p2, (90-95)p2

el tiempo de turnaround para cada proceso es cuanto tardaron desde estar listos hasta ser terminados 
turnaround para p1 = 15 - 0  = 15
turnaround para p2 = 95 - 0  = 95
turnaround para p3 = 55 - 20 = 35
turnaround para p4 = 80 - 25 = 55
turnaround para p5 = 50 - 45 = 5
turnaround para p6 = 70 - 55 = 15
turnaround = momento de finalizacion - momento en que llego a la fila

valor medio de turnaround = (15+95+35+55+5+15)/6 = 36,66

tiempo espera de p1 = 0
tiempo espera de p2 = 95 - 20 = 75
tiempo espera de p3 = 35 - 20 = 15
tiempo espera de p4 = 55 - 20 = 35
tiempo espera de p5 = 50 - 5 = 45
tiempo espera de p6 = 15 - 15 = 0
momento de finalizacion - tiempo de ejecucion

valor medio de espera = (0+75+15+35+45+0)/6 = 28,33

EJERCICIO 4
FCFS

(0-5)p1, (5-8)p2, (8-9)p3, (9-16)p4, (16-20)p5
turnaround para p1 = 5
turnaround para p2 = 8
turnaround para p3 = 9
turnaround para p4 = 16
turnaround para p5 = 20

valor medio de turnaround = (5+7+8+15+19)/5 = 10,8

tiempo espera de p1 = 0
tiempo espera de p2 = 5
tiempo espera de p3 = 7
tiempo espera de p4 = 8
tiempo espera de p5 = 15

valor medio de espera = (0+5+7+8+15)/5 = 7

SJF
(0-1)p3, (1-4)p2, (4-8)p5, (8-13)p1, (13-20)p4
turnaround para p1 = 13
turnaround para p2 = 4
turnaround para p3 = 1
turnaround para p4 = 20
turnaround para p5 = 8

valor medio de turnaround = (13+4+1+20+8)/5 = 9,2

tiempo espera de p1 = 8
tiempo espera de p2 = 1
tiempo espera de p3 = 0
tiempo espera de p4 = 13
tiempo espera de p5 = 4

valor medio de espera = (8+1+0+13+4)/5 = 5,2

PRIORITY SCHEDULIND no-apropiativo
(0-5)p1, (5-9)p5, (9-10)p3, (10-17)p4, (17-20)p2

turnaround para p1 = 5
turnaround para p2 = 20
turnaround para p3 = 10
turnaround para p4 = 17
turnaround para p5 = 9

valor medio de turnaround = (5+20+10+17+9)/5 = 12,2

tiempo espera de p1 = 0
tiempo espera de p2 = 17
tiempo espera de p3 = 9
tiempo espera de p4 = 10
tiempo espera de p5 = 5

valor medio de espera = (0+17+9+10+5)/5 = 8,2

ROUND-ROBIN (quantum = 2)
(0-2)p1, (2-4)p2, (4-5)p3, (5-7)p4, (7-9)p5, (9-11)p1, (11-12)p2, (12-14)p4, (14-16)p5, 
(16-17)p1, (17-19)p4, (19-20)p4

turnaround para p1 = 17
turnaround para p2 = 12
turnaround para p3 = 5
turnaround para p4 = 20
turnaround para p5 = 16

valor medio de turnaround = (17+12+5+20+16)/5 = 14

tiempo espera de p1 = 17-5 = 12
tiempo espera de p2 = 12-3 = 9
tiempo espera de p3 = 4
tiempo espera de p4 = 20-7 = 13
tiempo espera de p5 = 16-4 = 12

valor medio de espera = (12+9+4+13+12)/5 = 10

VALOR MINIMO DE TIEMPO DE ESPERA 
FCFS tuvo un medio de espera de: 7
SJF tuvo un medio de espera de: 5,2
PRIORITY SCHEDULING tuvo un medio de espera de 8,2
ROUND-ROBIN tuvo un medio de espera de: 10

por lo tanto... el algoritmo que tuvo el menor tiempo de 
espera fue el shortest job first
*/