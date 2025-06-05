#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h> /*For mode constants*/
#include <fcntl.h> /*For O_* cinstants*/
#include <string.h>

int file_get_size(const char *nombre_de_archivo);
int main(){
    char *archivo = "cat.pgm";
    //obtener el tamanio del archivo
    int size = file_get_size(archivo); 
    if(size > 0){

        /*create the shared memory segment */
        int shm_fd = shm_open("/cat_shm", O_CREAT | O_RDWR, 0666);
        /* configure the size of the shared memory segment*/
        ftruncate(shm_fd, size); 

        /*now map the shared memory segment in the address space of the process*/
        void *ptr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0); 
        if (ptr == MAP_FAILED){
            printf("Map failed\n");
            return -1; 
        }

        /*abrimos el archivo con solo lectura */
        int fileDescriptor = open(archivo, O_RDONLY);
        if(fileDescriptor < 0){
          printf("error al buscar el archivo");
          return 1; 
        } 

        /*pasamos la imagen a la seccion de memoria compartida*/
        read(fileDescriptor, ptr, size); 
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
    while ((r = read(fileDescriptor, &i, 1)) == 1) {
        size++;
    }
 
//    do{
//        /*al leer una posicion el fileDescriptor queda posicionado un caracter mas adelante */
//        r = read(fileDescriptor, &i, 1);
//        size++;
//        //printf("i es %c y largo: %d\n", (char)i, size);
//        
//    } while(r==1);
    close(fileDescriptor);
    return size; 
}