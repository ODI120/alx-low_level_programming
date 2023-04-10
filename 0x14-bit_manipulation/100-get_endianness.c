#include <stdio.h>

/**
 * get_endianness - this wil check the endianness of the system
 *
 * Return: 0 if the system is big endian, 1 if it is little endian
 */
int get_endianness(void)
{
	unsigned int may = 1;
	char *c = (char *)&may;

	if (*c)
		return (1); /* little endian */
	else
		return (0); /* big endian */
}
