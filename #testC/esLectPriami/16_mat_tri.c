#include <stdio.h>

#define DIM 3

short tsup(int a[][DIM], size_t r, size_t c);
short tinf(int a[][DIM], size_t r, size_t c);

int main()
{
	int mat[DIM][DIM] = {0};

	for (size_t j = 0; j < DIM; j++)
	{
		for (size_t k = 0; k < DIM; k++)
			scanf("%d", &mat[j][k]);
	}
	printf("Matrice %s\n", tinf(mat, 1, 0) ? "TRI INF" : "NON tri inf");
	printf("Matrice %s\n", tsup(mat, 0, 1) ? "TRI SUP" : "NON tri sup");
	return 0;
} 

short tsup(int a[][DIM], size_t r, size_t c)
{
	if (a[r][c] != 0)
		return 0;
	else if (c < r-1)
		tinf(a, r, ++c);
	else if (r < DIM - 1)
		tinf(a, ++r, 0);
	else 
		return 1;
}

short tinf(int a[][DIM], size_t r, size_t c)
{
	/*
	static short cnt;
	printf("CNT: %d\n", ++cnt);
	*/
	if (a[r][c] != 0)
		return 0;
	else if (c < DIM-1)
		tsup(a, r, ++c);
	else if (r < DIM-2)
		tsup(a, ++r, r+2);
	else
		return 1;
}