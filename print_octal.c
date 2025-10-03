#include "main.h"

int print_octal(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;
	char buffer[32];
	int i = 0;

	if (n == 0)
	{
		add_to_buffer('0');
		return (1);
	}
	while (n > 0)
	{
		buffer[i++] = (n % 8) + '0';
		n /= 8;
	}
	while (i > 0)
	{
		add_to_buffer(buffer[--i]);
		count++;
	}
	return (count);
}
