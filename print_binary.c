#include "main.h"
int print_binary(va_list args)
{
	unsigned int n = va_arg(args, unsigned int), mask, i = 31, started = 0, count = 0;
	if (n == 0) { write(1, "0", 1); return (1); }
	for (; i >= 0 && i < 32; i--) { mask = 1u << i; if (n & mask) { write(1, "1", 1); count++; started = 1; } else if (started) { write(1, "0", 1); count++; } }
	return (count);
}
