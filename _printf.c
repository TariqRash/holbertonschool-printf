#include "main.h"

static int is_valid_specifier(char c)
{
	return (c == 'c' || c == 's' || c == 'S' || c == '%' || c == 'd' ||
		c == 'i' || c == 'u' || c == 'o' || c == 'x' || c == 'X' ||
		c == 'b' || c == 'p' || c == 'r' || c == 'R');
}

static int is_flag_or_length(char c)
{
	return (c == '+' || c == ' ' || c == '#' || c == 'l' || c == 'h');
}

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0, temp;
	format_t spec;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			temp = i + 1;
			while (format[temp] && is_flag_or_length(format[temp]))
				temp++;
			if (format[temp] == '\0' || !is_valid_specifier(format[temp]))
			{
				write(1, "%", 1);
				count++;
			}
			else
			{
				i++;
				spec = parse_flags(format, &i);
				count += handle_specifier(format[i], args, spec);
			}
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
