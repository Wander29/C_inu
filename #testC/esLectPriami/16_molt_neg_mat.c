#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COL 4

long long multiply(int mat[][COL], size_t dim, size_t r, size_t c);

int main()
{
	int mat[ROW][COL] = {0};
	for (int j = 0; j < ROW; j++)
	{
		for (int k = 0; k < COL; k++)
			scanf("%d", *(mat+j)+k );
	}

	printf("ProdNegativi: %lld\n", multiply(mat, ROW, 0, 0));
	/*
	for (int j = 0; j < ROW; j++)
	{
		for (int k = 0; k < COL; k++)
			printf("%d ", mat[j][k]);
		printf("\n");
	}*/

	return 0;
}

long long multiply(int mat[][COL], size_t dim, size_t r, size_t c)
{
	static long long int sum = 1;
	static long long int temp = 0;

	printf("%d\n", 32);

	if (mat[r][c] < 0)
	{
		temp = sum;
		sum *= mat[r][c];
		if (temp != 0 && sum/temp != mat[r][c])
		{
			puts("Overflow, Orbene\n");
			exit (EXIT_FAILURE);
		}
	}

	if (c < COL-1)
		return multiply(mat, dim, r, ++c);
	else if (r < dim-1)
		return multiply(mat, dim, ++r, 0);
	else
		return sum;

}