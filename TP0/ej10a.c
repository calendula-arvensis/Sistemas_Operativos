#include <stdio.h>
int main()
{
    printf("Que hace falta corregir para que la variable r contenga la division exacta de a y b \n");

    printf(" int a, b; \n");
    printf(" float r; \n");
    printf(" a = 5; \n");
    printf(" b = 2;\n");
    printf(" r = a / b; \n");

    int a, b;
    float r;
    a = 5;
    b = 2;
    r = (float)a / b;

    printf("hay que castear el tipo de dato float para que la division tenga en cuenta los decimales.\n");
    printf("r = (float)a / b, esto da de resultado r = %f \n", r);
}