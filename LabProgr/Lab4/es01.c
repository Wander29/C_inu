#include <stdio.h>

int main(){
	int rip = 0, temp = 0, somma = 0;

	scanf("%d", &rip);
	while (rip < 1)
	{
		printf("Incorretto. Inserisci un intero positivo.\n");
		while (getchar() != '\n');
		scanf("%d", &rip);
	} 

	for (int i = 0; i < rip; i++)
	{
		while (getchar() != '\n');
		while( scanf("%d", &temp) != 1)
		{
			printf("Incorretto. Inserisci un intero.\n");
			while (getchar() != '\n');
		}
		somma += temp;
	}

	printf("%.2f", (float) somma/rip);
}