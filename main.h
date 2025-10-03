#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>   // ~D~@ va_list, va_start, va_end
#include <unistd.h>   // ~D~@ write
#include <stddef.h>   // ~D~@ NULL

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_number(va_list args);
int print_int(int n);
int print_binary(va_list args);
int print_octal(va_list args);
int print_hex_lower(va_list args);
int print_hex_upper(va_list args);
int print_pointer(va_list args);
int print_reverse(va_list args);
int print_rot13(va_list args);
int print_unsigned(va_list args);

#endif

