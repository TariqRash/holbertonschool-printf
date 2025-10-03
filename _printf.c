#include "main.h"

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0, start_pos;
	format_t spec;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			start_pos = i;
			i++;
			if (format[i] == '\0')
			{
				write(1, "%", 1);
				count++;
				break;
			}
			spec = parse_flags(format, &i);
			if (format[i] == '\0' || (format[i] != 'c' && format[i] != 's' && 
			    format[i] != 'S' && format[i] != '%' && format[i] != 'd' && 
			    format[i] != 'i' && format[i] != 'u' && format[i] != 'o' && 
			    format[i] != 'x' && format[i] != 'X' && format[i] != 'b' && 
			    format[i] != 'p' && format[i] != 'r' && format[i] != 'R'))
			{
				while (start_pos <= i)
				{
					write(1, &format[start_pos], 1);
					count++;
					start_pos++;
				}
			}
			else
			{
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
