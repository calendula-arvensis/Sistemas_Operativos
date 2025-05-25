#include <xinu.h>

void produce(void), consume(void);
int32 n=0; /*global variables are shared by all processes*/
sid32 prod_sem, cons_sem; 

/*main - Example of unsynchronized producer and consumer processes*/
void xsh_prodConsumidor(void){
    prod_sem = semcreate(1); 
    cons_sem = semcreate(0); 
    resume(create(consume, 1024, 20, "cons", 0));
    resume(create(produce, 1024, 20, "prod", 0));
}

/*produce - Increment n 2000 times and exit */

void produce(void){
    int32 i; 
    for ( i = 1; i <= 2000; i++)
    {
        wait(prod_sem); 
        n++; 
        signal(cons_sem); 
    }
}

/*consume - Print n 2000 times and exit */
void consume(void){
    int32 i;
    for ( i = 1; i <= 2000; i++)
    {
        wait(cons_sem);
        printf("The value of n in %d \n", n);
        signal(prod_sem); 
    }
    
}