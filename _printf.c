#include "main.h"

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
			if (format[i + 1] == '\0')
				return (-1);
			if (format[i + 1] == '%')
			{
				write(1, "%", 1);
				count++;
				i += 2;
				continue;
			}
			if (format[i + 1] != 'c' && format[i + 1] != 's' && format[i + 1] != 'S' &&
			    format[i + 1] != 'd' && format[i + 1] != 'i' && format[i + 1] != 'u' &&
			    format[i + 1] != 'o' && format[i + 1] != 'x' && format[i + 1] != 'X' &&
			    format[i + 1] != 'b' && format[i + 1] != 'p' && format[i + 1] != 'r' &&
			    format[i + 1] != 'R' && format[i + 1] != '+' && format[i + 1] != ' ' &&
			    format[i + 1] != '#' && format[i + 1] != 'l' && format[i + 1] != 'h')
			{
				write(1, "%", 1);
				count++;
				i++;
				continue;
			}
			i++;
			spec = parse_flags(format, &i);
			count += handle_specifier(format[i], args, spec);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
			i++;
		}
	}
	va_end(args);
	return (count);
}
