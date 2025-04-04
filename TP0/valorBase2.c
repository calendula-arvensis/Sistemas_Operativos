#include <stdio.h>
int main()
{
    printf("Cual es el valor en base 2 (binario) de i, j, k \n");
    char i = 'a';
    char j = 77;
    char k = 0x4D;

    printf("el char %c tiene de valor %d, que en binario es: %d ,verificacion: %d \n", i, (char)i, 1100001, (char)0x61);
    printf("el char %c tiene de valor %d, que en binario es: %d ,verificacion: %d \n", j, (char)j, 1001101, (char)0x4D);
    printf("el char %c tiene de valor %d, que en binario es: %d ,verificacion: %d \n", k, (char)k, 1001101, (char)0x4D);
    printf("el char k y j representan el mismo valor \n");
    return 0;
}