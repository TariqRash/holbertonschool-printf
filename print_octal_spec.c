#include "main.h"

int get_octal_length(unsigned long n)
{
	int len = 0;

	if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		n /= 8;
	}
	return (len);
}

int print_octal_spec(va_list args, format_t spec)
{
	unsigned long n;
	int count = 0, len, pad, i;
	char buffer[32];
	int idx = 0;

	if (spec.length == LENGTH_LONG)
		n = va_arg(args, unsigned long);
	else if (spec.length == LENGTH_SHORT)
		n = (unsigned short)va_arg(args, unsigned int);
	else
		n = va_arg(args, unsigned int);

	len = get_octal_length(n);
	if ((spec.flags & FLAG_HASH) && n != 0)
		len++;
	pad = spec.width - len;

	if (!(spec.flags & FLAG_MINUS) && pad > 0)
		for (i = 0; i < pad; i++)
			count += write(1, " ", 1);

	if ((spec.flags & FLAG_HASH) && n != 0)
	{
		write(1, "0", 1);
		count++;
	}

	if (n == 0)
	{
		write(1, "0", 1);
		count++;
	}
	else
	{
		while (n > 0)
		{
			buffer[idx++] = (n % 8) + '0';
			n /= 8;
		}
		while (idx > 0)
		{
			write(1, &buffer[--idx], 1);
			count++;
		}
	}

	if ((spec.flags & FLAG_MINUS) && pad > 0)
		for (i = 0; i < pad; i++)
			count += write(1, " ", 1);

	return (count);
}
