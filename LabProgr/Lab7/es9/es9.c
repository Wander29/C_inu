#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_int();
void mult_trasp();


int main()
{
	int r = read_int(), c = read_int();

	//printf("\nR: %d\tC: %d\n", r, c);

	int** mat = calloc(r, sizeof(int*));
	for (short j = 0; j < r; j++)
		*(mat+j) = calloc(c, sizeof(int));

	for (size_t j = 0; j < r; j++)
	{
		for (size_t k = 0; k < c; k++)
			*(*(mat+j)+k) = read_int();
	}

	
	/*for (size_t j = 0; j < r; j++)
	{
		for (size_t k = 0; k < c; k++)
			printf("%d ", *(*(mat+j)+k) );
		printf("\n");
	}
	printf("TRASP\n");
	*/
	
	mult_trasp(&mat, r, c);
	
	/*for (size_t j = 0; j < c; j++) // stampo c righe e r colonne, ma la mia matrice rimane r righe × c colonne
	{
		for (size_t k = 0; k < r; k++)
			printf("%d ", *(*(mat+k)+j) ); 	// TRASPOSTA: scambio gli indici dei cicli, E ottengo c righe per r colonne
											// ho però la matrice salvata in r righe e c col, perciò mi sposto verticalmente 
											// di r ma stampo come se mi spostassi orizzontalmente
		printf("\n");
	}*/
	
	free(mat);
	mat = NULL;

	return 0;
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

void mult_trasp(int*** m, size_t row, size_t col)
{
	int aux = 0;
	// printf("M: %d\tMt: %d\n", *(*(*m)), 0);
	//printf("%d\n\n", *m[0][0]); 	// Posso accedere agli elementi della matrice anche con gli indici 
									// (va derefernziato il ptr poichè un param)
	for (size_t j = 0; j < row; j++) // righe result -> fino a c
	{
		for (size_t k = 0; k < row; k++) // colonne result -> fino a r
		{
			for (size_t l = 0; l < col; l++) // scorrimento interno per ogni moltiplicazione
			{
				aux += *(*(*m+j)+l) * *(*(*m+k)+l);
				//printf("M: %d\tMt: %d\n", *(*(*m+j)+l), *(*(*m+k)+l));
			} 
			printf("%d ", aux);
			aux = 0;
		}	
		printf("\n");
	}
}