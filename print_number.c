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

int print_int_rec(unsigned long n)
{
	int count = 0;
	char c;

	if (n / 10)
		count += print_int_rec(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	count++;
	return (count);
}

int print_int(long n, format_t spec)
{
	int count = 0, len, pad, i, prec_pad;
	unsigned long num;
	char pad_char = ' ';

	if (spec.precision == 0 && n == 0)
	{
		pad = spec.width;
		for (i = 0; i < pad; i++)
			count += write(1, " ", 1);
		return (count);
	}

	len = get_int_length(n);
	prec_pad = (spec.precision > len) ? spec.precision - len : 0;
	
	if (n >= 0 && (spec.flags & (FLAG_PLUS | FLAG_SPACE)))
		len++;
	if (n < 0)
		len++;
	
	if ((spec.flags & FLAG_ZERO) && !(spec.flags & FLAG_MINUS) && spec.precision < 0)
		pad_char = '0';
	
	pad = spec.width - (len + prec_pad);

	if (!(spec.flags & FLAG_MINUS) && pad > 0 && pad_char == ' ')
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

	if (pad_char == '0' && pad > 0)
		for (i = 0; i < pad; i++)
			count += write(1, "0", 1);

	for (i = 0; i < prec_pad; i++)
		count += write(1, "0", 1);

	count += print_int_rec(num);

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
