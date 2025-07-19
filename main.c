#include "main.h"

/**
 * main - test _printf function
 * Return: 0
 */
int main(void)
{
	int len;

	len = _printf("Hello %s!\nGrade: %c%%\n", "Spur", 'A');
	_printf("Printed %s chars\n",
		(len == -1) ? "no" : "some");

	return (0);
}
