#include "main.h"

int print_int_spec(long n, format_t spec)
{
	int count = 0;
	unsigned long num;
	char c;

	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		num = -n;
	}
	else
	{
		if (spec.flags & FLAG_PLUS)
		{
			write(1, "+", 1);
			count++;
		}
		else if (spec.flags & FLAG_SPACE)
		{
			write(1, " ", 1);
			count++;
		}
		num = n;
	}
	if (num / 10)
		count += print_int_spec(num / 10, (format_t){0, 0});
	c = (num % 10) + '0';
	write(1, &c, 1);
	count++;
	return (count);
}

int print_number_spec(va_list args, format_t spec)
{
	long n;

	if (spec.length == LENGTH_LONG)
		n = va_arg(args, long);
	else if (spec.length == LENGTH_SHORT)
		n = (short)va_arg(args, int);
	else
		n = va_arg(args, int);
	return (print_int_spec(n, spec));
}
