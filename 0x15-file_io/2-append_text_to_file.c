#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * append_text_to_file - append text to a file end
 * @filename: is the name of the file
 * @text_content: is the NULL terminated string to add at the end of the file
 * Return: 1 on success and -1 on failure
 * If text_content is NULL, Return 1 if the file exists
 * and -1 if the file does not exist
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int a = 0;
	int c = 0;
	int len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	a = open(filename, O_WRONLY | O_APPEND);
	c = write(a, text_content, len);

	if (a == -1 || c == -1)
		return (-1);

	close(a);

	return (1);
}
