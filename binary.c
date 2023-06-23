#include"main.h"
/**
 * print_binary - Prints an unsigned number
 * Return: Number of chars printed
 */
int print_binary(va_list types, char buffer[],
			int flags, int width, int precision, int size)
{
	unsigned int j = va_arg(types, unsigned int);
	unsigned int k = 2147483648; /* (2 ^ 31) */
	unsigned int a[32];
	int count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

											for (int i = 0; i < 32; i++)
						{
	a[i] = (j & k) ? 1 : 0;
		k >>= 1;
		}
	for (int i = 0, sum = 0; i < 32; i++)
														{
																	sum += a[i];
																		if (sum || i == 31)
																						{
																		char z = '0' + a[i];
																	write(1, &z, 1);
																								count++;
																																		}
																				}

													return count;
}

