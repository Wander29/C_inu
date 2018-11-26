#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define NMAX 3

int read_int();
bool func(int *b, int a_min);

int main()
{
	int vet[NMAX];
	int vet2[NMAX];
	int vet_min = INT_MAX;

	for(short a = 0; a < NMAX; a++)
	{
		vet[a] = read_int();
		if(vet[a] < vet_min)
			vet_min = vet[a];
	}

	for(short a = 0; a < NMAX; a++)
		vet2[a] = read_int();

	if (func(vet2, vet_min))
		printf("TRUE\n");
	else
		printf("FALSE\n");
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

bool func(int *b, int a_min)
{
	for(short a = 0; a < NMAX; a++)
	{
		if (b[a] <= a_min)
			return false;
	}
	return true;
}