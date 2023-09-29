#include "main.h"

/**
 * flip_bits - flip bits to convert one number to another number
 * @n: first number
 * @m: second number to convert to
 * Return: number of bits that was needed to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int difference;
	int diff_bits;

	difference = n ^ m;
	diff_bits = 0;

	while (difference)
	{
		diff_bits++;
		difference &= (difference - 1);
	}

	return (diff_bits);
}
