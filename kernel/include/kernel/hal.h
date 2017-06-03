#ifndef ARCH_I386_HAL_H
#define ARCH_I386_HAL_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

uint8_t inportb(uint16_t port);
void outportb(uint16_t port, uint8_t value);

#ifdef __cplusplus
}
#endif

#endif // ARCH_I386_HAL_H

