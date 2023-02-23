#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes the charcter c to stdout
 * gc: The character to print
 *
 * Return: On Success 1.
 * On error, -1 is returned, and error is set appropraitely.
 */
int _putchar(char c)
{	
	return (write(1, &c, 1));
}
