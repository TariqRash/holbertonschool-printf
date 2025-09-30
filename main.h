#ifndef MAIN_H
#define MAIN_h

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format,...);
int print_char(va_list args);
int print_string(va_list args);
int print_numper(va_list args);
int print_int(int n);

#endif
