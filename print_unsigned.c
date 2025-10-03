#include "main.h"

/**
 * print_unsigned - Print unsigned integer
 * @args: Arguments list
 *
 * Return: Number of characters printed
 */
int print_unsigned(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int temp = n;
	int count = 0, divisor = 1;
	char c;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (temp / 10)
	{
		divisor *= 10;
		temp /= 10;
	}

	while (divisor > 0)
	{
		c = (n / divisor) + '0';
		write(1, &c, 1);
		count++;
		n %= divisor;
		divisor /= 10;
	}

	return (count);
}
