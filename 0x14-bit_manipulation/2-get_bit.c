#include <stdio.h>

/**
 * get_bit - gets value of a bit in a given index
 * @n: number to extract the bit from
 * @index: the index of the bit to extract
 *
 * Return: value of the bit at the given index, or -1 if an error occurs
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask = 1UL << index;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	return ((n & mask) ? 1 : 0);
}
