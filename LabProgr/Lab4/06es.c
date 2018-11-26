#include <stdio.h>

typedef enum{	
				OK,
				ERROR
			}state;

int ask_input();

int main(){
	int x;
	x = ask_input();

	for (int j = 1; j <= 10; j++)
	{
		printf("%d\n", x*j);
	}
	return 0;
}

int ask_input()
{
	int var = 0;
	
	while ( scanf("%d", &var) < 1  || (var < 1) ) 
	{
	 	printf("Incorretto.  Inserisci un intero positivo.\n");
	 	while (getchar() != '\n');
	}

	return var;
}




