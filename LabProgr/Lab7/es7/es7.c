#include <stdio.h>

#define ROW 4
#define COL 3

int read_int();
void somma_matrici(int m1[][COL], int m2[][COL], int row, int col);

int main()
{
	int m1[ROW][COL];
	int m2[ROW][COL];

	for(short a = 0; a < ROW; a++)
	{
		for (short b = 0; b < COL ; b++)
			m1[a][b] = read_int();
	}
	for(short a = 0; a < ROW; a++)
	{
		for (short b = 0; b < COL ; b++)
			m2[a][b] = read_int();
	}
	somma_matrici(m1, m2, ROW, COL);
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

void somma_matrici(int m1[][COL], int m2[][COL], int row, int col)
{
	for (short a = 0; a < row; a ++)
	{
		for (short b = 0; b < col; b++)
			printf("%d ", m1[a][b] + m2[a][b]);
		printf("\n");
	}
}