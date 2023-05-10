#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * read_textfile - read text file to standard output
 * @filename: textfile read
 * @letters: length of letter read
 * Return: 0 whenfunction fail or filr is Null
 * Actual number of byte on success
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t y;
	ssize_t w;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	w = read(fd, buf, letters);
	y = write(STDOUT_FILENO, buf, w);

	free(buf);
	close(fd);
	return (y);
}
