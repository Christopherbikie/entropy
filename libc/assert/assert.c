#include <assert.h>
#include <stdio.h>

void __assert(const char *file, int line, const char *func, const char *expr)
{
	// TODO: print to stderr
	// TODO: print line number properly
	printf("Assertion failed: %s:%s: %s: \"%s\"", file, line, func, expr);
}

