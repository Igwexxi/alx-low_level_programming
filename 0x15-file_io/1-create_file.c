#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * create_file - Create file
 * @filename: Pointer to the named file to create
 * @text_content: Pointer to the str to write to file
 * Return: --1 on fail -1 otherwise
 */
int create_file(const char *filename, char *text_content)
{
	int fd = 0;
	int z = 0;
	int len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	z = write(fd, text_content, len);

	if (fd == -1 || z == -1)
		return (-1);

	close(fd);

	return (1);
}
