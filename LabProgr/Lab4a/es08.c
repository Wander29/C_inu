#include <stdio.h>

int main()
{
	int x;

	while (scanf("%d", &x) < 1 || x <= 0)
	{
		while (getchar() != '\n');
	}
	
	for (int i = 1; i <= 10; i ++)
	{
		printf("%d\n", x * i);
	}

	return 0;
}