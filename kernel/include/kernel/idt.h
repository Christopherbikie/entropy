#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

void idt_init();

void idt_set_gate(uint8_t n, uint32_t base, uint16_t selector, uint8_t type_attr);

#ifdef __cplusplus
}
#endif

