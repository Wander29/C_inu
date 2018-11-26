#include <stdio.h>

int read_int();
void ordered_swap(int *v1, int *v2, int *v3);
void ordina_d(int *a, int *b);

int main()
{
	int vet[3];
	for (short a = 0; a < 3; a++)
		vet[a] = read_int();
	ordered_swap(&vet[0], &vet[1], &vet[2]);
	for (short a = 0; a < 3; a++)
		printf("%d\n", vet[a]);
	return 0;
} 

int read_int()
{
	int temp;
	while ( scanf("%d", &temp) != 1)
	{
		scanf("%*[^\n]%*c");
	}
	return temp;
}

void ordered_swap(int *v1, int *v2, int *v3)
{
	ordina_d(v1, v2);
	ordina_d(v1, v3);
	ordina_d(v2, v3);
}

void ordina_d(int *a, int *b)
{
	if (*a < *b) {}
	else
	{
		*a += *b;
		*b = *a - *b;
		*a -= *b;
	}
}