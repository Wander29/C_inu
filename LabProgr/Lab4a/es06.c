#include <stdio.h>

int main()
{
	int x;

	while (scanf("%d", &x) < 0)
	{
		while (getchar() != '\n');
	}

	if (x > 0)
	{
		for(int i = 0; i < x; i += 2)
		{
			for(int a = 0; a < x-i; a++)
				printf("%c", '*');
			printf("\n");
		}
	}
}