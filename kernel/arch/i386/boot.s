# Declare constants for the multiboot header.
.set ALIGN,    1<<0
.set MEMINFO,  1<<0
.set FLAGS,    ALIGN | MEMINFO
.set MAGIC,    0x1BADB002
.set CHECKSUM, -(MAGIC + FLAGS)

# Declare multiboot header, aligned to 32-bit (4 byte) boundary.
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

.section .bss
.align 16
stack_bottom:
.skip 16384 # 16 KiB
stack_top:

# Linker script specifies _start as the entry point to the kernel, so here it is.
# It doesn't make sence to return from this funtion as the bootloader is gone.
.section .text
.global _start
.type _start, @function
_start:
	# Set up stack
	mov $stack_top, %esp

	call kernel_main

	# If the system has nothing to do, go into an infinite loop.
	cli
1:	hlt
	jmp 1b

.size _start, . - _start
