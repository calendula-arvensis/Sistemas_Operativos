#include <xinu.h>
#include <stdio.h>
#include <string.h>

int esPrimo(int a);
void listarPrimos(int ini, int fin);

int xsh_listarPrimos(){
    /*fork a child process (kind of like a diferentiable clone) */
    //pid_t pidH = fork();
    pid32 pid1 = create(listarPrimos, 2048, 30, "process 1", 2, 0, 5000);
    pid32 pid2 = create(listarPrimos, 2048, 20, "process 2", 2, 5000, 10000);
    //numero de prioridad es el 3er parametro de 'create', mientras mas alto mas prioridad
    //la funcion que va en el primer parametro debe retornar void
    /*el 5to parametro representa la cantidad de parametros de la funcion en el 1er parametro, 
    y los que siguen son los valores de dichos parametros (args) de argumento*/
    resume(pid1); 
    resume(pid2);
    return 0;
}

void listarPrimos(int ini, int fin){
    int x = ini; 
    while(x <= fin){
        if( esPrimo(x) > 0){
            kprintf("%d\n",(int)x);
        }
        x=x+1; 
    }
    kprintf("primos listados");
    return;
}

int esPrimo(int a){
    int encontrado = 1; 
    int i = 2, max = a/2; 
    while(i <= max && encontrado > 0){
        if (a % i == 0){
            encontrado = 0; 
        } 
        i= i+1;
    }
    return encontrado;
}