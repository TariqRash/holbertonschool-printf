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
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			count++;
			i++;
		}
		else
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			if (format[i] == '%')
			{
				write(1, "%", 1);
				count++;
				i++;
			}
			else if (format[i] == ' ' && (format[i + 1] == '\0' || format[i + 1] == ' ' || format[i + 1] == '%'))
			{
				write(1, "% ", 2);
				count += 2;
				i++;
			}
			else
			{
				spec = parse_flags(format, &i);
				count += handle_specifier(format[i], args, spec);
				i++;
			}
		}
	}
	va_end(args);
	return (count);
}
