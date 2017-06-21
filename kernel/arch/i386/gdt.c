#include "kernel/gdt.h"

struct gdt_entry gdt[3];

static struct gdt_entry make_desc(uint32_t base, uint32_t limit, enum seg_privilege dpl, enum seg_executable exec, enum seg_granularity gran) 
{
	struct gdt_entry desc;

	desc.limit_low = limit & 0xFFFF;       // Limit 0:15
	desc.base_low = base & 0xFFFF;         // Base 0:15
	desc.base_mid = (limit >> 16) & 0xFF;  // Base 16:23
	desc.access =                          // Access byte
		(1 << 7)                              // Present bit
		| ((dpl & 0x7) << 5)                  // Description Privilege Level
		| (1 << 4)                            // 1
		| (exec << 3)                         // Executable bit
		| (0 << 2)                            // Direction/conforming bit
		| (1 << 1)                            // Read/write bit
		| (0 << 0);                           // Accessed bit
	desc.limit_high_flags =                // Flags and limit 16:19
		(gran << 7)                           // Granularity
		| (1 << 6)                            // Size bit (16/32)
		| (0 << 5)                            // Reserved (not x86-64)
		| (0 << 4)                            // Reserved
		| ((limit >> 16) & 0xFF);             // limit 16:19
	desc.base_high = (base >> 24) & 0xFF;  // Base 24:31

	return desc;
}

static uint64_t make_gdtr(uint32_t limit, void *base)
{
	return limit | ((uint64_t) (uint32_t) base << 16);
}

void gdt_init()
{
	gdt[0] = (struct gdt_entry) {0, 0, 0, 0, 0, 0};
	gdt[1] = make_desc(0, 0xFFFFFFFF, 0, EXEC_CODE, GRAN_PAGE);
	gdt[2] = make_desc(0, 0xFFFFFFFF, 0, EXEC_DATA, GRAN_PAGE);

	uint32_t gdtr = make_gdtr(sizeof(gdt) - 1, gdt);
	asm volatile("lgdt %0" : :"m" (gdtr));
}

