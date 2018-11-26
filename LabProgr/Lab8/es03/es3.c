#include <stdio.h>

#define MAX 7

void primoultimopari(int arr[], int dim, int* primaocc, int* ultimaocc);
int read_int();

int main()
{
	int vet[MAX];
	for(short a = 0; a<MAX; a++)
		vet[a] = read_int();
	int prima = -1, ultima = -1;
	primoultimopari(vet, MAX, &prima, &ultima);
	printf("%d %d", prima, ultima);
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

void primoultimopari(int arr[], int dim, int* primaocc,int* ultimaocc)
{
	for(short a = 0; a < dim; a++)
	{
		if ( *(arr + a) % 2 == 0 && *primaocc == -1)
		{
			*primaocc = a;
		}
		if ( *(arr + (dim - 1) - a) % 2 == 0 )
			*ultimaocc = (dim-1) - a;

		if (*primaocc != -1 && *ultimaocc != -1)
			return;
	}
}

