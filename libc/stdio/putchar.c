#include "stdio.h"

#if defined(__is_libk)
#include "kernel/tty.h"
#endif

int putchar(int ic)
{
#if defined(__is_libk)
	char c = (char) ic;
	terminal_write(&c, sizeof(c));
#elif defined(__unix__) || (defined(__APPLE__) && defined(__MACH__)) // building x86 for unit testing
	char c = (char) ic;
	write(1, &c, 1);
#else
	// TODO: Implement stdio and the write system call.
#endif
	return ic;
}
