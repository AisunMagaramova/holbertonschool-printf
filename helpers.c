#include "main.h"

/**
 * print_char - prints a character
 * @args: va_list
 * Return: number of characters printed
 */
int print_char(va_list args)
{
	char c = (char)va_arg(args, int);
	_putchar(c);
	return (1);
}

/**
 * print_string - prints a string
 * @args: va_list
 * Return: number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int i = 0;

	if (!str)
		str = "(null)";
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

/**
 * print_percent - prints a percent sign
 * Return: 1
 */
int print_percent(void)
{
	_putchar('%');
	return (1);
}
