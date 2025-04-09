/*
ANALISIS DE SYSTEM CALLS

'suspend(pid) se usa para suspender un proceso, poniendolo en hibernacion. Solo suspende procesos que estan
en ejecucion o listos. Si se intenta suspender un proceso dormido no se que pasa, pero seria muy molesto que no te deje

resume(pid) se utiliza para poner en listo un proceso que estaba suspendido o caba de ser creado (se crean en suspencion)

getprio(pid) retorna la prioridad planificada para un proceso (cuyo ID es pid)

chpio(pid, newprio); cambia la prioridad planificada de este proceso a una nueva prioridad y retorna la prioridad anterior. para que?

getpid(); retorna el ID del proceso en ejecucion

sleepms(ms); duerme al proceso durante ms milisegundos, la unica diferencia con sleep(seg) es la unidad en la que se toma el parametro

QUANTUM es 2
el quantum es el tiempo maximo que un proceso puede estar en la cpu.
Si el valor es muy chico puede sobrecargarse la maquina al hacer tantos cambios de contexto o tan seguidos.
En cambio si el valor es muy grande, los procesos podrian morir de inanicion al tener que esperar a que otros procesos terminen.
Esta bueno encontrar un valor que balancee estos dos problemas (2)

*/