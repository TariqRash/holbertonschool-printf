#include "main.h"

/**
 * print_int - Print integer with flags
 * @n: Number to print
 * @spec: Format specification
 *
 * Return: Number of chars printed
 */
int print_int(long n, format_t spec)
{
	int count = 0;
	unsigned long num;
	char c;
	format_t empty_spec;

	empty_spec.flags = 0;
	empty_spec.length = 0;

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
		count += print_int(num / 10, empty_spec);
	c = (num % 10) + '0';
	write(1, &c, 1);
	count++;
	return (count);
}

/**
 * print_number - Print number with format spec
 * @args: Arguments list
 * @spec: Format specification
 *
 * Return: Number of chars printed
 */
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
