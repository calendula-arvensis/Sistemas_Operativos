#include <stdio.h>
int main()
{
    printf("Prepare un programa con una variable de tipo char y otra de tipo unsigned char. Inicialice ambas variables con los valores máximos de cada tipo \n");
    char i = 0x7F;
    unsigned char j = 0xFF;

    int tamanio = sizeof(i);
    int tamanio2 = sizeof(j);
    printf("char: %i \n", i);
    printf("unsigned char: %i \n", j);

    printf("el rango de char va de: %d a %d \n", (char)0x80, (char)0x7F);
    printf("el rango de unsigned char va de: %d a %d \n", (unsigned char)0x00, (unsigned char)0xFF);

    i++;
    j++;
    printf("despues de incrementar el char maximo: %d \n", (char)i);
    printf("despues de incrementar el unsigned char maximo: %d \n", (unsigned char)j);
    return 0;
}