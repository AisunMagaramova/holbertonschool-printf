#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_int - Prints an integer to standard output.
 * @n: The integer to print.
 */
static void print_int(int n)
{
	char buf[12];
	int i;
	int is_negative;

	i = 0;
	is_negative = 0;

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
 * my_printf - Custom printf function supporting %d and %i.
 * @format: Format string.
 *
 * Return: Number of characters printed (currently returns 0).
 */
int my_printf(const char *format, ...)
{
	va_list args;
	int i;

	va_start(args, format);
	i = 0;
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
				else
					break;
			}
		}
		else
			write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (0);
}
