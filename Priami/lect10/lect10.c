#include <stdio.h>

int ricors();

int main()
{
	char risp;
	do 
	{
		
		while (getchar() != '\n');
		switch( ricors() )
		{
			case -1:
				printf("\nNon sono 2 parole.. ma puoi ritentare\n");
				break;

			case 0:
				printf("\nTry Again, you'll be luckier\n");
				break;

			case 1:
				if(getchar() == '\n')
					printf("\n!!! Found a _-_Palindroma_-_ !!!\n");
				else
					printf("\nTry Again, you'll be luckier\n");
				break;

			default:
				break; 
		}

		printf("\nVuoi riprovare? [y/n]  ");
		while ( scanf("%[y/n]", &risp) < 1 )
		{
			printf("\nVuoi riprovare? [y/n]  ");
			while (getchar() != '\n');
		}
	} while ( risp == 'y' );
}

int ricors()
{
	char c;
	c = getchar();

	if (c == '*')
		return 1;

	if (c == '\n')
		return -1;

	if (ricors() == 1)
	{
		if (c == getchar())
			return 1;
		else
			return 0;
	} else 
	{
		return 0;
	}
}