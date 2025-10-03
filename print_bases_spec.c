#include "main.h"

int print_ulong_spec(unsigned long n)
{
	int count = 0;
	char c;

	if (n / 10)
		count += print_ulong_spec(n / 10);
	c = (n % 10) + '0';
	add_to_buffer(c);
	count++;
	return (count);
}

int print_unsigned_spec(va_list args, format_t spec)
{
	unsigned long n;

	if (spec.length == LENGTH_LONG)
		n = va_arg(args, unsigned long);
	else if (spec.length == LENGTH_SHORT)
		n = (unsigned short)va_arg(args, unsigned int);
	else
		n = va_arg(args, unsigned int);
	return (print_ulong_spec(n));
}

int print_octal_spec(va_list args, format_t spec)
{
	unsigned long n;
	int count = 0;
	char buffer[32];
	int i = 0;

	if (spec.length == LENGTH_LONG)
		n = va_arg(args, unsigned long);
	else if (spec.length == LENGTH_SHORT)
		n = (unsigned short)va_arg(args, unsigned int);
	else
		n = va_arg(args, unsigned int);
	if ((spec.flags & FLAG_HASH) && n != 0)
	{
		add_to_buffer('0');
		count++;
	}
	if (n == 0)
	{
		add_to_buffer('0');
		return (count + 1);
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

int print_hex_lower_spec(va_list args, format_t spec)
{
	unsigned long n;
	int count = 0;
	char buffer[32];
	int i = 0;
	char *hex = "0123456789abcdef";

	if (spec.length == LENGTH_LONG)
		n = va_arg(args, unsigned long);
	else if (spec.length == LENGTH_SHORT)
		n = (unsigned short)va_arg(args, unsigned int);
	else
		n = va_arg(args, unsigned int);
	if ((spec.flags & FLAG_HASH) && n != 0)
	{
		add_to_buffer('0');
		add_to_buffer('x');
		count += 2;
	}
	if (n == 0)
	{
		add_to_buffer('0');
		return (count + 1);
	}
	while (n > 0)
	{
		buffer[i++] = hex[n % 16];
		n /= 16;
	}
	while (i > 0)
	{
		add_to_buffer(buffer[--i]);
		count++;
	}
	return (count);
}

int print_hex_upper_spec(va_list args, format_t spec)
{
	unsigned long n;
	int count = 0;
	char buffer[32];
	int i = 0;
	char *hex = "0123456789ABCDEF";

	if (spec.length == LENGTH_LONG)
		n = va_arg(args, unsigned long);
	else if (spec.length == LENGTH_SHORT)
		n = (unsigned short)va_arg(args, unsigned int);
	else
		n = va_arg(args, unsigned int);
	if ((spec.flags & FLAG_HASH) && n != 0)
	{
		add_to_buffer('0');
		add_to_buffer('X');
		count += 2;
	}
	if (n == 0)
	{
		add_to_buffer('0');
		return (count + 1);
	}
	while (n > 0)
	{
		buffer[i++] = hex[n % 16];
		n /= 16;
	}
	while (i > 0)
	{
		add_to_buffer(buffer[--i]);
		count++;
	}
	return (count);
}
