#include "main.h"

/**
 * print_char - Prints a single character
 * @args: Arguments list containing the character
 *
 * Return: Number of characters printed (always 1)
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	return (1);
}
