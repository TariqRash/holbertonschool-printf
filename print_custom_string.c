#include "main.h"

int print_custom_string(va_list args)
{
	char *str = va_arg(args, char *);
	int i, count = 0;
	char hex[3];

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		if (str[i] > 0 && str[i] < 32) || str[i] >= 127)
		{
			add_to_buffer('\\'); add_to_buffer('x');
			hex[0] = "0123456789ABCDEF"[str[i] / 16];
			hex[1] = "0123456789ABCDEF"[str[i] % 16];
			add_to_buffer(hex[0]); add_to_buffer(hex[1]);
			count += 4;
		}
		else
		{
			add_to_buffer(str[i]);
			count++;
		}
	}
	return (count);
}
