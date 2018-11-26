#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 3

int main()
{
	char **mat = calloc(N, sizeof(char*)); //char mat[N][N];
	for (int a = 0; a < N; a++)
		mat[a] = calloc(N, sizeof(char));

	for (int j = 0; j < N; j++)
	{
		for (int k = 0; k < N; k++)
		{
			scanf(" %c", *(mat+j)+k); //spazio C -> teoricamente svuota il buffer 
		}
	}

	for (int j = 0; j < N; j++)
	{
		for (int k = 0; k < N; k++)
			printf("%c ", *(*(mat+j)+k) );

		printf("\n");
	}
	
} 
