#include "libctest.h"
#include <stdio.h>

void __test_fail(const char *file, int line, const char *func, const char *msg)
{
	printf("Test failed: %s:{line}: %s: %s", file, /*line,*/ func, msg);
}

