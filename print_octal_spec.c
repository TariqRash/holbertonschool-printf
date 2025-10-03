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
	int count = 0, len, pad, i, prec_pad, idx = 0;
	char buffer[32], pad_char = ' ';

	if (spec.length == LENGTH_LONG)
		n = va_arg(args, unsigned long);
	else if (spec.length == LENGTH_SHORT)
		n = (unsigned short)va_arg(args, unsigned int);
	else
		n = va_arg(args, unsigned int);

	if (spec.precision == 0 && n == 0)
	{
		pad = spec.width;
		for (i = 0; i < pad; i++)
			count += write(1, " ", 1);
		return (count);
	}

	len = get_octal_length(n);
	prec_pad = (spec.precision > len) ? spec.precision - len : 0;
	if ((spec.flags & FLAG_HASH) && n != 0)
		len++;
	
	if ((spec.flags & FLAG_ZERO) && !(spec.flags & FLAG_MINUS) && spec.precision < 0)
		pad_char = '0';
	
	pad = spec.width - (len + prec_pad);

	if (!(spec.flags & FLAG_MINUS) && pad > 0 && pad_char == ' ')
		for (i = 0; i < pad; i++)
			count += write(1, " ", 1);

	if ((spec.flags & FLAG_HASH) && n != 0)
	{
		write(1, "0", 1);
		count++;
	}

	if (pad_char == '0' && pad > 0)
		for (i = 0; i < pad; i++)
			count += write(1, "0", 1);

	for (i = 0; i < prec_pad; i++)
		count += write(1, "0", 1);

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
