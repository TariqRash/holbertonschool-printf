#include "main.h"

int get_ulong_length(unsigned long n)
{
	int len = 0;

	if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int print_ulong(unsigned long n)
{
	int count = 0;
	char c;

	if (n / 10)
		count += print_ulong(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	count++;
	return (count);
}

int print_unsigned_spec(va_list args, format_t spec)
{
	unsigned long n;
	int count = 0, len, pad, i;

	if (spec.length == LENGTH_LONG)
		n = va_arg(args, unsigned long);
	else if (spec.length == LENGTH_SHORT)
		n = (unsigned short)va_arg(args, unsigned int);
	else
		n = va_arg(args, unsigned int);

	len = get_ulong_length(n);
	pad = spec.width - len;

	if (!(spec.flags & FLAG_MINUS) && pad > 0)
		for (i = 0; i < pad; i++)
			count += write(1, " ", 1);

	count += print_ulong(n);

	if ((spec.flags & FLAG_MINUS) && pad > 0)
		for (i = 0; i < pad; i++)
			count += write(1, " ", 1);

	return (count);
}
