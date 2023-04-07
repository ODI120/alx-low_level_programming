#include <stdio.h>
/**
 * print_binary - prints the binary representation of a number
 * @n: the number to print in binary
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	unsigned long int bit = 1UL << (sizeof(unsigned long int) * 8 - 1);

	while (bit)
	{
		if (n & bit)
			putchar('1');
		else
			putchar('0');
		bit >>= 1;
	}
}
