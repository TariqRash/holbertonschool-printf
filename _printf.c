#include "main.h"

int _printf(const char *format, ...)
{
	va_list args;
	int i, count = 0;

	if (format == NULL)
		return (-1);
	reset_buffer();
	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				break;
			if (format[i] == 'c')
				count += print_char(args);
			else if (format[i] == 's')
				count += print_string(args);
			else if (format[i] == 'S')
				count += print_custom_string(args);
			else if (format[i] == '%')
			{
				add_to_buffer('%');
				count++;
			}
			else if (format[i] == 'd' || format[i] == 'i')
				count += print_number(args);
			else if (format[i] == 'u')
				count += print_unsigned(args);
			else if (format[i] == 'o')
				count += print_octal(args);
			else if (format[i] == 'x')
				count += print_hex_lower(args);
			else if (format[i] == 'X')
				count += print_hex_upper(args);
			else if (format[i] == 'b')
				count += print_binary(args);
			else if (format[i] == 'p')
				count += print_pointer(args);
			else if (format[i] == 'r')
				count += print_reverse(args);
			else if (format[i] == 'R')
				count += print_rot13(args);
			else
			{
				add_to_buffer('%');
				add_to_buffer(format[i]);
				count += 2;
			}
		}
		else
		{
			add_to_buffer(format[i]);
			count++;
		}
	}
	va_end(args);
	flush_buffer();
	return (count);
}
