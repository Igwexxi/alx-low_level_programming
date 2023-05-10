#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * create_buffer - Hold 1024 byte for a buffer
 * @file: file buff is storing charcater for
 * Return: pointer to the new buffer
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}
/**
 * close_file - closes fd
 * @fd: file descriptor to close
 */
void close_file(int fd)
{
	int j;

	j = close(fd);

	if (j == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
/**
 * main - cp file_from file_to
 * @argc: len of argument given
 * @argv: array of pointer to the argument
 * Return: 0 on success
 *	If file_to or file_from cannot be closed - exit code 100
 *	If file_to cannot be created or written to - exit code 99
 *	If file_from does not exist or cannot be read - exit code 98
 *	If the argument count is incorrect - exit code 97
 */
int main(int argc, char *argv[])
{
	int from, to, x, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	x = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || x == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}
		w = write(to, buffer, x);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}
		x = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (x > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
