#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

enum seg_executable
{
	EXEC_DATA = 0, // Data segment
	EXEC_CODE = 1  // Code segment
};

enum seg_granularity
{
	GRAN_BYTE = 0, // 1 byte granularity
	GRAN_PAGE = 1  // 4 kB granualrity
};

enum seg_privilege
{
	PRIV_KERNEL = 0, // Kernel mode (ring 0)
	PRIV_USR    = 3  // User mode (ring 3)
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

void gdt_init();

#ifdef __cplusplus
}
#endif

