#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <string.h>

int main ()
{
	char str[] = "CIAO MONDO CANE";
	for (char* p = strtok(str, " "); p!=NULL; p = strtok(NULL, " ") )
	{
		printf("TOKEN %-20s\n", p);
	}
	/*
	clock_t clock1, clock2;
	
	//srand(time(NULL));
	//int x = rand() % 18;
	clock1 = clock();
	//printf("%.*s\n%06d",x, "ALL'INIZIO DEL MONDO", x);
	
	for (int a = 0; a < 10000; a++)
		;
	clock2 = clock();
	printf("clock %d\tCLOCK %d", sizeof(clock_t), sizeof(CLOCKS_PER_SEC));
	printf("Tempo: %f\n", (clock2-clock1)/(double)CLOCKS_PER_SEC);


	*/
	return 0;
}