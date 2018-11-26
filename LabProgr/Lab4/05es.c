#include <stdio.h>

typedef enum{	
				OK,
				ERROR
			}state;

int ask_input(char c);

int main(){
	int h = 0, l = 0;

	h = ask_input('h');
	l = ask_input('l');

	for (int a = 0; a < l; a++)
	{
		printf("*");
	}

	if(h > 1)
	{
		printf("\n");
		for (int c = 0; c < (h-2); c++)
		{
			printf("*");
			for (int a = 0; a < l - 2; a++)
			{
				printf(" ");
			}
			printf("*\n");
		}

		for (int a = 0; a < l; a++)
		{
			printf("*");
		}
	} 
	printf("\n");
	return 0;

}

int ask_input(char c)
{
	int var = 0;
	
	while ( scanf("%d", &var) < 1  || (var < 1) ) 
	{
	 	printf("%c incorretto. Introdurre un intero maggiore di 0.\n", c);
	 	while (getchar() != '\n');
	}

	return var;
}