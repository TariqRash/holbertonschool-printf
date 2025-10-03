#include "main.h"

int print_reverse(va_list args)
{
	char *str = va_arg(args, char *);
	int len = 0, i, count = 0;

	if (str == NULL)
		str = "(null)";
	while (str[len])
		len++;
	for (i = len - 1; i >= 0; i--)
	{
		add_to_buffer(str[i]);
		count++;
	}
	return (count);
}
