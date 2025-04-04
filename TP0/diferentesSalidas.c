#include <stdio.h>
int main()
{
    char a = 'M';
    printf("a = %i \n", a);
    printf("La letra %c \n", a);
    char sensor = 'b';
    float temp = 23;
    printf("La temperatura de %c es %i", sensor, temp);

    printf("Al armar un string con variables, se declara una variable interna con el signo porcentaje y la inicial de su tipo de dato, luego al final del texto se pone una ,(coma) y se ponen EN ORDEN las variables que van a llenar los espacios declarados (del tipo de dato declarado)");
    return 0;
}