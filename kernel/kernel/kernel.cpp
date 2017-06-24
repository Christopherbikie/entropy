#include <stdio.h>

#include <kernel/gdt.h>
#include <kernel/idt.h>
#include <kernel/isrs.h>
#include <kernel/tty.h>

extern "C"
void kernel_main(void)
{
	terminal_initialise();
	
	printf("\nEntopy kernel v0.0.1\n\n");
	printf("Initialising CPU (i386)\n");
	
	gdt_init();
	idt_init();
	isrs_init();
	
	printf("\nHello, world!\n");
}
