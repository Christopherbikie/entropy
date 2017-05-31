#include <stdio.h>

#include "kernel/tty.h"

extern "C"
void kernel_main(void)
{
	terminal_initialise();
	printf("Hello, world!\n");
}
