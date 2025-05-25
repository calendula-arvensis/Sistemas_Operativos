#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h> /*For mode constants*/
#include <fcntl.h> /*For O_* cinstants*/
#include <string.h>

int file_get_size(const char *nombre_de_archivo);
int main(){
    char *archivo = "./ej1.txt";
    int size = file_get_size(archivo); 
    if(size > 0){
    char buff[size];
    int fileDescriptor = open(archivo, O_RDONLY);
    if(fileDescriptor < 0){
        printf("error al buscar el archivo");
        return -1; 
    } 
    read(fileDescriptor, buff, size); 
    for (int j = size-1; j >= 0; j--)
    {
        printf("%c", buff[j]);
    }
    printf("\n");
    close(fileDescriptor);
}
return 0; 
}

int file_get_size(const char *nombre_de_archivo){
    int size = 0; 
    int fileDescriptor = open(nombre_de_archivo, O_RDONLY);
    if(fileDescriptor < 0){
        printf("error al buscar el archivo");
        return -1; 
    } 
    char i, r; 
    do{
        /*al leer una posicion el fileDescriptor queda posicionado un caracter mas adelante */
        r = read(fileDescriptor, &i, 1);
        size++;
        printf("i es %c y largo: %d\n", (char)i, size);
        
    } while(r==1);
    close(fileDescriptor);
    return size; 
}
