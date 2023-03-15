#include "main.h"
#include <stdlib.h>

/**
 * create_array - create an array of chars and initialize with a specific chars
 * @size: size of array
 * @c: chars to be initialize
 * Return: NULL if it fails
 */
char *create_array(unsigned int size, char c)
{
	char *str;

	unsigned int n;

	str = malloc(sizeof(char) * size);

	if (size == 0 || str == NULL)
		return (NULL);

	for (n = 0; n < size; n++)

		str[n] = c;

	return (str);
}
