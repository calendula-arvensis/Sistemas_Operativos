#include <stdio.h>
int main()
{
    printf("Los tipos basicos de declaracion de variables son: \n");
    printf("-char (un elemento del tamanio de un byte) \n");
    printf("-int (numero entero con signo) \n");
    printf("-long (un entero largo) \n");
    printf("-float (un numero en punto flotante) \n");
    printf("-double (un numero en punto flotante, doble presicion) \n");
    printf("Los tipos enteros (char, int y long) admiten los modificadores signed (con signo) y unsigned (sin signo).");
    printf("Un objeto de datos unsigned utiliza todos sus bits para representar magnitud;");
    printf(" un signed utiliza un bit para signo,en representacion complemento a dos.\n");
    printf("ejemplo: unsigned int edad");
    return 0;
}