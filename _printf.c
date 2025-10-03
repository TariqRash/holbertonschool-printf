#include "main.h"

/**
 * handle_specifier - Handle format specifier
 * @format: Format character
 * @args: Arguments list
 *
 * Return: Number of characters printed
 */
int handle_specifier(char format, va_list args)
{
	int count = 0;

	if (format == 'c')
		count += print_char(args);
	else if (format == 's')
		count += print_string(args);
	else if (format == '%')
	{
		write(1, "%", 1);
		count++;
	}
	else if (format == 'd' || format == 'i')
		count += print_number(args);
	else if (format == 'b')
		count += print_binary(args);
	else if (format == 'u')
		count += print_unsigned(args);
	else if (format == 'o')
		count += print_octal(args);
	else if (format == 'x')
		count += print_hex_lower(args);
	else if (format == 'X')
		count += print_hex_upper(args);
	else if (format == 'p')
		count += print_pointer(args);
	else if (format == 'r')
		count += print_reverse(args);
	else if (format == 'R')
		count += print_rot13(args);
	else
	{
		write(1, "%", 1);
		write(1, &format, 1);
		count += 2;
	}
	return (count);
}

/**
 * _printf - Custom printf function
 * @format: Format string containing conversion specifiers
 *
 * Return: Number of characters printed, -1 on error
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			count += handle_specifier(format[i], args);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
