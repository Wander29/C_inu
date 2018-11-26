#include <stdio.h>

int main(){
	int x = 0, sum = 1; 

	scanf("%d", &x);
	while (x < 0)
	{
		printf("Incorretto. Inserisci un intero positivo.\n");
		while (getchar() != '\n');
		scanf("%d", &x);
	} 

	if (x == 0)
		printf("%d", 1);

	for(int i=0; i < x; i++)
	{
		sum *= (x-i);
	}
	printf("%d", sum);
}