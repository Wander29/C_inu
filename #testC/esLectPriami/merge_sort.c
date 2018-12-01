#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 8
#define MIN 0
#define MAX 110

void merge_sort(int a[], size_t dim, char order);
void sort(int a[], size_t start, size_t end, char order);
void merge(int a[], size_t sin, size_t centro1, size_t centro2, size_t dx, char order);


int main()
{

	int mat[N] = {0};

	printf("Crescente / Decrescente? <c> <d>\n");
	char ordine;
	scanf("%c", &ordine);

	for (size_t j = 0; j < N; j++) 
		mat[j] = MIN + rand() % MAX + 1;

	printf("\n");
	for (size_t j = 0; j < N; j++) 
		printf("%-3d ", mat[j]);
	printf("\n");

	merge_sort(mat, N, ordine);

	printf("\n");
	for (size_t j = 0; j < N; j++) 
		printf("%-3d ", mat[j]);
	printf("\n");
}

void merge_sort(int a[], size_t dim, char order)
{
	sort(a, 0, dim-1, order);
}

void sort(int a[], size_t start, size_t end, char order)
{
	if ( (end - start) >= 1) // non è il caso base
	{
		size_t centro1 = (start+end) / 2; // divisone intera
		size_t centro2 = centro1 + 1;
	// divido l'array e ordino i 2 sottoarray - ricorsivamente
		sort(a, start, centro1, order);
		sort(a, centro2, end, order);
	// fondo i sottoarray ordinati
		merge(a, start, centro1, centro2, end, order);
	}
// else: array di dim 1, ma ovviamente è già ordinato
}

void merge(int a[], size_t sin, size_t centro1, size_t centro2, size_t dx, char order)
{
	size_t sin_i = sin;
	size_t dx_i = centro2;
	size_t fondi_i = 0;

	int temp_a[dx - sin + 1];
	while (sin_i <= centro1 && dx_i <= dx)
	{ // inserisce nell'array finale l'elemento corretto in base all'ordinamento scelto
		switch(order)
		{
			case 'c':
				if (a[sin_i] <= a[dx_i])
					temp_a[fondi_i++] = a[sin_i++];
				else
					temp_a[fondi_i++] = a[dx_i++];
				break;

			case 'd':
				if (a[sin_i] <= a[dx_i])
					temp_a[fondi_i++] = a[dx_i++];
				else
					temp_a[fondi_i++] = a[sin_i++];
				break;

			default:
				break;
		}
	}
	if (sin_i == centro2) // esaurito sottoarray sinistro
	{
		while (dx_i <= dx)
			temp_a[fondi_i++] = a[dx_i++];
	} else // esaurito sottoarray destro
	{
		while(sin_i <= centro1)
			temp_a[fondi_i++] = a[sin_i++];
	}
//copio array temp in quello originale
	for (size_t j = sin; j <= dx; j++)
		a[j] = temp_a[j-sin];
}

