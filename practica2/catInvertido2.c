#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h> /*For mode constants*/
#include <fcntl.h> /*For O_* cinstants*/
#include <string.h>

#include <ctype.h> // what

#define NEW_FILE "cat2.pgm"
int file_get_size(const char *nombre_de_archivo);
int obtener_offset_cabecera(const char *archivo);
int main(){
    char *archivo = "cat.pgm";
    int cabecera = 15; 
    //obtener el tamanio del archivo
    int size = file_get_size(archivo);  
    if (size >0){
        /*abrimos el segmento de memoria compartida*/
        int shm_fd = shm_open("/cat_shm", O_RDONLY, 0666);
        if(shm_fd < 0){
            printf("shared memory failed"); 
            return -1; 
        }

        /*mapeamos el segmento de memoria y guardamos la direccion*/
        void *ptr = mmap(0, size, PROT_READ, MAP_SHARED, shm_fd, 0);
        if(ptr == MAP_FAILED){
            printf("map failed\n");
            exit (-1);
        }
        /*armamos el arreglo que va a contener la nueva imagen invertida*/
        unsigned char nuevaImagen[size]; 

        //obtener los primeros bytes de formato y copiarlos como estan
            int offset = obtener_offset_cabecera(archivo);
            printf("La cabecera termina en el byte: %d\n", offset);
            memcpy(nuevaImagen, ptr, offset);

        //los proximos bytes los copiamos de forma inversa
        int i = offset; 
        for (int j = size-1; j >= offset; j--)
        {
            nuevaImagen[i] = ((unsigned char *)ptr)[j];
            i++;
        }

        /*abrimos un nuevo archivo de salida */
        int out_fileDescriptor = open(NEW_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if(out_fileDescriptor <0){
            printf("error en output"); 
            return -1; 
        }

        /*copiamos la nueva imagen al nuevo archivo*/
        write(out_fileDescriptor, &nuevaImagen[0], size);

        /*cerramos el fd*/
        close(out_fileDescriptor);
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

int obtener_offset_cabecera(const char *archivo) {
    FILE *fp = fopen(archivo, "rb");
    if (!fp) {
        perror("fopen");
        return -1;
    }

    char linea[256];
    int lineas_validas = 0;
    int offset = 0;

    while (fgets(linea, sizeof(linea), fp)) {
        offset += strlen(linea);

        // Ignorar líneas de comentario
        if (linea[0] == '#') continue;

        // Contar línea válida
        lineas_validas++;

        if (lineas_validas == 3) {
            break; // Ya leímos: formato, tamaño y valor máximo
        }
    }

    fclose(fp);
    return offset;
}