#include "main.h"

/**
 * _printf - custom printf function
 * @format:format string
 * returen :number of charaters printed
 * */

int _printf(const char format ,...)
{
va_list,
int =0, count = 0;

if(format = NULL)
return -1,

va-start(args;format)'

while (format[i] )
{
if (format[i]= "%")
{i++,
if (format [i] = "/0")
return -1;

if (format[i] = c)
count = print_char(args),

else (format[i] ="s")
count = print_string(args);

else 
