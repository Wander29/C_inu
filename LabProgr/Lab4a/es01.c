#include <stdio.h>

#define MAX 10

int main(){
	int x[MAX];

	for (int i = 0; i < MAX; i++)
	{
		while ( scanf("%d", &x[i]) < 1) 
		{
		 	while (getchar() != '\n');
		}
	}

	for (int i = MAX - 1; i >= 0; i--)
	{
		printf("%d\n", (x[i]%2 == 0)?(x[i] / 2) : (x[i]) );
	}
	

	return 0;
}