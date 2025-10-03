#include "main.h"

format_t parse_flags(const char *format, int *i)
{
	format_t spec = {0, 0};
	int pos = *i;

	while (format[pos] == '+' || format[pos] == ' ' || format[pos] == '#')
	{
		if (format[pos] == '+')
			spec.flags |= FLAG_PLUS;
		else if (format[pos] == ' ')
			spec.flags |= FLAG_SPACE;
		else if (format[pos] == '#')
			spec.flags |= FLAG_HASH;
		pos++;
	}
	if (format[pos] == 'l')
	{
		spec.length = LENGTH_LONG;
		pos++;
	}
	else if (format[pos] == 'h')
	{
		spec.length = LENGTH_SHORT;
		pos++;
	}
	*i = pos;
	return (spec);
}
