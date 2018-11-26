#include <stdio.h>
#include <math.h>

enum state {OK, ERROR};

int main(){
	int x = 0;

	enum state stato = ERROR;

	while (stato == ERROR)
	{
		while ( scanf("%d", &x) < 1 ) 
		{
		 	printf("Incorretto. Inserisci un intero positivo.\n");
		 	while (getchar() != '\n');
		}
		if (x >= 0)
			stato = OK;
		else
			printf("Incorretto. Inserisci un intero positivo.\n");
	}

	for(int i = 0; i < (int)ceil((float)x/2.0) ; i++) // x/2 poi faccio il ceil (ovvero lo porto all'intero immediatamente >=)
	{
		for (int a = 0; a < (x-(i*2)); a++) //ripetizioni
		{
			printf("*");
		}
		printf("\n");
	}
}