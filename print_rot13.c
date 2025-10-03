#include "main.h"

/**
 * print_rot13 - Prints string in ROT13
 * @args: Arguments list
 *
 * Return: Number of characters printed
 */
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
				write(1, &c, 1);
				found = 1;
				break;
			}
		}

		if (!found)
			write(1, &str[i], 1);

		count++;
	}

	return (count);
}
