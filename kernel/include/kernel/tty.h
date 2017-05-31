#ifndef _KERNEL_TTY_H
#define _KERNEL_TTY_H

#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif

void terminal_initialise(void);

void terminal_putchar(char c);
void terminal_write(const char *data, size_t size);
void terminal_writestr(const char *data);

void terminal_clear(void);

#ifdef __cplusplus
}
#endif

#endif
