#include "main.h"

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	format_t spec;

	if (format == NULL)
		return (-1);
	g_buffer_index = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			add_to_buffer(format[i]);
			count++;
			i++;
		}
		else
		{
			i++;
			if (format[i] == '\0')
			{
				flush_buffer();
				va_end(args);
				return (-1);
			}
			if (format[i] == '%')
			{
				add_to_buffer('%');
				count++;
				i++;
			}
			else if (format[i] == ' ' && (format[i + 1] == '\0' || format[i + 1] == ' ' || format[i + 1] == '%'))
			{
				add_to_buffer('%');
				add_to_buffer(' ');
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
	flush_buffer();
	va_end(args);
	return (count);
}
