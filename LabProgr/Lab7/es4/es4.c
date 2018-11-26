#include <stdio.h>

#define NMAX 100

int read_int();
int read_int_dim();

int main()
{
	int vet[NMAX];
	int cnt = read_int_dim();

	for(short a = 0; a < cnt; a++)
		vet[a] = read_int();

	for(short a = 0; a < cnt - 1; a++)
	{
		if ( (vet[a] >= 0 && vet[a] % 2 == 0) || (vet[a] < 0 && vet[a+1] >= 0) )
			printf("%d\n", vet[a]);
	}
	if ( (vet[cnt-1] >= 0 && vet[cnt-1] % 2 == 0) )
		printf("%d\n", vet[cnt-1]);
}

int read_int_dim()
{
	int tmp;
	while (scanf("%d", &tmp) != 1 || tmp < 1 || tmp > 100)
	{
		printf("Inserisci un intero positivo compreso fra 1 e 100.\n");
		while (scanf("%*[^\n]%*c"));
	}
	return tmp;
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