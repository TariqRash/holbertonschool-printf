#include "main.h"
int get_ulong_length(unsigned long n)
{
	int len = 0;
	if (n == 0) return (1);
	while (n > 0) { len++; n /= 10; }
	return (len);
}
int print_ulong(unsigned long n)
{
	int count = 0; char c;
	if (n / 10) count += print_ulong(n / 10);
	c = (n % 10) + '0'; add_to_buffer(c); count++;
	return (count);
}
int print_unsigned_spec(va_list args, format_t spec)
{
	unsigned long n; int count = 0, len, pad, i, prec_pad; char pad_char = ' ';
	if (spec.length == LENGTH_LONG) n = va_arg(args, unsigned long);
	else if (spec.length == LENGTH_SHORT) n = (unsigned short)va_arg(args, unsigned int);
	else n = va_arg(args, unsigned int);
	if (spec.precision == 0 && n == 0) { for (i = 0; i < spec.width; i++) count += add_to_buffer(' '); return (count); }
	len = get_ulong_length(n); prec_pad = (spec.precision > len) ? spec.precision - len : 0;
	if ((spec.flags & FLAG_ZERO) && !(spec.flags & FLAG_MINUS) && spec.precision < 0) pad_char = '0';
	pad = spec.width - (len + prec_pad); if (pad < 0) pad = 0;
	if (!(spec.flags & FLAG_MINUS) && pad > 0 && pad_char == ' ') for (i = 0; i < pad; i++) count += add_to_buffer(' ');
	if (pad_char == '0' && pad > 0) for (i = 0; i < pad; i++) count += add_to_buffer('0');
	for (i = 0; i < prec_pad; i++) count += add_to_buffer('0');
	count += print_ulong(n);
	if ((spec.flags & FLAG_MINUS) && pad > 0) for (i = 0; i < pad; i++) count += add_to_buffer(' ');
	return (count);
}
