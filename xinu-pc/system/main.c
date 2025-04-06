/*  main.c  - main */

#include <xinu.h>


process	main(void)
{


	paint_screen();
        printWallpaper();
	recvclr();
	resume(create(shell, 8192, 50, "shell", 1, CONSOLE));

	/* Wait for shell to exit and recreate it */

	while (TRUE) {
		receive();
		sleepms(200);
		kprintf("\n\nMain process recreating shell\n\n");
		resume(create(shell, 4096, 20, "shell", 1, CONSOLE));
	}
	return OK;
    
}

void printWallpaper(){
  int renglon = 20; 
  int espDer = 400; 
print_text_on_vga(espDer, 10*renglon++, "         $$            $$");
print_text_on_vga(espDer, 10*renglon++, "      $$$  $ $$    $$ $  $$$");
print_text_on_vga(espDer, 10*renglon++, "     $  $  $$  $  $  $$  $  $");
print_text_on_vga(espDer, 10*renglon++, "     $  $$$ $  $$$$  $ $$$ $$");
print_text_on_vga(espDer, 10*renglon++, "    $$$$     $$$  $$$     $$$$");
print_text_on_vga(espDer, 10*renglon++, "   $  $        $  $        $  $");
print_text_on_vga(espDer, 10*renglon++, "   $  $         $$         $  $");
print_text_on_vga(espDer, 10*renglon++, "    $$          $$          $$$");
print_text_on_vga(espDer, 10*renglon++, "   $  $     $$$$  $$$$     $  $");
print_text_on_vga(espDer, 10*renglon++, "   $  $    $$$$$$$$$$$$    $  $");
print_text_on_vga(espDer, 10*renglon++, "    $$$$    $$$$$$$$$$    $$$$");
print_text_on_vga(espDer, 10*renglon++, "     $  $    $$$$$$$$    $  $");
print_text_on_vga(espDer, 10*renglon++, "     $  $     $$$$$$     $  $");
print_text_on_vga(espDer, 10*renglon++, "      $$$$     $$$$     $$$$");
print_text_on_vga(espDer, 10*renglon++, "       $  $     $$     $  $");
print_text_on_vga(espDer, 10*renglon++, "       $  $$$        $$$  $");
print_text_on_vga(espDer, 10*renglon++, "        $$$  $      $  $$$");
print_text_on_vga(espDer, 10*renglon++, "          $  $$$  $$$  $");
print_text_on_vga(espDer, 10*renglon++, "    $$$$$  $$$  $$  $$$ $$$$");
print_text_on_vga(espDer, 10*renglon++, "   $     $  $  $$  $  $     $$");
print_text_on_vga(espDer, 10*renglon++, "   $      $  $$  $$  $      $$");
print_text_on_vga(espDer, 10*renglon++, "   $       $  $  $  $       $");
print_text_on_vga(espDer, 10*renglon++, "   $        $ $$$$ $        $");
print_text_on_vga(espDer, 10*renglon++, "    $        $    $        $");
print_text_on_vga(espDer, 10*renglon++, "   $         $    $         $");
print_text_on_vga(espDer, 10*renglon++, " $$$ $        $    $        $ $$");
print_text_on_vga(espDer, 10*renglon++, "$  $         $$$$$$         $  $");
print_text_on_vga(espDer, 10*renglon++, "$  $   $$$$$$ $  $ $$$$$$   $  $");
print_text_on_vga(espDer, 10*renglon++, "$   $ $    $ $$  $$ $    $ $   $");
print_text_on_vga(espDer, 10*renglon++, " $  $$    $ $ $  $ $ $    $$  $");
print_text_on_vga(espDer, 10*renglon++, "  $  $$$$$ $  $  $  $ $$$$$  $");
print_text_on_vga(espDer, 10*renglon++, "   $      $   $  $   $      $$");
print_text_on_vga(espDer, 10*renglon++, "   $     $    $  $    $     $$");
print_text_on_vga(espDer, 10*renglon++, "    $   $     $  $     $   $$");
print_text_on_vga(espDer, 10*renglon++, "     $$$      $$$$      $$$");

}
