#include <stdio.h>

/**
 * flip_bits - this will definatly  return the number of bit needed to flip to get from
 * one number to another
 * @n: the first number
 * @m: the second number
 *
 * Return: the number of bits that are different between n and m
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int dec = n ^ m;
	unsigned int may = 0;

	while (dec)
	{
		may += dec & 1;
		dec >>= 1;
	}

	return (may);
}
