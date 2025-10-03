#include "main.h"

int print_char_width(va_list args, format_t spec)
{
	char c = va_arg(args, int);
	int count = 0, pad = spec.width - 1, i;

	if (!(spec.flags & FLAG_MINUS) && pad > 0)
		for (i = 0; i < pad; i++) { add_to_buffer(' '); count++; }
	add_to_buffer(c);
	count++;
	if ((spec.flags & FLAG_MINUS) && pad > 0)
		for (i = 0; i < pad; i++) { add_to_buffer(' '); count++; }
	return (count);
}

int print_char(va_list args)
{
	char c = va_arg(args, int);
	add_to_buffer(c);
	return (1);
}
