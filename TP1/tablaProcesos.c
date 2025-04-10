/*
Observar el archivo include/process.h. en XINU. ¿Qué campos contiene la tabla de procesos
en Xinu?. ¿Piensa que falta algo más que deba contemplar el sistema operativo para gestionar
un proceso?

/* Definition of the process table (multiple of 32 bits) */

/*
struct procent 		// Entry in the process table		
	uint16	prstate;	// Process state: PR_CURR, etc.		//estado del proceso
	pri16	prprio;		// Process priority			        //su prioridad
	char	*prstkptr;	// Saved stack pointer			    //puntero actual de la pila
	char	*prstkbase;	// Base of run time stack		    //direccion base de la pila
	uint32	prstklen;	// Stack length in bytes		    //tamanio correspondiente a la pila
	char	prname[PNMLEN];	// Process name				    //nombre del proceso
	sid32	prsem;		// Semaphore on which process waits //semaforo al que espera
	pid32	prparent;	// ID of the creating process		//ID del proceso padre ??
	umsg32	prmsg;		// Message sent to this process		//mensaje enviado al proceso
	bool8	prhasmsg;	// Nonzero iff msg is valid		    //no cero si el mensaje es valido
	int16	prdesc[NDESC];	// Device descriptors for process	//device descritores del mensaje ?? (I/O)
};

*/