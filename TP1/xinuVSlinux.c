/*
Douglas Comer en el libro que documenta la implementación de Xinu dice:
The name stands for Xinu Is Not Unix. As we will see, the internal structure of Xinu differs
completely from the internal structure of Unix (or Linux). Xinu is smaller, more elegant, and easier
to understand.
Ahora compare las funciones que se utilizan en Linux y en Xinu para pedirle luego al sistema
crear procesos. ¿Cuál es más fácil en su opinión?, ¿las funciones para realizar system calls en
Linux o en Xinu? Si su respuesta fue Linux, entonces ¿por qué piensa que Douglas Comer diría
que Xinu es más elegante y más fácil de entender?

EN LINUX
Para crear procesos, se usa principalmente:
    fork() → duplica el proceso actual
    exec() → reemplaza el proceso actual con uno nuevo
    clone() → más bajo nivel, usado por fork() internamente
    vfork() → variante más ligera de fork()
Estas funciones:
    Son potentes
    Manejan espacios de memoria separados
    Son parte de un ecosistema más complejo: señales, pipes, threads, etc.
Pero también:
    Son más difíciles de entender (por ejemplo, fork() devuelve dos valores distintos)
    Dependen fuertemente del comportamiento del kernel y la libc

EN XINU
Para crear un proceso se usa:
pid32 pid = create(func, stack_size, priority, name, nargs, ...);
Y luego se activa con:
resume(pid);
Más directo y controlado.
    create() aloca el PCB y pila, inicializa contexto
    resume() lo pone en READY
    No hay fork, no hay multitarea con memoria separada ni espacio de usuario vs kernel

Xinu es más fácil de entender para aprender sistemas operativos.
    Tiene menos capas de abstracción
    No depende del hardware en tiempo real (ni MMU, ni protección de memoria)
    Tiene código fuente corto y accesible
    No depende de syscall wrappers ni bibliotecas externas
En cambio, Linux es más difícil, aunque más poderoso:
    Fork y exec tienen semánticas complejas
    Maneja memoria protegida, múltiples usuarios, permisos, signals, file descriptors…
    Es modular pero inmenso: millones de líneas de código

Xinu está pensado como un sistema educativo:
    Su objetivo es enseñar cómo se implementa un sistema operativo desde cero.
    Cada componente (scheduler, syscall, proceso, memoria, etc.) es visible, controlado y personalizable.
    El diseño de Xinu es determinista y sencillo. No hay “magia detrás del kernel”.
Linux, en cambio:
    Está hecho para ser usado, no para ser fácil de entender.
    Tiene que soportar millones de escenarios, hardware y usuarios distintos.
    Está lleno de optimizaciones, excepciones y corner cases.
*/