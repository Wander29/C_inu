#include <stdio.h>

int main()
{
	int n, x = 1;

	while ( scanf("%d", &n) < 1 || n < 1)
	{
		while (getchar() == '\n');
	}

	for (int i = 1; i <= n; i++)
	{
		x += i;
	}
	printf("parti del piano: %d\n", x);
}