#include "main.h"

int print_unsigned(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int temp = n;
	int count = 0, divisor = 1;
	char c;

	if (n == 0)
	{
		add_to_buffer('0');
		return (1);
	}
	while (temp / 10)
	{
		divisor *= 10;
		temp /= 10;
	}
	while (divisor > 0)
	{
		c = (n / divisor) + '0';
		add_to_buffer(c);
		count++;
		n %= divisor;
		divisor /= 10;
	}
	return (count);
}
