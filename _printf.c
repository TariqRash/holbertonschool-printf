#include "main.h"

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0, j;
	format_t spec;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			j = i;
			i++;
			if (format[i] == '\0')
				return (-1);
			spec = parse_flags(format, &i);
			if (format[i] == 'c' || format[i] == 's' || format[i] == 'S' ||
			    format[i] == '%' || format[i] == 'd' || format[i] == 'i' ||
			    format[i] == 'u' || format[i] == 'o' || format[i] == 'x' ||
			    format[i] == 'X' || format[i] == 'b' || format[i] == 'p' ||
			    format[i] == 'r' || format[i] == 'R')
				count += handle_specifier(format[i], args, spec);
			else
			{
				while (j <= i)
					count += write(1, &format[j++], 1);
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
