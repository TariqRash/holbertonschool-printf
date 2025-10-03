#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/* Flag definitions for Tasks 8-9 */
#define FLAG_PLUS 1
#define FLAG_SPACE 2
#define FLAG_HASH 4

/* Length definitions for Tasks 8-9 */
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

/* Core functions */
int _printf(const char *format, ...);
int handle_specifier(char format, va_list args, format_t spec);

/* Basic print functions */
int print_char(va_list args);
int print_string(va_list args);
int print_number(va_list args);
int print_int(int n);

/* Task 3: Binary */
int print_binary(va_list args);

/* Task 4: Bases */
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex_lower(va_list args);
int print_hex_upper(va_list args);

/* Task 5: Buffer */
int add_to_buffer(char c);
int flush_buffer(void);
void reset_buffer(void);

/* Task 6: Pointer */
int print_pointer(va_list args);

/* Task 7: Custom String */
int print_custom_string(va_list args);
int is_printable(char c);
int print_hex_char(char c);

/* Tasks 8-9: Spec versions with flags/length */
format_t parse_flags(const char *format, int *i);
int print_number_spec(va_list args, format_t spec);
int print_int_spec(long n, format_t spec);
int print_unsigned_spec(va_list args, format_t spec);
int print_octal_spec(va_list args, format_t spec);
int print_hex_lower_spec(va_list args, format_t spec);
int print_hex_upper_spec(va_list args, format_t spec);

/* Task 14: Reverse */
int print_reverse(va_list args);

/* Task 15: ROT13 */
int print_rot13(va_list args);

#endif
