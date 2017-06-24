#include <kernel/idt.h>
#include <string.h>
#include <stdio.h>

#define IDT_NUM_ENTRIES 256

struct idt_entry
{
	uint16_t base_low;
	uint16_t selector;
	uint8_t zero;
	uint8_t type_attr;
	uint16_t base_high;
} __attribute__((packed));

struct idt_ptr
{
	uint16_t limit;
	uint32_t base;
} __attribute__((packed));

struct idt_entry idt[IDT_NUM_ENTRIES];

extern void idt_load(uint32_t idt_ptr);

void idt_set_gate(uint8_t n, uint32_t base, uint16_t selector, uint8_t type_attr)
{
	idt[n].base_low = base & 0xFFFF;
	idt[n].base_high = (base >> 16) & 0xFFFF;
	idt[n].selector = selector;
	idt[n].zero = 0;
	idt[n].type_attr = type_attr;
}

void idt_init()
{
	printf("Initialising the IDT... ");
	
	struct idt_ptr idt_ptr;
	idt_ptr.limit = sizeof(struct idt_entry) * IDT_NUM_ENTRIES - 1;
	idt_ptr.base = (uint32_t) &idt;

	memset(&idt, 0x00, sizeof(struct idt_entry) * IDT_NUM_ENTRIES);
	
	idt_load((uint32_t) &idt_ptr);
	
	printf("done\n");
}

