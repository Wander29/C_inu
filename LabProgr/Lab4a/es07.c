#include <stdio.h>

int main()
{
	int h, b;

	while (scanf("%d", &h) < 0)
	{
		while (getchar() != '\n');
	}

	while (scanf("%d", &b) < 0)
	{
		while (getchar() != '\n');
	}

	if (b > 0 && h > 0)
	{
		for(int i = 0; i < b; i++ )
			printf("%c", '*');

		printf("\n");
		if (h > 2)
		{
			for (int a = 0; a < h - 2; a++)
			{
				printf("%c", '*');

				for(int i = 0; i < b - 2; i++ )
					printf(" ");

				printf("%c", '*');
				printf("\n");
			}

		}
		if (h != 1)
		{
			for(int i = 0; i < b; i++ )
				printf("%c", '*');
		}
		printf("\n");
	}
}