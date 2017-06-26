#include <stdio.h>

#include "include/string_test.h"

int main()
{
	printf("===============\n");
	printf("Libc Unit Tests\n");
	printf("===============\n");

	test_string_strcmp();

	return 0;
}

