#include <stdio.h>

int main(){
	int x = 0, f0 = 0, f1 = 1;
	int f2 = f0 + f1;

	enum state {OK, ERROR};

	enum state stato = ERROR;

	while (stato == ERROR)
	{
		while ( scanf("%d", &x) < 1 ) 
		{
		 	printf("Inserire un intero positivo\n");
		 	while (getchar() != '\n');
		}
		if (x >= 0)
			stato = OK;
		else
			printf("Inserire un intero positivo\n");
	}

	printf("%d\n", f0);
	if (x == 0)
	{ }
	else 
	{
		printf("%d\n", f1);
		do 
		{
			f0 = f1;
			f1 = f2;
			printf("%d\n", f2);
			f2 = f1 + f0;
		} while ( f2 <= x );
	}
}