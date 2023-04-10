#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>

/**
 * read_textfile - this is going to read a text
 *file and prints it to the POSIX standard output
 * @filename: name of the file to read
 * @letters: number of letters to read and print
 *
 * Return: the actual number of letters read and printed, or 0 on failure
 */
size_t read_textfile(const char *filename, size_t letters)
{
	int fedd;
	size_t n_read, n_written;
	char *june;

	if (!filename)
		return (0);

	june = malloc(sizeof(char) * letters);
	if (!june)
		return (0);

	fedd = open(filename, O_RDONLY);
	if (fedd == -1)
	{
		free(june);
		return (0);
	}

	n_read = read(fedd, june, letters);
	if ((n_read = -1))
	{
		free(june);
		close(fedd);
		return (0);
	}

	n_written = write(STDOUT_FILENO, june, n_read);
	if (n_written != n_read)
	{
		free(june);
		close(fedd);
		return (0);
	}

	free(june);
	close(fedd);
	return (n_written);
}
