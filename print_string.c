#include "main.h"

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
