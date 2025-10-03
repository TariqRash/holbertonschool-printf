#include "main.h"

/**
 * print_ulong - Print unsigned long
 * @n: Number to print
 *
 * Return: Count
 */
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

/**
 * print_unsigned_spec - Print unsigned with spec
 * @args: Arguments
 * @spec: Format spec
 *
 * Return: Count
 */
int print_unsigned_spec(va_list args, format_t spec)
{
	unsigned long n;

	if (spec.length == LENGTH_LONG)
		n = va_arg(args, unsigned long);
	else if (spec.length == LENGTH_SHORT)
		n = (unsigned short)va_arg(args, unsigned int);
	else
		n = va_arg(args, unsigned int);
	return (print_ulong(n));
}
