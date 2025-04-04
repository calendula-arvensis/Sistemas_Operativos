#include <stdio.h>
int main()
{
    printf("Cuantos bits puede almacenar una variable declarada como int en C? (ej. int var;) \n");
    printf("Suponga 3 computadoras de arquitecturas diferentes: arquitecturas de 8bits, 32bits y 64bits");
    printf("\n Respuesta: \n");
    printf("El lenguaje C no define el tamanio de los objetos de datos de un tipo determinado. Es decir, un entero puede ocupar 16 bits en una implementacion del compilador, 32 en otra, o aun 64.  lo unico seguro es que un short no es mayor que un int, que a su vez no es mayor que long.");
    printf("Mi PC es de 64bits, lo busque apretando windows+R y escribiendo dxdiag");
    return 0;
}