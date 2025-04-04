#include <stdio.h>
int main()
{
    printf("Cual es el resultado del siguiente fragmento de codigo? Anticipe su respuesta en base a lo dicho en esta unidad y luego confírmela mediante un programa \n");

    printf("anticipo que el primero se va a truncar, el segundo no y el tercero tampoco, el cuarto no se que hace\n");
    printf("el quinto se va a truncar a 3, el sexto no se, el septimo elimina la parte decimal y la reemplaza con ceros y el octavo tambien es truncado \n");
    printf("%d\n", 20 / 3);
    printf("%f\n", 20 / 3);
    printf("%f\n", 20 / 3.);
    printf("%d\n", 10 % 3);
    printf("%d\n", 3.1416);
    printf("%f\n", (double)20 / 3);
    printf("%f\n", (int)3.1416);
    printf("%d\n", (int)3.1416);

    printf("resultados: el primero se trunco, el segundo quedo nulo, el tercero esta bien, el cuarto me da 1 (?), el quinto dio 77650087 (?) el sexto dio bien, el septimo fue reemplazado completo por ceros y el octavo fue truncado");
}
