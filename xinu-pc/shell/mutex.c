#include <xinu.h>

void mutex_lock(); 
int mutex_unLock();
sid32 sem;  
pid32 pActual; 

void mutex_init(){
    pActual = 0; 
    sem = semcreate(1); 
}

void mutex_lock(){
    wait(sem); 
    pActual = currpid; 
}

int mutex_unlock(){
    if(pActual == currpid){
        pActual = 0; 
        signal(sem);
        return 0; 
    } else {
        printf("el unlock fue mal usado");
        return 1; 
    }
}
