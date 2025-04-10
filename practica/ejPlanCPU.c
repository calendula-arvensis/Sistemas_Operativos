/*
(0-8)p3, r12    queue:p2(3) 
(8-10)p3, r10   queue:p2(3)
(10-18)p1, r2   queue:p2(3), p3(4)
(18-22)p1, T    queue:p2(3), p3(4), p5(5)
(22-27)p5, T    queue:p2(3), p3(4), p4(4)
(27-35)p3, r2   queue:p2(3), p4(4)
(35-43)p4, r12  queue:p2(3), p3(4)
(43-45)p3, T    queue:p2(3), p4(4)
(45-53)p4, r4   queue:p2(3)
(53-57)p4, T    queue:p2(3)
(57-65)p2, r12  queue:
(65-73)p2, r4   queue: 
(73-77)p2, T

turnaround para p1 = 22 -10 = 12
turnaround para p2 = 77 - 5 = 72
turnaround para p3 = 45 - 0 = 45
turnaround para p4 = 57 - 25 = 32
turnaround para p5 = 27 - 20 = 7

valor medio de turnaround = (12+72+45+32+7)/5 = 33,6

tiempo espera de p1 = 22-12-10 = 0
tiempo espera de p2 = 77-20-5 = 52
tiempo espera de p3 = 45-20-0 = 25
tiempo espera de p4 = 57-20-25 = 12
tiempo espera de p5 = 27-5-20 = 2

valor medio de espera = (0+52+25+12+2)/5 = 18,2
*/