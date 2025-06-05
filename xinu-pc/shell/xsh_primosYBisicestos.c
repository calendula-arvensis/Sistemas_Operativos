#include <xinu.h>
void esPrimo(pid32 pidO);
void esBisiesto(pid32 pidO);

shellcmd xsh_primosYBisiestos(int nargs, char *args[]){
    int num, esP, esB; 
    char buff[10];

    kprintf("Ingrese un nro: \n");
    read(CONSOLE, buff, 10);
    num = atoi(buff);

    kprintf("El numero ingresado entero es %d \n", num);
    pid32 primo = create(esPrimo, 2048, 20, "esPrimo", 1, getpid());
    pid32 bisiesto = create(esBisiesto, 2048, 20, "esBisiesto", 1, getpid()); 
    resume(primo);
    resume(bisiesto);
    send(primo, num);
    esP = receive(); 
    kill(primo);
    send(bisiesto, num); 
    esB = receive(); 

    kill(bisiesto); 

    	if(esP> 0)
		printf("El numero es primo \n");
	else
		printf("El numero no es primo \n");

	if(esB)
		printf("El numero es año bisiesto \n");
	else
		printf("El numero no es año bisiesto\n");
}

void esBisiesto(pid32 pidO){ 
    int siEs = 0; 
    int x = receive();
    if(x%4 == 0){
        if(x%400 == 0){
            siEs = 1; 
        } else if(x%100 > 0){
            siEs = 1; 
        }
    } 
    send(pidO, siEs); 
}