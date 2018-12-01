#include <stdio.h>
#include <stdlib.h>

void multiplyMat(int*** const mA, int*** const mB, int*** mC, const  size_t n, const  size_t m, const size_t s);

int main()
{
	int n, m, s;
	int** mA, **mB, **mC;
	scanf("%d\n%d\n%d", &n, &m, &s);
	
	mA = calloc(n, sizeof(int*));
	for(int j = 0; j < n; j++)
		mA[j] = calloc(m, sizeof(int));

	mB = calloc(m, sizeof(int*));
	for(int j = 0; j < m; j++)
		mB[j] = calloc(s, sizeof(int));

	mC = calloc(n, sizeof(int*));
	for(int j = 0; j < n; j++)
		mC[j] = calloc(s, sizeof(int));

	if (!mA || !mB || !mC)
		exit(EXIT_FAILURE);

// Lettura matriceA
	for (int j = 0; j < n; j++)
	{
		for (int k = 0; k < m; k++)
		{
			scanf("%d",  *(mA + j) + k );
		}
	}
// Lettura matriceB
	for (int j = 0; j < m; j++)
	{
		for (int k = 0; k < s; k++)
		{
			scanf("%d",  *(mB + j) + k );
		}
	}

	multiplyMat(&mA, &mB, &mC, n, m, s);

// Stampa matriceC
	for (int j = 0; j < n; j++)
	{
		for (int k = 0; k < s; k++)
			printf("%d ", *(*(mC+j)+k) );
		printf("\n");
	}

// Free Memory
	for(int j = 0; j < n; j++)
		free(mA[j]);
	free(mA);

	for(int j = 0; j < m; j++)
		free(mB[j]);
	free(mB);

	for(int j = 0; j < n; j++)
		free(mC[j]);
	free(mC);

	return 0;
}

// @param:
/* 
	-mA = n × m
	-mB = m × s
	-mC = n × s PRODOTTO matriciale tra mA e mB
*/
void multiplyMat(int*** const mA, int*** const mB, int*** mC, const size_t n, const size_t m, const size_t s)
{
	for (size_t j = 0; j < n; j++)
	{
		for (size_t k = 0; k < s; k++)
		{
			for (size_t l = 0; l < m; l++)
				(*mC)[j][k] += (*mA)[j][l] * (*mB)[l][k];
		}
	}
}