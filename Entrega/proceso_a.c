#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h> /*For mode constants*/
#include <fcntl.h> /*For O_* cinstants*/
#include <string.h>

int main(){
/*COPIADO DEL POWER A VER QUE HACE */
const int SIZE = 4096;
const char *name = "OS"; 
const char *mess0 = "Miau Miau Studying "; 
const char *mess1 = "Operating systems"; 
const char *archivo = "/usr/share/doc/aufs-dkms/filesystems/aufs/design/06mmap.txt";

int shm_fd; 
void *ptr; 

/*create the shared memory segment */
shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

/* configure the size of the shared memory segment*/
ftruncate(shm_fd, SIZE); 

/*now map the shared memory segment in the 
address space of the process*/
ptr = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0); 
if (ptr == MAP_FAILED){
    printf("Map failed\n");
    return -1; 
}

/* Abrimos el archivo solo para lectura */
    int fileDescriptor = open(archivo, O_RDONLY);

    int buffSize = 4096;
    char buff[buffSize];

    /* Copiamos el contenido del txt en buff */
    read(fileDescriptor, buff, buffSize);


/*now write to the shared memory region*/
sprintf(ptr, "%s", buff); 

/* Cerramos el archivo */
/*if (close(fileDescriptor) == -1){
    printf("Error al cerrar el archivo");
}*/

return 0; 
}