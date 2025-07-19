#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - simplified printf handling % and %c
 * @format: format string
 * Return: number of chars printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	char c;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				c = (char)va_arg(args, int);
				write(1, &c, 1);
				count++;
			}
			else if (format[i] == '%')
			{
				write(1, "%", 1);
				count++;
			}
			else
			{
				/* Unknown format specifier, just print it as is */
				write(1, "%", 1);
				write(1, &format[i], 1);
				count += 2;
			}
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
			i++;
		}
	}

	va_end(args);
	return (count);
}
