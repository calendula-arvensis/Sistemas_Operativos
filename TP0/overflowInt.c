#include <stdio.h>
int main()
{
    printf("Escribir un programa que multiplique e imprima 100000 * 100000. De que tamanio son los ints en su sistema?\n");
    int a = 100000, b = 100000;
    int c = a * b;
    printf(" Respuesta: c = %d \n", c);
    printf("el tamanio de los ints es %d, esto significa que van de %d a %d", sizeof(c), (int)0x80000000, (int)0x7FFFFFFF);
    return 0;
}