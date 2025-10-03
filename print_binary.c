#include "main.h"

int print_binary(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;
	int i;
	int started = 0;
	unsigned int mask;

	if (n == 0)
	{
		add_to_buffer('0');
		return (1);
	}
	for (i = 31; i >= 0; i--)
	{
		mask = 1u << i;
		if (n & mask)
		{
			add_to_buffer('1');
			count++;
			started = 1;
		}
		else if (started)
		{
			add_to_buffer('0');
			count++;
		}
	}
	return (count);
}
