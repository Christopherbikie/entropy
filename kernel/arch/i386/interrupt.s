%macro ISR_STUB 1
	global isr_stub_%1
	isr_stub_%1:
		cli
		push byte 0
		push byte %1
		jmp isr_common_stub
%endmacro

%macro ISR_STUB_ERR 1
	global isr_stub_%1
	isr_stub_%1:
		cli
		push byte %1
		jmp isr_common_stub
%endmacro

ISR_STUB     0
ISR_STUB     1
ISR_STUB     2
ISR_STUB     3
ISR_STUB     4
ISR_STUB     5
ISR_STUB     6
ISR_STUB     7
ISR_STUB_ERR 8
ISR_STUB     9
ISR_STUB_ERR 10
ISR_STUB_ERR 11
ISR_STUB_ERR 12
ISR_STUB_ERR 13
ISR_STUB_ERR 14
ISR_STUB     15
ISR_STUB     16
ISR_STUB     17
ISR_STUB     18
ISR_STUB     19
ISR_STUB     20
ISR_STUB     21
ISR_STUB     22
ISR_STUB     23
ISR_STUB     24
ISR_STUB     25
ISR_STUB     26
ISR_STUB     27
ISR_STUB     28
ISR_STUB     29
ISR_STUB     30
ISR_STUB     31

extern isr_handler

isr_common_stub:
	pusha
	mov ax, ds
	push eax

	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	
	call isr_handler

	pop eax
	mov gs, ax
	mov fs, ax
	mov es, ax
	mov ds, ax

	popa
	add esp, 0x08 ; Clean up pushed error code & ISR number
	sti
	iret

