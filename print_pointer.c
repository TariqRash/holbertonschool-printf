#include "main.h"

/**
 * print_pointer - Prints pointer address
 * @args: Arguments list
 *
 * Return: Number of characters printed
 */
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
		write(1, "(nil)", 5);
		return (5);
	}

	write(1, "0x", 2);
	count += 2;

	if (addr == 0)
	{
		write(1, "0", 1);
		return (3);
	}

	while (addr > 0)
	{
		buffer[i++] = hex[addr % 16];
		addr /= 16;
	}

	while (i > 0)
	{
		write(1, &buffer[--i], 1);
		count++;
	}

	return (count);
}
