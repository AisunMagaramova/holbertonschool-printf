#include "main.h"
#include <unistd.h>

/**
 * print_percent - Prints a percent sign
 * Return: Number of characters printed (1)
 */
int print_percent(void)
{
	return (write(1, "%", 1));
}
