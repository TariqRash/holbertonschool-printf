#include "main.h"

int get_int_length(long n)
{
	int len = 0;

	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int print_int(long n, format_t spec)
{
	int count = 0, len, pad, i;
	unsigned long num;
	char c;
	format_t empty;

	empty.flags = 0;
	empty.length = 0;
	empty.width = 0;
	empty.precision = -1;

	len = get_int_length(n);
	if (n >= 0 && (spec.flags & (FLAG_PLUS | FLAG_SPACE)))
		len++;
	if (n < 0)
		len++;
	pad = spec.width - len;

	if (!(spec.flags & FLAG_MINUS) && pad > 0)
		for (i = 0; i < pad; i++)
			count += write(1, " ", 1);
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
		count += print_int(num / 10, empty);
	c = (num % 10) + '0';
	write(1, &c, 1);
	count++;
	if ((spec.flags & FLAG_MINUS) && pad > 0)
		for (i = 0; i < pad; i++)
			count += write(1, " ", 1);
	return (count);
}

int print_number(va_list args, format_t spec)
{
	long n;

	if (spec.length == LENGTH_LONG)
		n = va_arg(args, long);
	else if (spec.length == LENGTH_SHORT)
		n = (short)va_arg(args, int);
	else
		n = va_arg(args, int);
	return (print_int(n, spec));
}
