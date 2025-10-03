# 0x11. C - printf

## Description
Custom implementation of the C printf function that handles basic format specifiers.

## Requirements
- Ubuntu 20.04 LTS
- gcc compiler with flags: -Wall -Werror -Wextra -pedantic -std=gnu89
- Code must follow Betty style

## Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c
```

## Supported Format Specifiers
| Specifier | Description |
|-----------|-------------|
| %c | Print a character |
| %s | Print a string |
| %% | Print a percent sign |
| %d | Print a decimal integer |
| %i | Print an integer |

## Function Prototype
```c
int _printf(const char *format, ...);
```

## Return Value
Number of characters printed (excluding the null byte)

## Files
- _printf.c - Main printf function
- print_char.c - Handle character conversion
- print_string.c - Handle string conversion
- print_number.c - Handle integer conversion
- main.h - Header file with prototypes

## Authors
See AUTHORS file
