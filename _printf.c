#include "main.h"
#include <stdarg.h>/*variadic functian ucun lazim olan kitabxana*/
#include <unistd.h>
/**
 * _printf-formatli metin cap edir, printf insade versiyasidir
 * @format-format string
 * return-cap olunan simvollarin sayi
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	char ch;
	char *str;
	if (format == NULL)
		return (-1);
	va_start (args, format);/*argumentleri oxumaga baslamaq*/
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == 'c')
			{
				ch = va_arg(args, int);/*nobeti argumenti al*/
				write(1, &ch, 1);
				count++;
			}
			else if(format[i] == 's')
			{
				str = va_arg(args, char*);
				if (str == NULL )
					str = "(null)";
				while(*str)
				{
					write (1, str++, 1);
					count++;
				}
			}
			else if (format[i] == '%')
			{
				write(1, "%", 1);
				count++;
			}
			else
			{
				write(1," %", 1);
				write(1, &format[i], 1);
				count += 2;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);/*is bitdi*/
	return count;
}
