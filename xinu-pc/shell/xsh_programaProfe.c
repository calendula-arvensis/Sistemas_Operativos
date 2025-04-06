
/* ex2.c - main, sndA, sndB */

#include <xinu.h>

int xsh_programaProfe(){
    main2();
    return 0;
}
void	sndA(void), sndB(void),sndch(char ch);

//Variables globales para almacenar los PIDS de los procesos.
pid32 pidA, pidB; /*pid32 es un tipo de datos entero de 32 bits quealmacena el id ùnico de un proceso. */
/*------------------------------------------------------------------------
 * main  --  example of creating processes in Xinu
 *------------------------------------------------------------------------
 */
/*xinu ya tiene su proceso main, no puede haber otro */
void	main2(void)
{
    /*
    pidA = create(sndA, 1024, 20, "process 1", 0);
    pidB = create(sndB, 1024, 20, "process 2", 0);
	resume( pidA );
	resume( pidB );

    sleep(3);
    kill(pidA);
    kill(pidB);
    */

    /*FORMA DE CREAR UN PROCESO UN XINU
    resume (create(funcion, cantBytesPila, prioridad, nombreDelProceso, cantArgumentos, Argumentos))
    funcion: es donde se comienza a ejecutar el programa 
    1024 representa 1KB, entonces 8KB son 8x1024*/

    resume( create(sndch, 8192, 20, "send A", 1, 'A') );
	resume( create(sndch, 8192, 20, "send B", 1, 'B') );

}

/*------------------------------------------------------------------------
 * sndch  --  output a character on a serial device indefinitely
 *------------------------------------------------------------------------
 */
void	sndch(char ch)
{

	while ( 1 )
		putc(CONSOLE, ch);
}
/*------------------------------------------------------------------------
 * sndA  --  repeatedly emit 'A' on the console without terminating
 *------------------------------------------------------------------------
 */
/*
void	sndA(void)
{
	while( 1 )
		putc(CONSOLE, 'A');
}
*/
/*------------------------------------------------------------------------
 * sndB  --  repeatedly emit 'B' on the console without terminating
 *------------------------------------------------------------------------
 */
/*
void	sndB(void)
{
	while( 1 )
		putc(CONSOLE, 'B');
}
*/