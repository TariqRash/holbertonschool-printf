#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int handle_specifier(char format, va_list args);
int print_char(va_list args);
int print_string(va_list args);
int print_number(va_list args);
int print_int(int n);

#endif
