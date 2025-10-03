#include "main.h"
int print_pointer(va_list args)
{
	void *ptr = va_arg(args, void *); unsigned long addr = (unsigned long)ptr; int i = 0, count = 0; char buf[32], *hex = "0123456789abcdef";
	if (!ptr) { write(1, "(nil)", 5); return (5); }
	write(1, "0x", 2); count = 2;
	if (!addr) { write(1, "0", 1); return (3); }
	while (addr) { buf[i++] = hex[addr % 16]; addr /= 16; }
	while (i) { write(1, &buf[--i], 1); count++; }
	return (count);
}
