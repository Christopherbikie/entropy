#include "stdlib.h"

char *itoa(int value, char *str, int radix)
{
	if (radix < 2 || radix > 36)
	{
		*str = '\0';
		return str;
	}

	char *ptr = str, *ptr1 = str, tmp_char;
	int tmp_value;

	// Find value in ascii, but backwards
	// Using manual modulus, because it saves a division over using the operator
	do
	{
		tmp_value = value;
		value /= radix;
		*ptr++ = "ZYXWVUTSRQPONMLKJIHGFEDCBA9876543210123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[35 + (tmp_value - value * radix)];
	} while (value);

	// Add minus sign if base 10
	if (radix == 10 && tmp_value < 0)
		*ptr++ = '-';

	// End string
	*ptr-- = '\0';

	// Reverse string (but keep null-terminator at end)
	while (ptr1 < ptr)
	{
		tmp_char = *ptr;
		*ptr-- = *ptr1;
		*ptr1++ = tmp_char;
	}

	return str;
}

