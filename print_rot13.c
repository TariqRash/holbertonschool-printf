#include "main.h"

int print_rot13(va_list args)
{
	char *str = va_arg(args, char *);
	int i, count = 0;
	char c;

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		c = str[i];
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		{
			if ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M'))
				c += 13;
			else
				c -= 13;
		}
		add_to_buffer(c);
		count++;
	}
	return (count);
}
