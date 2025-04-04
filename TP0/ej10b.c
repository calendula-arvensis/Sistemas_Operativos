#include <stdio.h>
int main()
{
    printf("Que resultado puede esperarse del siguiente fragmento de codigo \n");

    printf("  int a, b, c, d; \n");
    printf(" a = 1; \n");
    printf(" b = 2; \n");
    printf(" c = a / b;\n");
    printf(" d = a / c; \n");

    int a, b, c, d;
    a = 1;
    b = 2;
    c = a / b;
    /*d = a / c; */

    printf("de resultado da: c = %d \n", c);
    printf("como c da cero, la division en d aborta al programa y no da ningun resultado \n");
}