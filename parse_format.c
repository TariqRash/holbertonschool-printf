#include "main.h"

/**
 * parse_flags - Parse format flags and length
 * @format: Format string
 * @i: Current position (will be updated)
 *
 * Return: format_t structure with parsed values
 */
format_t parse_flags(const char *format, int *i)
{
	format_t spec;
	int pos = *i;

	spec.flags = 0;
	spec.length = 0;

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
