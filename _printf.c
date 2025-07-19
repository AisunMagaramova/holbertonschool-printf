#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_int - prints an integer
 * @n: integer to print
 */
static void print_int(int n)
{
	char buf[12];
	int i = 0;
	int is_negative = 0;

	if (n == 0)
	{
		write(1, "0", 1);
		return;
	}
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	while (n > 0)
	{
		buf[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (is_negative)
		buf[i++] = '-';
	while (i--)
		write(1, &buf[i], 1);
}

/**
 * _printf - simplified printf, only handles %d and %i
 * @format: format string
 * Return: number of characters printed (not implemented fully)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;

	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'd' || format[i] == 'i')
			{
				print_int(va_arg(args, int));
			}
			else
			{
				write(1, "%", 1);
				if (format[i] != '\0')
					write(1, &format[i], 1);
			}
		}
		else
		{
			write(1, &format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (0); /* Return value ignored in this task */
}
