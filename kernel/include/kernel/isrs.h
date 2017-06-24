#include <stdint.h>

struct registers
{
	uint32_t ds;
	uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
	uint32_t int_no, err_code;
	uint32_t eip, cs, eflags, useresp, ss;
} __attribute__((packed));

#ifdef __cplusplus
extern "C"
{
#endif

void isrs_init();

#ifdef __cplusplus
}
#endif
