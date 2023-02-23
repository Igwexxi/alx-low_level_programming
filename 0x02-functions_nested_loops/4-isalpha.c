#include "main.h"

/**
 * _isalpha - checkes for alphabet
 * @c: The character to be checked
 * Return: 1 if c is a letter, lowercase or uppercase 0 if otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
	return (1);
	}
	return (0);
}
