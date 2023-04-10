#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/**
 * create_file - this wil create a file with the given name and writes the given
 *text to it
 * @filename: name of the file to create
 * @text_content: content to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int i, h, l;

	if (filename == NULL)
		return (-1);

	i = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (i == -1)
		return (-1);

	if (text_content != NULL)
	{
		l = strlen(text_content);
		h = write(i, text_content, l);
		if (h == -1 || h != l)
		{
			close(i);
			return (-1);
		}
	}

	close(i);
	return (1);
}
