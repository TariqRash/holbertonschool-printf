#include "main.h"

int print_char_width(va_list args, format_t spec)
{
	char c = va_arg(args, int);
	int count = 0, pad = spec.width - 1, i;

	if (!(spec.flags & FLAG_MINUS) && pad > 0)
		for (i = 0; i < pad; i++)
			count += write(1, " ", 1);
	write(1, &c, 1);
	count++;
	if ((spec.flags & FLAG_MINUS) && pad > 0)
		for (i = 0; i < pad; i++)
			count += write(1, " ", 1);
	return (count);
}

int print_char(va_list args)
{
	char c = va_arg(args, int);
	write(1, &c, 1);
	return (1);
}
