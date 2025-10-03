#include "main.h"

/**
 * is_printable - Check if char is printable
 * @c: Character to check
 *
 * Return: 1 if printable, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

/**
 * print_hex_char - Print char as \xHH
 * @c: Character to print
 *
 * Return: Number of chars printed (4)
 */
int print_hex_char(char c)
{
	char *hex = "0123456789ABCDEF";
	char buffer[4];

	buffer[0] = '\\';
	buffer[1] = 'x';
	buffer[2] = hex[(unsigned char)c / 16];
	buffer[3] = hex[(unsigned char)c % 16];

	write(1, buffer, 4);
	return (4);
}

/**
 * print_custom_string - Prints string with \xHH for non-printable
 * @args: Arguments list
 *
 * Return: Number of characters printed
 */
int print_custom_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;
	int i;

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i]; i++)
	{
		if (is_printable(str[i]))
		{
			write(1, &str[i], 1);
			count++;
		}
		else
		{
			count += print_hex_char(str[i]);
		}
	}

	return (count);
}
