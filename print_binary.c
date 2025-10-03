#include "main.h"

int print_binary(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0, i, started = 0;
	unsigned int mask = 1U << 31;

	if (n == 0)
	{
		add_to_buffer('0');
		return (1);
	}
	for (i = 0; i < 32; i++)
	{
		if (n & mask)
			started = 1;
		if (started)
		{
			add_to_buffer((n & mask) ? '1' : '0');
			count++;
		}
		mask >>= 1;
	}
	return (count);
}
