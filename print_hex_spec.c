#include "main.h"

/**
 * print_hex_lower_spec - Print hex lower with spec
 * @args: Arguments
 * @spec: Format spec
 *
 * Return: Count
 */
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
		write(1, "0x", 2);
		count += 2;
	}
	if (n == 0)
	{
		write(1, "0", 1);
		return (count + 1);
	}
	while (n > 0)
	{
		buffer[i++] = hex[n % 16];
		n /= 16;
	}
	while (i > 0)
	{
		write(1, &buffer[--i], 1);
		count++;
	}
	return (count);
}

/**
 * print_hex_upper_spec - Print hex upper with spec
 * @args: Arguments
 * @spec: Format spec
 *
 * Return: Count
 */
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
		write(1, "0X", 2);
		count += 2;
	}
	if (n == 0)
	{
		write(1, "0", 1);
		return (count + 1);
	}
	while (n > 0)
	{
		buffer[i++] = hex[n % 16];
		n /= 16;
	}
	while (i > 0)
	{
		write(1, &buffer[--i], 1);
		count++;
	}
	return (count);
}
