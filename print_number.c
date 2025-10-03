#include "main.h"

int print_int(int n)
{
	int count = 0;
	unsigned int num;
	char c;

	if (n < 0)
	{
		add_to_buffer('-');
		count++;
		num = -n;
	}
	else
		num = n;
	if (num / 10)
		count += print_int(num / 10);
	c = (num % 10) + '0';
	add_to_buffer(c);
	count++;
	return (count);
}

int print_number(va_list args)
{
	int n = va_arg(args, int);
	return (print_int(n));
}
