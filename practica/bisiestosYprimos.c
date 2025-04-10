#include <stdio.h>
//#include <stdlib.h>
#include <unistd.h> //para el excelp o para poder poner NULL ahi ??
//#include <sys/types.h>
#include <sys/wait.h> //para el fork y wait

int main(){
    pid_t pidP = fork(); 

    if(pidP < 0 ){
        printf("primer fork failed");
        return 1; 
    } else if (pidP == 0){
        //codigo del hijo 
        execlp("./listarPrimos", "primos", NULL); 
    } 
    /*como el hijo se fue a otro codigo, el padre puede seguir su ejecucion sin necesidad de verificar pidP */
    pid_t pidB = fork(); //este codigo empieza desde aca, no? 

    if(pidB < 0 ){
        printf("segundo fork failed");
        return 1; 
    } else if (pidB == 0){
        //codigo del hijo 
        execlp("./listarBisiestos", "bisiesto", NULL); 
    } 

    printf("prueba");
    sleep(4);
    kill(pidB, 15); 
    sleep(4);
    kill(pidP, 15); 
    return 0; 
}