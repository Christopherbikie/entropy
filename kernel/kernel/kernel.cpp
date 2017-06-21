#include <stdio.h>

#include <kernel/tty.h>
#include <kernel/gdt.h>

extern "C"
void kernel_main(void)
{
	gdt_init();

	terminal_initialise();

	printf("Hello, world!\n");
}

