#include "main.h"

int handle_specifier(char format, va_list args, format_t spec)
{
	int count = 0;

	if (format == 'c')
		count += print_char(args);
	else if (format == 's')
		count += print_string(args);
	else if (format == 'S')
		count += print_custom_string(args);
	else if (format == '%')
	{
		add_to_buffer('%');
		count++;
	}
	else if (format == 'd' || format == 'i')
	{
		if (spec.flags || spec.length)
			count += print_number_spec(args, spec);
		else
			count += print_number(args);
	}
	else if (format == 'u')
	{
		if (spec.length)
			count += print_unsigned_spec(args, spec);
		else
			count += print_unsigned(args);
	}
	else if (format == 'o')
	{
		if (spec.flags || spec.length)
			count += print_octal_spec(args, spec);
		else
			count += print_octal(args);
	}
	else if (format == 'x')
	{
		if (spec.flags || spec.length)
			count += print_hex_lower_spec(args, spec);
		else
			count += print_hex_lower(args);
	}
	else if (format == 'X')
	{
		if (spec.flags || spec.length)
			count += print_hex_upper_spec(args, spec);
		else
			count += print_hex_upper(args);
	}
	else if (format == 'b')
		count += print_binary(args);
	else if (format == 'p')
		count += print_pointer(args);
	else if (format == 'r')
		count += print_reverse(args);
	else if (format == 'R')
		count += print_rot13(args);
	else
	{
		add_to_buffer('%');
		add_to_buffer(format);
		count += 2;
	}
	return (count);
}

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	format_t spec;

	if (format == NULL)
		return (-1);
	reset_buffer();
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(args);
				flush_buffer();
				return (-1);
			}
			spec = parse_flags(format, &i);
			count += handle_specifier(format[i], args, spec);
			i++;
		}
		else
		{
			add_to_buffer(format[i]);
			count++;
			i++;
		}
	}
	va_end(args);
	flush_buffer();
	return (count);
}
