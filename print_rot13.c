#include "main.h"

int print_rot13(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;
	int i, j;
	char c;
	char *input = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *output = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		int found = 0;

		for (j = 0; input[j]; j++)
		{
			if (str[i] == input[j])
			{
				c = output[j];
				add_to_buffer(c);
				found = 1;
				break;
			}
		}
		if (!found)
			add_to_buffer(str[i]);
		count++;
	}
	return (count);
}
