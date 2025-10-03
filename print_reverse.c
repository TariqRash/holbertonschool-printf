#include "main.h"
int print_reverse(va_list args)
{
	char *s = va_arg(args, char *); int c = 0, l = 0;
	if (!s) s = "(null)";
	while (s[l]) l++;
	while (l) { write(1, &s[--l], 1); c++; }
	return (c);
}
