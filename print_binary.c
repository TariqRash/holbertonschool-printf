#include "main.h"

int print_binary(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int mask;
	int i;
	int started = 0;
	int count = 0;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	for (i = 31; i >= 0; i--)
	{
		mask = 1u << i;
		if (n & mask)
		{
			write(1, "1", 1);
			count++;
			started = 1;
		}
		else if (started)
		{
			write(1, "0", 1);
			count++;
		}
	}
	return (count);
}
