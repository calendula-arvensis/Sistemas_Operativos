#include <stdio.h>
int main()
{
    printf("Averigue los tamanios de todos los tipos basicos en su sistema aplicando el operador sizeof() \n");
    char c = 'a';
    int i;
    long l;
    float f;
    double d;

    printf("tamanio de char: %i \n", sizeof(c));
    printf("tamanio de int: %i \n", sizeof(i));
    printf("tamanio de long %d \n", sizeof(l));
    printf("tamanio de float %d \n", sizeof(f));
    printf("tamanio de double %d \n", sizeof(d));

    return 0;
}