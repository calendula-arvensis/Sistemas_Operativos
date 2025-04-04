#include <stdio.h>
int main()
{
    printf("Cual es el rango numerico de i y j en su PC? sea i un char y j un unsigned char \n");
    char i = 'a';
    unsigned char j = 'a';

    int tamanio = sizeof(i);
    int tamanio2 = sizeof(j);
    printf("tamanio de char: %i \n", tamanio);
    printf("tamanio unsigned char: %i \n", tamanio2);
    printf("ambos ocupan un byte, entonces \n");

    printf("el rango de char va de: %d a %d \n", (char)0x80, (char)0x7F);
    printf("el rango de unsigned char va de: %d a %d \n", (unsigned char)0x00, (unsigned char)0xFF);
    return 0;
}