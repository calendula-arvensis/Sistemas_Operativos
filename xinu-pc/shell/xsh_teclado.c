#include <xinu.h>
extern paint_screen();

shellcmd xsh_teclado(int32 nargs, char *args[]){
    int tamanio = 20; 
    unsigned char tecla; 
    char t[80]; 
    int inicio = 0; 
    paint_screen();
    open(KEYBOARD, NULL, NULL); 

    for (int i = 0; i < tamanio; i++)
    {
        read(KEYBOARD, &tecla, 1);
        sprintf(t, "tecla 0x%x ", tecla);
        print_text_on_vga(300, 300 + inicio, t);
        inicio = inicio + 15; 
    }
    close(KEYBOARD);
    exit();
}