#include "main.h"

/**
 * print_reverse - Prints string in reverse
 * @args: Arguments list
 *
 * Return: Number of characters printed
 */
int print_reverse(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;
	int len = 0;

	if (str == NULL)
		str = "(null)";

	while (str[len])
		len++;

	while (len > 0)
	{
		write(1, &str[--len], 1);
		count++;
	}

	return (count);
}
