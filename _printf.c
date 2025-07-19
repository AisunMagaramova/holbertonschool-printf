#include "main.h"
#include <unistd.h>

/**
 * _printf - formatlı çap funksiyası
 * @format: format string
 * Return: çap olunan simvol sayı
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')  /* tək % varsa, ardınca heç nə yoxdursa */
			{
				va_end(args);
				return (-1);
			}
			else if (format[i + 1] == '%')  /* %% isə % çap edir */
			{
				write(1, "%", 1);
				count++;
				i += 2;
				continue;
			}
			else
			{
				write(1, "%", 1);
				count++;
				i++;
				continue;
			}
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
