#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include <stdio.h>
#include "main.h"

/**
 * append_text_to_file - this wiil b e able append text to end of file
 * @filename: the name of the file to append text to
 * @text_content: the text to append to the file
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, status;
	ssize_t len = 0;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[len] != '\0')
			len++;
		status = write(fd, text_content, len);
		if (status == -1)
			return (-1);
	}

	close(fd);
	return (1);
}
