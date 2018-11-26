#include <stdio.h>

#define MAX 5

int main()
{
	int a[MAX], b[MAX];

	for (int i = 0; i < MAX; i++)
	{
		while (scanf("%d", &a[i]) < 1)
		{
			while (getchar() != '\n');
		}
	}

	for (int i = 0; i < MAX; i++)
	{
		while (scanf("%d", &b[i]) < 1)
		{
			while (getchar() != '\n');
		}
	}

	printf("[");
	for (int i = 0; i < MAX; i++)
	{
		printf("%d", a[i]);
		if(i != MAX-1)
			printf(",");
	}
	printf("]\n");

	printf("[");
	for (int i = 0; i < MAX; i++)
	{
		printf("%d", b[i]);
		if(i != MAX-1)
			printf(",");
	}
	printf("]\n");

	printf("[");
	for (int i = 0; i < MAX; i++)
	{
		printf("%d", a[i] + b[i]);
		if(i != MAX-1)
			printf(",");
	}
	printf("]\n");

	return 0;
}