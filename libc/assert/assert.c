#include <assert.h>

void __assert(const char *file, int line, const char *func, const char *expr)
{
	// TODO: print to stderr
	printf("Assertion failed: %s:%s: %s: \"%s\"", file, line, func, expr);
}

