#include "main.h"

/**
 * print_octal_spec - Print octal with spec
 * @args: Arguments
 * @spec: Format spec
 *
 * Return: Count
 */
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
		write(1, "0", 1);
		count++;
	}
	if (n == 0)
	{
		write(1, "0", 1);
		return (count + 1);
	}
	while (n > 0)
	{
		buffer[i++] = (n % 8) + '0';
		n /= 8;
	}
	while (i > 0)
	{
		write(1, &buffer[--i], 1);
		count++;
	}
	return (count);
}
