#include <stdio.h>
#include "main.h"

/**
 * binary_to_uint - convert a binary number to an unsigned int
 * @b: char string
 * Return: converted decimal number or 0 if there is an unconvertable char
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int mins, puncs;
	int len;

	if (b == NULL)
		return (0);

	for (len = 0; b[len]; len++)
	{
		if (b[len] != '0' && b[len] != '1')
			return (0);
	}
	for (puncs = 1, mins = 0, len--; len >= 0; len--, puncs *= 2)
	{
		if (b[len] == '1')
			mins += puncs;
	}

	return (mins);
}
