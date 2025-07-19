#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
int my_printf(const char *format, ...);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(void);
int _putchar(char c);
#endif
