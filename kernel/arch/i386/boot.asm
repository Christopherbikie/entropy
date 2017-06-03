; Declare constants for the multiboot header.
MBALIGN  equ  1<<0              ; align loaded modules on page boundaries
MEMINFO  equ  1<<1              ; provide memory map
FLAGS    equ  MBALIGN | MEMINFO ; this is the Multiboot 'flag' field
MAGIC    equ  0x1BADB002        ; 'magic number' lets bootloader find the header
CHECKSUM equ -(MAGIC + FLAGS)

; Declare multiboot header, aligned to 32-bit (4 byte) boundary.
section .multiboot
align 4
	dd MAGIC
	dd FLAGS
	dd CHECKSUM

section .bss
align 4
stack_bottom:
resb 16384 ; 16 KiB
stack_top:

; Linker script specifies _start as the entry point to the kernel, so here it is.
; It doesn't make sence to return from this funtion as the bootloader is gone.
section .text
global _start:function (_start.end - _start)
_start:
	; set up stack
	mov esp, stack_top
	
	extern kernel_main
	call kernel_main

	cli
.hang:
	hlt
	jmp .hang
.end:
