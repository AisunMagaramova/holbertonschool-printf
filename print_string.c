#include "main.h"
#include <unistd.h>

/**
 * print_string - Prints a string
 * @args: va_list containing the string
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int i = 0;

	if (!str)
		str = "(null)";

	while (str[i])
		write(1, &str[i++], 1);

	return (i);
}
