#include <stdio.h>

#include <kernel/gdt.h>
#include <kernel/idt.h>
#include <kernel/isrs.h>
#include <kernel/tty.h>

extern "C"
void kernel_main(void)
{
	terminal_initialise();
	
	gdt_init();
	idt_init();
	isrs_init();

	printf("Hello, world!\n");
}
