#include <stdio.h>

#define ROW 4
#define COL 3

int read_int();
short find_col(int a[][COL], int col, int row);

int main()
{
	int vet[ROW][COL];

	for(short a = 0; a < ROW; a++)
	{
		for (short b = 0; b < COL ; b++)
			vet[a][b] = read_int();
	}
	printf("%d\n", find_col(vet, COL, ROW));
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

short find_col(int a[][COL], int col, int row)
{
	for (short j = col - 1; j >= 0; j--)
	{
		for (short b = 0; b < row; b++)
		{
			if (a[b][j] % 3 != 0 )
				goto start_ciclo;
		}
		return j;
		start_ciclo: ;
	}
	return -1;
}