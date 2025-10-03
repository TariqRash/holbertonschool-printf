#include <stdio.h>
#include "../main.h"

int main(void)
{
	/* Test binary */
	_printf("Binary of 98: %b\n", 98);
	
	/* Test pointer */
	void *ptr = (void *)0x7ffe637541f0;
	_printf("Pointer: %p\n", ptr);
	
	/* Test reverse */
	_printf("Reverse: %r\n", "Hello");
	
	/* Test ROT13 */
	_printf("ROT13: %R\n", "Hello");
	
	return (0);
}
