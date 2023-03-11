#include <stdio.h>
#include "main.h"

/**
 * main - prints all the argument it recieves
 * @argc: counts argument
 * @argv: array of argument
 * Return: 0 (success)
 */
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	return (0);
}
