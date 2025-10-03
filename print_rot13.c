#include "main.h"
int print_rot13(va_list args)
{
	char *s = va_arg(args, char *), *in = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz", *out = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm", c; int i, j, cnt = 0, f;
	if (!s) s = "(null)";
	for (i = 0; s[i]; i++) { f = 0; for (j = 0; in[j]; j++) { if (s[i] == in[j]) { c = out[j]; write(1, &c, 1); f = 1; break; } } if (!f) write(1, &s[i], 1); cnt++; }
	return (cnt);
}
