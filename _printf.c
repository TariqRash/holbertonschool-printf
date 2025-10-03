#include "main.h"

/**
 * print_binary - Print an unsigned int in binary
 * @args: Argument list
 *
 * Return: Number of characters printed
 */
int print_binary(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;
	char buffer[32]; /* 32 bits max for unsigned int */
	int i = 0;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (n > 0)
	{
		buffer[i++] = (n % 2) + '0';
		n /= 2;
	}

	/* Print in reverse */
	while (i > 0)
	{
		write(1, &buffer[--i], 1);
		count++;
	}

	return (count);
}

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
	else if (format == 'b') /* 👈 new binary specifier */
		count += print_binary(args);
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

