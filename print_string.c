#include "main.h"

int print_string_width(va_list args, format_t spec)
{
	char *str = va_arg(args, char *);
	int count = 0, len = 0, pad, i;

	if (str == NULL)
		str = "(null)";
	while (str[len])
		len++;
	pad = spec.width - len;
	if (!(spec.flags & FLAG_MINUS) && pad > 0)
		for (i = 0; i < pad; i++)
			count += write(1, " ", 1);
	while (*str)
	{
		write(1, str, 1);
		str++;
		count++;
	}
	if ((spec.flags & FLAG_MINUS) && pad > 0)
		for (i = 0; i < pad; i++)
			count += write(1, " ", 1);
	return (count);
}

int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (str == NULL)
		str = "(null)";
	while (str[count])
	{
		write(1, &str[count], 1);
		count++;
	}
	return (count);
}
