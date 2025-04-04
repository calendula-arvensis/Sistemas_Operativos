#include <stdio.h>
int main()
{
    printf("Cuales de entre estas declaraciones contienen errores? \n");
    // integer a;
    short i, j, k;
    // long float(h);
    double long d3;
    // unsigned float n;
    // char 2j;
    int MY;
    float ancho, alto; // long;
    // bool i;

    printf("'integer a;' no existe el tipo de dato integer, deberia decir 'int' \n");
    printf("'long float(h);' un dato no puede ser de mas de un tipo de dato, hay que elegir entre 'long' y 'float'\n");
    printf("'unsigned float n;' los float no pueden ignorar el signo \n");
    printf("'char 2j;' las variables no pueden empezar con numeros\n");
    printf("'float ancho, alto, long;' 'long' es una palabra reservada, no puede ser nombre de variable\n");
    printf("'bool i;' el tipo bool o boleano no existe \n");
    return 0;
}