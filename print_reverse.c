#include "main.h"

int print_reverse(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;
	int len = 0;

	if (str == NULL)
		str = "(null)";
	while (str[len])
		len++;
	while (len > 0)
	{
		add_to_buffer(str[--len]);
		count++;
	}
	return (count);
}
