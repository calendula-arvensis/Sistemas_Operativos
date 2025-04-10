/*
On UNIX and Linux systems, we can obtain a listing of processes by using the ps command.
For example, the command 'ps -el' will list complete information for all processes currently active in the system. 

ps -eo pid,ppid,user,state,comm
donde: 
    pid: ID del proceso
    ppid: ID del proceso padre
    user: usuario propietario
    state: estado del proceso (lo que te interesa)
    comm: nombre del comando

A parent process may wait for the termination of a child process by using
the wait() system call. The wait() system call is passed a parameter that
allows the parent to obtain the exit status of the child. This system call also
returns the process identifier of the terminated child so that the parent can tell
which of its children has terminated:
pid t pid;
int status;
pid = wait(&status);

A process that has terminated, but whose parent has not yet called wait() , is known as a ZOMBIE process. 
All processes transition to this state when they terminate, but generally they exist as zombies only briefly. 
Once the parent calls wait() , the process identifier of the zombie process and its entry in the process table are released.

Now consider what would happen if a parent did not invoke wait() and instead terminated,
thereby leaving its child processes as ORPHANS. Traditional UNIX systems addressed this scenario by assigning the init 
process as the new parent to orphan processes. (Recall from Section 3.3.1 that init serves as the root of the process hierarchy 
in UNIX systems.) The init process periodically invokes wait() , thereby allowing the exit status of any orphaned process to be 
collected and releasing the orphan’s process identifier and process-table entry.
Although most Linux systems have replaced init with systemd , the latter process can still serve the same role, although Linux 
also allows processes other than systemd to inherit orphan processes and manage their termination.

POSIBLES ESTADOS DE LOS PROCESOS: 
R	Running	                Ejecutándose o listo para ejecutarse (ready)
S	Sleeping	            Esperando algún evento (espera corta)
D	Uninterruptible sleep	Espera profunda (esperando I/O, no se puede interrumpir con signals)
Z	Zombie	                Proceso terminado, pero su padre aún no lo ha recogido con wait()
T	Stopped	                Detenido (por señal SIGSTOP, o debugger)
I	Idle	                Proceso inactivo (en algunos sistemas modernos como macOS ARM)
X	Dead	                Proceso muerto (estado raro, no debería verse comúnmente)
*/