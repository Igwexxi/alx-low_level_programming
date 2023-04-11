#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * append_text_to_file - It appends text at the end of a file
 * @filename: Is the name of the file
 * @text_content: Is the NULL terminated string to add at the end of the file
 *
 * Return: If the function fails or filename is NULL -1
 *	1 on success -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int o, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	o = open(filename, O_WRONLY | O_APPEND);
	w = write(o, text_content, len);

	if (o == -1 || w == -1)
		return (-1);

	close(o);

	return (1);
}
