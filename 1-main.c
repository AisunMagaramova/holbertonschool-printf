#include "main.h"

int main(void)
{
	my_printf("Hello %d World %i!\n", 42, -100);
	my_printf("This is 123 and %d again\n", 456);
	my_printf("Unknown specifier: %x, %% sign\n");
	return (0);
}
