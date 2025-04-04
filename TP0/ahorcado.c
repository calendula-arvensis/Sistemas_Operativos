#include <stdio.h>
#include <stdlib.h> /* para las funciones system y exit */

int main()
{
    /*printf("la linea '#include <stdio.h>' es una directiva de preprocesador que indica incluir en la unidad de traduccion al archivo de cabecera o header stdio.h. Este contiene, entre otras cosas, la declaracion (o prototipo) de la funcion de salida de caracteres printf(), perteneciente a la Biblioteca Standard. Los prototipos se incluyen para advertir al compilador de los tipos de las funciones y de sus argumentos. \n");
    printf("la linea '#include <stdlib.h>' supongo que tambien es una directiva de preprocesador que hace lo mismo pero para las funciones system, exit y otras funciones comunes");
    printf("la linea 'system (/bin/stty raw)' sets the terminal to raw mode, which allows the program to receive all keystrokes directly without any processing by the terminal itself. In raw mode, the terminal does not recognize line ends, backspaces, or other special control characters, and the program must handle these inputs manually.");
    printf("la linea 'system (/ bin / stty sane erase ^ H)' supongo que resetea el input a como estaba antes, investigacion dice: se usa para restaurar la configuración del terminal a un estado normal después de haber activado el modo raw. ");
*/
    int c;

    /* Decirle al sistema que el modo input es RAW */
    system("/bin/stty raw");
    char restantes[] = "facultad";
    char palabra[sizeof(restantes) - 1];
    char vidas = 5;
    char encontrado, quedanLetras = 0;

    for (int i = 0; i < sizeof(palabra); i++)
    {
        palabra[i] = '_';
    }
    do
    {
        printf("\n vidas = %d ingrese una letra (0 para salir): ", (char)vidas);
        c = getchar();
        getchar(); /*consume el salto de linea */
        encontrado = 0;
        quedanLetras = 0;
        if (c != 0)
        {
            for (int i = 0; i < sizeof(restantes) - 1; i++)
            {
                if (restantes[i] == c)
                {
                    restantes[i] = 0;
                    palabra[i] = c;
                    encontrado = 1;
                }
                else if (palabra[i] == '_')
                {
                    quedanLetras = 1;
                }
                printf("%c", palabra[i]);
            }
            if (encontrado < 1)
            {
                vidas--;
            }
        }
    } while (c != '0' && vidas > 0 && quedanLetras > 0);
    if (quedanLetras == 0)
    {
        printf("\n haz ganado!\n");
    }
    else
    {
        printf("\nhaz perdido :(\n");
    }

    system("/bin/stty sane erase ^H");
}