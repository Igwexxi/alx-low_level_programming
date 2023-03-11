#include <stdio.h>
#include "main.h"

/**
 * main - prints its name
 * @argc: counts number of argument
 * @argv: array of argument
 * Return: Always 0 (success)
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", *argv);

	return (0);
}
