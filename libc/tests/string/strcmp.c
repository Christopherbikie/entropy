#include "string_test.h"
#include "libctest.h"
#include <string.h>

void test_string_strcmp()
{
	test(!strcmp("qwerty", "qwert"), "Identical strings returns non-zero");
}

