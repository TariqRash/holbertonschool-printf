#include "main.h"

/**
 * print_int - Helper function to print integer
 * @n: Number to print
 *
 * Return: Number of digits printed
 */
int print_int(int n)
{
	int count = 0;
	unsigned int num;
	char c;

	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10)
		count += print_int(num / 10);

	c = (num % 10) + '0';
	write(1, &c, 1);
	count++;

	return (count);
}

/**
 * print_number - Prints a number from va_list
 * @args: Arguments list containing the integer
 *
 * Return: Number of characters printed
 */
int print_number(va_list args)
{
	int n = va_arg(args, int);

	return (print_int(n));
}
