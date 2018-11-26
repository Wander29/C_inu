#include <stdio.h>

#define MAX 10

enum state {CONTINUE, MATCHED};

int main(){
	char seq[MAX];
	char x;
	int cnt = 0;

	enum state stato = CONTINUE;

	printf ("***Inserisci una sequenza in [a-z/@/#/$/&/*/</>/~/€] (per terminare deve essere della forma \'xywxxabxxx\'***\n(inserire un carattere alla volta e premere INVIO)\n\n");

	do {
		//inizialmente riempo la sequenza con MAX caratteri, il minimo per fare il confronto
		printf("%d: ", cnt+1);
		//leggo un carattere (se ne vengono inseriti di più considero solo il primo)
		while ( scanf("%1[a-z/@/#/$/&/*/</>/~/€]", &seq[cnt]) != 1 ) 
		{
		 	printf("CARATTERE NON ALFABETICO (solo minuscolo!)\n%d: ", cnt+1);
		 	while (getchar() != '\n');
		}
		while (getchar() != '\n'); //svuoto il buffer di input

		cnt++;//uso cnt per tenere traccia delle ripetizioni

	} while(cnt<MAX);

	printf("SEQUENZA corrente: "); 
	for (int i = 0; i < MAX; i++)
	{
		printf("%c", seq[i]);
	}
	printf("\n\t\t%2c | %1c | %1c | %1c | %1c\n", 'x', 'y', 'w', 'a', 'b');
	printf("\t\t%2c  %2c  %2c  %2c  %2c\n", seq[0], seq[1], seq[2], seq[5], seq[6]);

	//Ciclo endless Loop
	while ( stato == CONTINUE )
	{
		//CONFRONTO
		x = seq[0];
		if( x == seq[3] )
		{
			if (x == seq[4]) 
			{
				if (x == seq[7])
				{
					if (x == seq[8])
					{
						if (x == seq[9])
						{
							if ( (seq[5] != seq[1]) && (seq[5] != seq[2]) )
							{
								if ( (seq[6] != seq[1]) && (seq[6] != seq[2]) )
								{
									for (int a = 0; a < 60; a++)
									{
										printf("=");
									}
									printf("\nSEQUENZA: ");
									for (int i = 0; i < cnt; i++)
									{
										printf("%c", seq[i]);
									}
									printf("\n");
									stato = MATCHED;
								}
							}
						}
					}
				}
			}
		} //fine confronto

		if (stato == CONTINUE)
		{	
			//SCAMBIO DI POSTO nell'array
			for (int posto = 0; posto < (MAX - 1); posto++)
			{
				seq[posto] = seq[posto + 1];
			}

			printf("new: ");
			while ( scanf("%1[a-z/@/#/$/&/*/</>/~/€]", &seq[MAX - 1]) != 1 )
			{
			 	printf("CARATTERE NON ALFABETICO (solo minuscolo!)\n%d: ", MAX);
			 	while (getchar() != '\n');
			}
			while (getchar() != '\n'); 

			printf("SEQUENZA corrente: "); 
			for (int i = 0; i < MAX; i++)
			{
				printf("%c", seq[i]);
			}
			printf("\n\t\t%2c | %1c | %1c | %1c | %1c\n", 'x', 'y', 'w', 'a', 'b');
			printf("\t\t%2c  %2c  %2c  %2c  %2c\n", seq[0], seq[1], seq[2], seq[5], seq[6]);
		}
	} //fine while endless loop

	return 0;
}