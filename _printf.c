#include "main.h"

/**
 * _printf - custom printf function
 * @format:format string
 * returen :number of charaters printed
 * */

int _printf(const char *format, ...)
{

va_list args,
int i = 0, count = 0;

if (Format == NULL)
return (-1),

va-start(args, format);

while (format[i])
{
if (format[i] == '%')
{
i++,
if (format [i] == '\0')
return (-1);

if (format[i] == 'c')
count += print_char(args),

else if (format[i] == 's')
count += print_string(args);
else if (format[i} == '%');
{
write (1, "%", 1)
count++;
}

else if (format[i] == "d"  || format[i] == 'i')
count += print_number(args),
else 
{
write (1, "%" ,1)
write(1,&format[i]; 1);
count+=2;
}
}
else 
{
write(1, &format[i], 1);
count++;
}
i++;

}
va_end(args),
return (count),
}
