#include "main.h"
int print_custom_string(va_list args)
{
	char *s = va_arg(args, char *), *h = "0123456789ABCDEF", b[4]; int i, c = 0;
	if (!s) s = "(null)";
	for (i = 0; s[i]; i++) {
		if (s[i] >= 32 && s[i] < 127) { write(1, &s[i], 1); c++; }
		else { b[0] = '\\'; b[1] = 'x'; b[2] = h[(unsigned char)s[i] / 16]; b[3] = h[(unsigned char)s[i] % 16]; write(1, b, 4); c += 4; }
	}
	return (c);
}
