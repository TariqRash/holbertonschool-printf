#include "main.h"

int print_string_width(va_list args, format_t spec)
{
	char *str = va_arg(args, char *);
	int count = 0, len = 0, pad, i, print_len;

	if (str == NULL) str = "(null)";
	while (str[len]) len++;
	print_len = (spec.precision >= 0 && spec.precision < len) ? spec.precision : len;
	pad = spec.width - print_len;
	if (!(spec.flags & FLAG_MINUS) && pad > 0)
		for (i = 0; i < pad; i++) { add_to_buffer(' '); count++; }
	for (i = 0; i < print_len; i++) { add_to_buffer(str[i]); count++; }
	if ((spec.flags & FLAG_MINUS) && pad > 0)
		for (i = 0; i < pad; i++) { add_to_buffer(' '); count++; }
	return (count);
}

int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (str == NULL) str = "(null)";
	while (str[count]) { add_to_buffer(str[count]); count++; }
	return (count);
}
