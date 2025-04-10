#include <stdio.h>

int esBisiesto(int x);
int main(){
    int nro = 1700; 
    int respuesta; 
    while(1){
        respuesta = esBisiesto(nro); 
        if(respuesta > 0){
            printf("soy el proceso que lista bisiestos, %d es bisiesto\n", nro);
        }
        nro++; 
    }
    return 0; 
}

int esBisiesto(int x){ 
    int siEs = 0; 
    if(x%4 == 0){
        if(x%100 == 0 && x%400 == 0){
            siEs = 1; 
        } else if(x%100 > 0){
            siEs = 1; 
        }
    }
return siEs; 
}