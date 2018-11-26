#include <stdio.h>

int parti(int n);

int main()
{
	int n;

	while ( scanf("%d", &n) < 1 || n < 1)
	{
		while (getchar() == '\n');
	}

	printf("parti del piano: %d\n", parti(n));
}

int parti(int n)
{
	if (n == 1)
		return 2;
	else
		return parti(n-1) + n;
}