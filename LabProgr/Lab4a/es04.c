#include <stdio.h>

#define MAX 10

typedef enum {OK, ERROR} state;

int main(){
	int x[MAX];
	state stato = ERROR;

	for (int i = 0; i < MAX; i++)
	{
		while ( scanf("%d", &x[i]) < 1) 
		{
		 	while (getchar() != '\n');
		}
	}

	for (int i = 0; (i < MAX); i++)
	{
		if (x[i] >= 0)
		{
			if (x[i]%2 == 0)
			{
				printf("%d\n", x[i]);
				stato = OK;
			}
		} else {
			if ( (i != MAX-1) && (x[i+1] >= 0) )
			{
				printf("%d\n", x[i]);
				stato = OK;
			}
		}
	}
	if (stato == ERROR)
		printf("\n");
	return 0;
}