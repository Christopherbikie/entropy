#include <stdint.h>

#include "kernel/gdt.h"

#define SEGMENT_BASE    0
#define SEGMENT_LIMIT   0xFFFFF

#define CODE_RX_TYPE    0xA
#define DATA_RW_TYPE    0x2

#define GDT_NUM_ENTRIES 5

enum seg_privilege
{
	PRIV_KERNEL = 0, // Kernel mode (ring 0)
	PRIV_USER   = 3  // User mode (ring 3)
};

struct gdt_entry
{
	uint16_t limit_low;
	uint16_t base_low;
	uint8_t base_mid;
	uint8_t access;
	uint8_t limit_high_flags;
	uint8_t base_high;
} __attribute__((packed));

struct gdt_ptr
{
	uint16_t limit;
	uint32_t base;
} __attribute__((packed));

struct gdt_entry gdt[GDT_NUM_ENTRIES];

void gdt_load_and_set(uint32_t gdtr);

static struct gdt_entry make_desc(enum seg_privilege dpl, uint8_t type)
{
	struct gdt_entry desc;

	desc.limit_low = SEGMENT_LIMIT & 0xFFFF;      // Limit 0:15
	desc.base_low = SEGMENT_BASE & 0xFFFF;        // Base 0:15
	desc.base_mid = (SEGMENT_BASE >> 16) & 0xFF;  // Base 16:23
	desc.access =                                 // Access byte
		(0x01 << 7)                                  // Segment present in memory
		| ((dpl & 0x03) << 5)                        // Descriptor privilege level
		| (0x01 << 4)                                // Descriptor type (0 = system, 1 = code or data)
		| (type & 0x0F);                             // Segment type, describes how it can be accessed
	desc.limit_high_flags =                       // Limit 16:19 and flags
		(0x01 << 7)                                  // Granularity (1 = page)
		| (0x01 << 6)                                // Size of operation (0 = 16 bits, 1 = 32 bits)
		| (0x00 << 5)                                // 1 = 64 bit code
		| (0x00 << 4)                                // "available for use by system software"
		| ((SEGMENT_LIMIT >> 16) & 0x0F);            // Limit 15:19
	desc.base_high = (SEGMENT_BASE >> 24) & 0xFF; // Base 24:31
	
	return desc;
}

void gdt_init()
{
	gdt[0] = make_desc(0, 0);
	gdt[1] = make_desc(PRIV_KERNEL, CODE_RX_TYPE);
	gdt[2] = make_desc(PRIV_KERNEL, DATA_RW_TYPE);
	gdt[3] = make_desc(PRIV_USER, CODE_RX_TYPE);
	gdt[4] = make_desc(PRIV_USER, DATA_RW_TYPE);

	struct gdt_ptr gdt_ptr;
    gdt_ptr.limit = sizeof(struct gdt_entry) * GDT_NUM_ENTRIES;
    gdt_ptr.base = (uint32_t) &gdt;
	
	gdt_load_and_set((uint32_t) &gdt_ptr);
}
