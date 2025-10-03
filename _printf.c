#include "main.h"

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
	format_t spec;

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
			spec = parse_flags(format, &i);
			count += handle_specifier(format[i], args, spec);
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
