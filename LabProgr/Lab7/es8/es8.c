#include <stdio.h>
#include <string.h>

int read_int();

void multiply_matr(int A[][2], int B[][3], int C[][3]);

int main()
{
	int mA[4][2];
	int mB[2][3];
	int mC[4][3]; // prodotto matriciale
	memset(mC, 0, sizeof(int)*12); // svuoto la matrice risultato

	for (size_t j = 0; j < 4; j++)
	{
		for(size_t k = 0; k < 2; k++)
			mA[j][k] = read_int();
	}

	for (size_t j = 0; j < 2; j++)
	{
		for(size_t k = 0; k < 3; k++)
			mB[j][k] = read_int();
	}

	multiply_matr(mA, mB, mC);

	for (size_t j = 0; j < 4; j++)
	{
		for(size_t k = 0; k < 3; k++)
			printf("%d ", mC[j][k]);
		printf("\n");
	}

}

int read_int()
{
	int tmp;
	while (scanf("%d", &tmp) != 1)
	{
		printf("Inserisci un intero.\n");
		while (scanf("%*[^\n]%*c"));
	}
	return tmp;
}

void multiply_matr(int A[][2], int B[][3], int C[][3])
{
	for (size_t j = 0; j < 4; j++)
	{
		for(size_t k = 0; k < 3; k++)
		{
			for (size_t l = 0; l < 2; l++)
				C[j][k] += (A[j][l] * B[l][k]);
		}
	}
}
