#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * print_number - int ededi yazır e  uzunlugnu qaytarır
 * @n: çap olunacaqeded
 *
 * Return: çap olunan simvol sayı
 */
int print_number(int n)
{
    char buffer[50];
    int len;

    len = sprintf(buffer, "%d", n);
    write(1, buffer, len);
    return len;
}

/**
 * _printf - sad  printf funksiyas�
 * @format: format setiri
 *
 * Return: çap olunan simvolların sayı
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'd' || *format == 'i')
            {
                int num = va_arg(args, int);
                count += print_number(num);
            }
            else
            {
                if (*format)
                {
                    write(1, format, 1);
                    count++;
                }
            }
            format++;
        }
        else
        {
            write(1, format, 1);
            count++;
            format++;
        }
    }

    va_end(args);

    return count;
}
