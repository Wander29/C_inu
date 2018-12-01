#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4
#define MIN 0
#define MAX 100

void genTrasp(int a[][N], int b[][N], size_t r, size_t c);

int main()
{

	int mat[N][N] = {0};

	for (size_t j = 0; j < N; j++)
	{
		for (size_t k = 0; k < N; k++)
			mat[j][k] = MIN + rand() % MAX + 1;
	}

	int trasp[N][N] = {0};
	genTrasp(mat, trasp, 0, 0);

	for (size_t j = 0; j < N; j++)
	{
		for (size_t k = 0; k < N; k++)
			printf("%3d ", mat[j][k] );
		printf("  |  ");
		for (size_t k = 0; k < N; k++)
			printf("%3d ", trasp[j][k] );
		printf("\n");
	}


	return 0;
} 

void genTrasp(int a[][N], int b[][N], size_t r, size_t c)
{
	b[r][c] = a[c][r];
	if (c < N-1)
		genTrasp(a, b, r, c+1);
	else if(r < N-1)
		genTrasp(a, b, r+1, 0);
}
