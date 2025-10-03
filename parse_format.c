#include "main.h"

format_t parse_flags(const char *format, int *i)
{
	format_t spec;
	int pos = *i;

	spec.flags = 0;
	spec.width = 0;
	spec.precision = -1;
	spec.length = 0;

	while (format[pos] == '+' || format[pos] == ' ' || format[pos] == '#' ||
	       format[pos] == '0' || format[pos] == '-')
	{
		if (format[pos] == '+')
			spec.flags |= FLAG_PLUS;
		else if (format[pos] == ' ')
			spec.flags |= FLAG_SPACE;
		else if (format[pos] == '#')
			spec.flags |= FLAG_HASH;
		else if (format[pos] == '0')
			spec.flags |= FLAG_ZERO;
		else if (format[pos] == '-')
			spec.flags |= FLAG_MINUS;
		pos++;
	}

	while (format[pos] >= '0' && format[pos] <= '9')
	{
		spec.width = spec.width * 10 + (format[pos] - '0');
		pos++;
	}

	if (format[pos] == '.')
	{
		pos++;
		spec.precision = 0;
		while (format[pos] >= '0' && format[pos] <= '9')
		{
			spec.precision = spec.precision * 10 + (format[pos] - '0');
			pos++;
		}
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
