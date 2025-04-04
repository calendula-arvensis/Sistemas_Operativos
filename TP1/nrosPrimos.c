#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int esPrimo(int a);
int listarPrimos(int ini, int fin);

int main(){
    /*fork a child process (kind of like a diferentiable clone) */
   pid_t pidH = fork();

   if (pidH < 0){
    /*fork failed, when could it fail?, is it like an exception?  */
    return 1; //obligatory
   } else if (pidH == 0){
    /*code for the child*/
    /*
    printf("inicia a listar el hijo\n");
    listarPrimos(1000, 5000);
    exit(0);
    */
    execl("/usr/bin/date","nuevoNombre", NULL);
   } else {
    /*code for the parent*/
    printf("inicia a listar el padre\n");
    //listarPrimos(0,1000);
    //wait(NULL);
    //kill(pidH, 15);
    printf("el hijo fue terminado\n");
   }
    return 0;
}

int listarPrimos(int ini, int fin){
    int x = ini; 
    while(x <= fin){
        if( esPrimo(x) > 0){
            printf("%d\n",(int)x);
        }
        x=x+1; 
    }
    return 0;
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