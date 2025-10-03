#include "main.h"

int handle_specifier(char format, va_list args, format_t spec)
{
	int count = 0;

	if (spec.width == -1)
		spec.width = va_arg(args, int);
	if (spec.precision == -2)
		spec.precision = va_arg(args, int);

	if (format == 'c')
		count += print_char_width(args, spec);
	else if (format == 's')
		count += print_string_width(args, spec);
	else if (format == 'S')
		count += print_custom_string(args);
	else if (format == '%')
	{
		write(1, "%", 1);
		count++;
	}
	else if (format == 'd' || format == 'i')
		count += print_number(args, spec);
	else if (format == 'u')
		count += print_unsigned_spec(args, spec);
	else if (format == 'o')
		count += print_octal_spec(args, spec);
	else if (format == 'x')
		count += print_hex_lower_spec(args, spec);
	else if (format == 'X')
		count += print_hex_upper_spec(args, spec);
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
		write(1, "%", 1);
		write(1, &format, 1);
		count += 2;
	}
	return (count);
}
