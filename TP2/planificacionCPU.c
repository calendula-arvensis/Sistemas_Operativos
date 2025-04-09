/*algunas cosas para tener en cuenta al analizar algoritmos de planificacion de cpu: 
el uso de la CPU: esta debe mantenerse ocupada pero no sobrecargada

"throughput" cantidad de procesos terminados en un determinado tiempo

"turnarround time" en complemento al throughput, este es desde el punto de vista de 
cada proceso, turnaround time es la suma de los periodos esperando en la cola(queue), 
ejecutando su codifo en la cpu y en operaciones de entrada y salida (I/O)

"waiting time" es el tiempo (o la suma de los tiempos) en que un proceso esta listo y esperando en la queue

"response time" es el tiempo que el proceso tarda en responder

ALGORITMOS DE PLANIFICACION DE CPU
"firs-come, first-served scheduling" el proceso que primero pide la cpu se la queda
este algoritmo no es el mejor porque depende de la circunstancia en la que los procesos 
pidan la cpu y que necesiten de ella. no es impredecible pero no tendra la misma eficiencia 
todas las veces

"shortest-job-first scheduling" el proceso mas corto va primero, pero requiere saber /o predecir/ cuanto
tardaria cada proceso 

"round-robin scheduling" es parecido al FCFS pero le agrega a la CPU la habilidad de pausar un 
proceso y seguir con otro, permitiendo una rotacion entre los procesos. Un QUANTUM es el valor definido de 
milisegundos en que cada proceso tiene uso de la cpu, luego tiene que dejarlo y seguir con el siguiente.
eventualmente la cpu llegara de nuevo a procesos ya incicializados y avanzara con ellos. 

"priority scheduling" es como el SJF pero en lugar de utilizar el tiempo de ejecucion le asigna a los procesos
una prioridad. Un problema que sirge con este algoritmo es la inacion o Starvation, ya que procesos con mayor 
prioridad se "colan" en la fila dejando aquellos con poca prioridad atras eternamente. una solucion a esto es 
ir agregandole prioridad a los procesos a medida que envejecen. 

"multilevel queue scheduling" este algoritmo agrupa las prioridades en distintas listas y utiliza el algoritmo 
round-robin en la lista de procesos de mayor prioridad, designando la prioridad al origen de los procesos 
(una lista para procesos de tiempo real, otra para procesos del sistema, procesos interactivos y finalmente rpcesos del batch)

"multilevel feedback queue scheduling" en el anterior, los procesos se quedan en la misma lista para siempre, en 
cambio este algoritmo permite a los procesos cambiar de lista, designando la prioridad de una forma muy compleja

ejercicio 3: 

(0-15)p1, (15-20)p5, (20-35)p6, (35-45)p3, (45-55)p4, (55-65)p3, (65-75)p4, (75-95)p2
el tiempo de turnaround para cada proceso es cuanto tardaron desde estar listos hasta ser terminados 
turnaround para p1 = 15
turnaround para p2 = 95
turnaround para p3 = 65
turnaround para p4 = 75
turnaround para p5 = 20
turnaround para p6 = 35

valor medio de turnaround = (15+95+65+75+20+35)/6 = 50,83
*/