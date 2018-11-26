#include <stdio.h>
#include <limits.h>

const int BITS = sizeof(unsigned int) * CHAR_BIT;

void stampa_bit(unsigned int n);

int main()
{
	unsigned int num = 8;
	printf("%u\n", num);
	stampa_bit(num);

	return 0;
}

void stampa_bit(unsigned int n)
{
	unsigned int mask = 1 << (BITS - 1);
	for (short a = 0; a < BITS; a++ )
	{
		putchar( mask & n ? '1' : '0');
		n <<= 1;
	}
	putchar('\n');
	return;
}