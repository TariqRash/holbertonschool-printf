#include "main.h"

int print_hex_lower(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;
	char buffer[32];
	int i = 0;
	char *hex = "0123456789abcdef";

	if (n == 0)
	{
		add_to_buffer('0');
		return (1);
	}
	while (n > 0)
	{
		buffer[i++] = hex[n % 16];
		n /= 16;
	}
	while (i > 0)
	{
		add_to_buffer(buffer[--i]);
		count++;
	}
	return (count);
}

int print_hex_upper(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;
	char buffer[32];
	int i = 0;
	char *hex = "0123456789ABCDEF";

	if (n == 0)
	{
		add_to_buffer('0');
		return (1);
	}
	while (n > 0)
	{
		buffer[i++] = hex[n % 16];
		n /= 16;
	}
	while (i > 0)
	{
		add_to_buffer(buffer[--i]);
		count++;
	}
	return (count);
}
