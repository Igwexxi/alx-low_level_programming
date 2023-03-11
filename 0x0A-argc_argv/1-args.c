#include <stdio.h>
#include "main.h"

/**
 * main - prints the number of argument passed to it
 * @argc: counts number of argument
 * @argv: array of argument
 *
 * Return: 0 (success)
 */
int main(int argc, char *argv[])
{
	(void) argv; /*ignore argv*/
	printf("%d\n", argc - 1);

	return (0);
}
