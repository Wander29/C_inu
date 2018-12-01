#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 8
#define MIN 0
#define MAX 110

void merge_sort(int a[], size_t dim);
void sort(int a[], size_t start, size_t end);
void merge(int a[], size_t start, size_t centro1, size_t centro2, size_t end);

int main()
{
	int mat[N] = {0};

	for (size_t j = 0; j < N; j++) 
		mat[j] = MIN + rand() % MAX + 1;

	for (size_t j = 0; j < N; j++) 
		printf("%-3d ", mat[j]);
	printf("\n");

	merge_sort(mat, N);

	printf("\n");
	for (size_t j = 0; j < N; j++) 
		printf("%-3d ", mat[j]);
	printf("\n");

	return 0;
}

void merge_sort(int a[], size_t dim)
{
	sort(a, 0, dim-1);
}

void sort(int a[], size_t start, size_t end)
{
	if ((end-start) >= 1)
	{
		size_t centro1 = (end+start) / 2;
		size_t centro2 = centro1 + 1;

		sort(a, start, centro1);
		sort(a, centro2, end);

		merge(a, start, centro1, centro2, end);
	}
}

void merge(int a[], size_t start, size_t centro1, size_t centro2, size_t end)
{
	size_t 	cnt_sx = start,
			cnt_dx = centro2,
			cnt_fin = 0;
	int aux[end-start+1];

	while(cnt_sx <= centro1 && cnt_dx <= end)
	{
		if(a[cnt_sx] <= a[cnt_dx])
			aux[cnt_fin++] = a[cnt_sx++];
		else
			aux[cnt_fin++] = a[cnt_dx++];
	}
	if (cnt_sx == centro2)
	{
		while(cnt_dx <= end)
			aux[cnt_fin++] = a[cnt_dx++];
	} else 
	{
		while(cnt_sx <= centro1)
			aux[cnt_fin++] = a[cnt_sx++];
	}

	for (size_t j = start; j <= end; j++)
		a[j] = aux[j-start];
}