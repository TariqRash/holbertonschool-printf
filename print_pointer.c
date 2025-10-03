#include "main.h"

int print_pointer(va_list args)
{
	void *ptr = va_arg(args, void *);
	unsigned long addr = (unsigned long)ptr;
	int count = 0;
	char buffer[32];
	int i = 0;
	char *hex = "0123456789abcdef";

	if (ptr == NULL)
	{
		add_to_buffer('(');
		add_to_buffer('n');
		add_to_buffer('i');
		add_to_buffer('l');
		add_to_buffer(')');
		return (5);
	}
	add_to_buffer('0');
	add_to_buffer('x');
	count += 2;
	if (addr == 0)
	{
		add_to_buffer('0');
		return (3);
	}
	while (addr > 0)
	{
		buffer[i++] = hex[addr % 16];
		addr /= 16;
	}
	while (i > 0)
	{
		add_to_buffer(buffer[--i]);
		count++;
	}
	return (count);
}
