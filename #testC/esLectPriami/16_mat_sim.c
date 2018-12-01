#include <stdio.h>

#define ROW 4
#define COL 4

short simm(int a[][COL], size_t r, size_t c);

int main()
{
	int mat[ROW][ROW] = {0};

	for (size_t j = 0; j < ROW; j++)
	{
		for (size_t k = 0; k < ROW; k++)
			scanf("%d", &mat[j][k]);
	}
	printf("Matrice %s\n", simm(mat, 0, 0) ? "SIMMETRICA" : "NON SIMMETRICA");
	return 0;
} 

short simm(int a[][COL], size_t r, size_t c)
{
	if (a[r][c] != a[c][r])
		return 0;
	else
		if (c < r)
			simm(a, r, ++c);
	else
		if (r < COL-1)
			simm(a, ++r, 0);
	else
		return 1;
}