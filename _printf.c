#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - formatlı mətn çap edir (printf-in sadələşdirilmiş versiyası)
 * @format: format string
 * Return: çap olunan simvolların sayı, və ya xəta (-1)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;
    char ch;
    char *str;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        // Əgər tək '%' varsa və sonra heç nə yoxdursa → çıx
        if (format[i] == '%' && format[i + 1] == '\0')
        {
            va_end(args);
            return (-1);
        }

        if (format[i] == '%' && format[i + 1])
        {
            i++;
            if (format[i] == 'c')
            {
                ch = va_arg(args, int);
                write(1, &ch, 1);
                count++;
            }
            else if (format[i] == 's')
            {
                str = va_arg(args, char *);
                if (str == NULL)
                    str = "(null)";
                while (*str)
                {
                    write(1, str++, 1);
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
                // Əgər tanınmayan format varsa, onu olduğu kimi çap et
                write(1, "%", 1);
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

    va_end(args);
    return (count);
}
