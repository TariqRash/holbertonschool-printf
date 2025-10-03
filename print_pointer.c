#include "main.h"

int print_pointer_spec(va_list args, format_t spec)
{
	void *ptr = va_arg(args, void *);
	unsigned long addr = (unsigned long)ptr;
	int count = 0, len = 2, i, pad;
	char buffer[32], *hex = "0123456789abcdef";
	int idx = 0;
	unsigned long temp = addr;

	if (ptr == NULL)
	{
		len = 5;
		pad = spec.width - len;
		if (!(spec.flags & FLAG_MINUS) && pad > 0)
			for (i = 0; i < pad; i++)
				count += write(1, " ", 1);
		write(1, "(nil)", 5);
		count += 5;
		if ((spec.flags & FLAG_MINUS) && pad > 0)
			for (i = 0; i < pad; i++)
				count += write(1, " ", 1);
		return (count);
	}

	if (addr == 0)
		len = 3;
	else
	{
		while (temp > 0)
		{
			len++;
			temp /= 16;
		}
	}

	pad = spec.width - len;

	if (!(spec.flags & FLAG_MINUS) && pad > 0)
		for (i = 0; i < pad; i++)
			count += write(1, " ", 1);

	write(1, "0x", 2);
	count += 2;

	if (addr == 0)
	{
		write(1, "0", 1);
		count++;
	}
	else
	{
		while (addr > 0)
		{
			buffer[idx++] = hex[addr % 16];
			addr /= 16;
		}
		while (idx > 0)
		{
			write(1, &buffer[--idx], 1);
			count++;
		}
	}

	if ((spec.flags & FLAG_MINUS) && pad > 0)
		for (i = 0; i < pad; i++)
			count += write(1, " ", 1);

	return (count);
}

int print_pointer(va_list args)
{
	format_t spec;

	spec.flags = 0;
	spec.width = 0;
	spec.precision = -1;
	spec.length = 0;
	return (print_pointer_spec(args, spec));
}
