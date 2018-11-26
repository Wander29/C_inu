#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 3

char vincitore(char*** mat, size_t dim);

int main()
{
	char** mat = calloc(N, sizeof(char*));
	for (int a = 0; a < N; a++)
		mat[a] = calloc(N, sizeof(char));

	for (int j = 0; j < N; j++)
	{
		for (int k = 0; k < N; k++)
		{
			scanf(" %c", *(mat+j)+k);
		}
	}

	//printf("\n%c\n%c\n%c\n", *(*(mat)+1), *(*(mat+1)+1), *(*(mat+2)+1) );

	char vinc = vincitore(&mat, N);

	if (vinc == '-')
		printf("pareggio\n");
	else
		printf("vince %c\n", vinc);
	

	return 0;
}

char vincitore(char*** mat, size_t dim)
{
	char temp[dim + 1];
	temp[dim] = '\0';

	/*for (int j = 0; j < N; j++)
	{
		for (int k = 0; k < N; k++)
		{
			printf(" %c", *(*(*mat+j)+k));
		}
		printf("\n");
	}*/

	char x[dim+1], o[dim+1];
	for (size_t a = 0; a < dim; a++)
	{
		*(x+a) = 'x';
		*(o+a) = 'o';
	}
	x[dim] = '\0';
	o[dim] = '\0';

	//confronto ogni riga/colonna/diagonale con tutte x o tutte o
	for (size_t j = 0; j < dim; j++)
	{
	//RIGHE
		for (size_t k = 0; k < dim; k++)
		{
			temp[k] = *(*(*mat+j)+k); //dereferenziare anche il parametro puntatore al puntatore
		}
		if (strcmp(temp, x) == 0)
			return 'x';
		else if (strcmp(temp, o) == 0)
			return 'o';
	//COLONNE
		for (size_t k = 0; k < dim; k++)
		{
			temp[k] = *(*(*mat+k)+j);
		}
		if (strcmp(temp, x) == 0)
			return 'x';
		else if (strcmp(temp, o) == 0)
			return 'o';
	}
//DIAGONALE
	for (size_t a = 0; a < dim; a++ )
	{
		temp[a] = *(*(*mat+a)+a);
		if (strcmp(temp, x) == 0)
			return 'x';
		else if (strcmp(temp, o) == 0)
			return 'o';
	}
	return '-';
}