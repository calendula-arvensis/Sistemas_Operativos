#include <stdio.h>
int esPrimo(int x);

int main(){
    int nro = 2; 
    int respuesta; 
    while(1){
        respuesta = esPrimo(nro); 
        if(respuesta == 1){
            printf("soy el proceso que lista primos, %d es primo\n", nro);
        }
        nro++;
    }
    return 0; 
}

int esPrimo(int x){
    int noTieneDivisor = 1; 
    int i = 2; 
    if(x > 2){
    while(noTieneDivisor > 0 && i < x){
        if(x%i == 0){
            return 0; 
        }
        i++; 
    }
}
return 1; 
}
