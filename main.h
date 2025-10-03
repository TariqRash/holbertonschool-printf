#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/* Flag definitions */
#define FLAG_PLUS 1
#define FLAG_SPACE 2
#define FLAG_HASH 4

/* Length definitions */
#define LENGTH_LONG 1
#define LENGTH_SHORT 2

/**
 * struct format_t - Format specification
 * @flags: Flags (+, space, #)
 * @length: Length modifier (l, h)
 */
typedef struct format_t
{
	int flags;
	int length;
} format_t;

int _printf(const char *format, ...);
int handle_specifier(char format, va_list args, format_t spec);
int print_char(va_list args);
int print_string(va_list args);
int print_number(va_list args, format_t spec);
int print_int(long n, format_t spec);
int print_unsigned_spec(va_list args, format_t spec);
int print_octal_spec(va_list args, format_t spec);
int print_hex_lower_spec(va_list args, format_t spec);
int print_hex_upper_spec(va_list args, format_t spec);
format_t parse_flags(const char *format, int *i);
int print_binary(va_list args);
int print_pointer(va_list args);
int print_reverse(va_list args);
int print_rot13(va_list args);
int print_custom_string(va_list args);

#endif
