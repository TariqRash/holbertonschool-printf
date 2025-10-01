#include <main.h>

/**
 * print_char - prints a character
 * @args: Arguments list
 * Return: number of characters printed (1)
 */

int print_char(va_list args)
{
char c = va_arg(args; int);
write(1,c,1);
return 1;
}

