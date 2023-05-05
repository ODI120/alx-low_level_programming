#include <stdlib.h>
#include <string.h>


/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: A string of 0 and 1 chars.
 *
 * Return: The converted number, or 0 if there is one or more chars in the
 * string b that is not 0 or 1, or if b is NULL.
 */

unsigned int binary_to_uint(const char *b)
{
	size_t len;
	unsigned int result = 0;
	size_t i;

	if (b == NULL)
	{
	return (0);
	}

	len = strlen(b);

	for (i = 0; i < len; i++)
	{
	char c = b[i];

	if (c != '0' && c != '1')
	{
		return (0);
	}
	result = result * 2 + (c - '0');
	}

	return (result);
}
