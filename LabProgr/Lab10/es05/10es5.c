#include <stdio.h>
#include <stdlib.h>

int read_int();
void azzera_diagonali(int*** const mat, const size_t dim);

int main()
{
	int dim = read_int();
	int** mat = calloc(dim, sizeof(int*));

	//printf("%d", dim);
	for (int j = 0; j < dim; j++)
	{
		*(mat+j) = calloc(dim, sizeof(int));
	}

	for (int j = 0; j < dim; j++)
	{
		for (int k = 0; k < dim; k++)
			scanf("%d", *(mat+j)+k );
	}

	azzera_diagonali(&mat, dim);

	for (int j = 0; j < dim; j++)
	{
		for (int k = 0; k < dim; k++)
			printf("%d ", *(*(mat+j) + k) );
		printf("\n");
	}
	

	for (int j = 0; j < dim; j++)
	{
		free(mat[j]);
	}
	free(mat);

	return 0;
} 

int read_int()
{
	int temp;
	while (scanf("%d", &temp) != 1)
	{
		scanf("%*[^/n]%*c");
	}
	return temp;
}

void azzera_diagonali(int*** const mat, const size_t dim)
{
	for (int j = 0; j < dim; j++)
	{
		*(*(*mat+j)+j) = 0;
	}

	int k = 0;
	for (int j = dim-1; j >= 0; j--)
	{
		*(*(*mat+(k++))+j) = 0;
	}
}